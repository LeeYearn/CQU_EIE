import requests
import json
# API URL offset参数是网页起始位置，limit参数是每次请求的数量（最多200）
url1 = "https://www.asos.com/api/product/search/v2/categories/27110?offset="
url2 = "&includeNonPurchasableTypes=restocking&key-search-mvtid=algolia&store=COM&lang=en-GB&currency=GBP&rowlength=3&channel=desktop-web&country=GB&keyStoreDataversion=mhabj1f-41&advertisementsPartnerId=100712&advertisementsVisitorId=346df952-e181-4720-be67-191f98bc41e0&advertisementsOptInConsent=true&limit=200"
# JSON文件路径
jsonDir = "./products_info.json"
data = {}
for i in range(0, 1000, 200):
    url = url1 + str(i) + url2
    # 发送请求
    response = requests.get(url)
    # 检查请求是否成功
    if response.status_code == 200:
        responseData = response.json()
        products = responseData.get("products", [])
        
        # 提取所需的信息
        for product in products:
            id = product.get("id")
            name = product.get("name")
            price = product.get("price", {}).get("current", {}).get("text")
            urlAddr = f"https://www.asos.com/{product.get('url')}"
            image = product.get("additionalImageUrls", [])
            
            # 添加主图地址并拼接
            image_url = product.get("imageUrl")
            image.append(image_url)

            # 拼接其他图片地址
            image = [f"https://{img_url}?$n_640w$&wid=513&fit=constrain" for img_url in image]

            # 将产品信息存储在字典中
            data[id] = {
                "name": name,
                "price": price,
                "url": urlAddr,
                "additionalImageUrls": image
            }
    else:
        print("请求失败，状态码：", response.status_code)
    print(f"已爬取 {i+200} 个信息")
# 保存为JSON文件
with open(jsonDir, "w", encoding='utf-8') as json_file:
    json.dump(data, json_file, ensure_ascii=False, indent=4)
print("数据已保存为JSON文件")