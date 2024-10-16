cmake_minimum_required(VERSION 3.10)

# 项目名称
project(SmartCarManagementSystem)

# 设置 Debug 模式以启用调试符号
set(CMAKE_BUILD_TYPE Debug)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用 PTHREAD 支持
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# 指定头文件目录
include_directories(include)

# 查找所有源文件
file(GLOB SOURCES "src/*.cpp")

# 添加可执行文件
add_executable(main main.cpp ${SOURCES})

# 添加 include 目录
target_include_directories(main PRIVATE include)

# 链接线程库
target_link_libraries(main PRIVATE Threads::Threads)

# 可以根据需要添加更多的编译选项
# target_compile_options(SmartCarManagementSystem PRIVATE -Wall -Wextra)
