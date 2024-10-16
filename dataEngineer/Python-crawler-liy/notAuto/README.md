# 项目阐述
- 项目显示通过jupyter ntebook写的，然后转成python的
- 在转换后优化了主线程和进度条之间的可能存在的阻塞问题，使得程序运行更加流畅

## 文件描述
- DownloadeImage.ipynb是下载图片的代码
- SaveTextInfo.ipynb是保存文本信息的代码
- getUrls.ipynb是通过api获取商品名称、价格、商品链接和相关图片链接的代码

# 运行顺序
1. 运行getUrls.ipynb，获取商品名称、价格、商品链接和相关图片链接
2. 运行SaveTextInfo.ipynb和DownloadeImage.ipynb就无所谓了