import requests
import json
import os
from tqdm import tqdm  # 导入 tqdm 库
from concurrent.futures import ThreadPoolExecutor, as_completed

def download_image(product_id, img_url, index):
    try:
        response = requests.get(img_url, timeout=10)
        response.raise_for_status()  # 如果状态码不是200，抛出异常
        file_name = f"{product_id}_{index + 1}.jpg"
        image_dir = f"./info/{product_id}/image"
        os.makedirs(image_dir, exist_ok=True)
        file_path = os.path.join(image_dir, file_name)
        with open(file_path, "wb") as img_file:
            img_file.write(response.content)
        # return f"下载成功: {file_name}"
    except requests.exceptions.RequestException as e:
        pass
   
def main():
    # 收集所有图片下载任务
    download_tasks = []
    for product_id, product_info in ReadJson.items():
        images = product_info.get("additionalImageUrls", [])
        for idx, img_url in enumerate(images):
            download_tasks.append((product_id, img_url, idx))
    # 使用线程池下载图片并显示进度条
    with ThreadPoolExecutor() as executor:
        with tqdm(total=len(download_tasks), desc="下载进度") as pbar:
            future_to_image = {executor.submit(download_image, *task): task for task in download_tasks}
            
            for future in as_completed(future_to_image):
                pbar.update(1)  # 更新进度条'
                result = future.result()

if __name__ == "__main__":
    # JSON文件路径
    jsonDir = "./products_info.json"
    # 读取JSON文件
    with open(jsonDir, "r", encoding='utf-8') as json_file:
        ReadJson = json.load(json_file)

    main()