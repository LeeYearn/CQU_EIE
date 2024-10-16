import os
import requests
import json
import threading
from tqdm import tqdm
from concurrent.futures import ThreadPoolExecutor, as_completed
from queue import Queue
from lxml import html
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36 Edg/129.0.0.0',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6'
}

# 队列，用于将写入任务推入异步写入线程
write_queue = Queue()

def get_info(response):
    # 解析 HTML 内容
    tree = html.fromstring(response.content)
    
    # 使用 XPath 查找所有指定的 div 标签（class="F_yfF"）
    div_contents = tree.xpath('//div[@class="F_yfF"]')
    
    # 检查是否找到了至少两个这样的 div
    if len(div_contents) >= 2:
    # 提取第二个 div 中的纯文本内容
        return div_contents[1].text_content()

# 模拟从网页获取信息的函数
def fetch_and_process_url(url):
    try:
        response = requests.get(url, headers=headers, timeout=10)
        response.raise_for_status()  # 检查 HTTP 响应是否为成功状态
        #提取页面内容
        return get_info(response)
    except Exception  as e:
        return None
# 写入文件的函数，放入队列中由单独线程处理
def write_info(product_id, product_info):
    url = product_info['url']
    name = product_info['name']
    price = product_info['price']
    
    result = fetch_and_process_url(url)
    
    if result:
        # 将要写入的内容推入队列
        write_queue.put((product_id, name, price, result))

# 文件写入线程（单独线程执行写入操作，避免与进度条冲突）
def file_writer_thread():
    while True:
        # 从队列中获取要写入的信息
        product_id, name, price, result = write_queue.get()
        output_dir = f'./info/{product_id}'
        os.makedirs(output_dir, exist_ok=True)
        try:
            with open(os.path.join(output_dir, 'info.txt'), 'w', encoding='utf-8', errors='ignore') as f:
                f.write(f'Name: {name}\n')
                f.write(f'Price: {price}\n')
                f.write(f'Result: {result}\n')
        except UnicodeEncodeError as e:
            # 不处理错误，忽略编码问题
            pass
        write_queue.task_done()

# 主函数，管理任务分发和进度条更新
def main(data):
    # 启动文件写入线程
    writer_thread = threading.Thread(target=file_writer_thread, daemon=True)
    writer_thread.start()

    with ThreadPoolExecutor(max_workers=10) as executor:
        with tqdm(total=len(data), desc="Processing URLs", unit="URL") as pbar:
            futures = [executor.submit(write_info, product_id, product_info) for product_id, product_info in data.items()]

            # 确保在每个任务完成后都能更新进度条，即使是失败的任务也要更新。
            for future in as_completed(futures):
                pbar.update(1)  # 更新进度条
                future.result()  # 确保任务完成


    # 等待队列中的所有任务完成
    write_queue.join()


if __name__ == "__main__":
    jsonDir = "./products_info.json"#设置之前保存的json文件路径
    with open(jsonDir, 'r',encoding='utf-8') as file:
        data = json.load(file)  # 读取 JSON 数据
    main(data)
