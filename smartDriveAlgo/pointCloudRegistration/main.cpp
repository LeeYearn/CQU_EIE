#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/registration/icp.h>
#include <Eigen/Dense>

#include "optimized_ICP_GN.h"

using namespace std;

int main()
{
    // 初始化点云，用于存储target目标点云和source源点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_target_ptr(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_source_ptr(new pcl::PointCloud<pcl::PointXYZ>);
    // 初始化点云，用于存储优化ICP和svd配准后的点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_source_opti_transformed_ptr(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_source_svd_transformed_ptr(new pcl::PointCloud<pcl::PointXYZ>);

    // 读取点云文件
    pcl::io::loadPCDFile("../data/room_scan2.pcd", *cloud_target_ptr);
    pcl::io::loadPCDFile("../data/room_scan1.pcd", *cloud_source_ptr);

    // Eigne是一个矩阵库，用于矩阵运算，matrix表示初始化一个4*4的矩阵，predict表示预测的变换矩阵，final表示最终的变换矩阵
    Eigen::Matrix4f T_predict, T_final;
    // 将矩阵初始化为单位矩阵
    T_predict.setIdentity();
    // 这些数据表示预测的变换矩阵
    T_predict << 0.765, 0.643, -0.027, -1.472,
        -0.6, 0.765, -0.023, 1.3,
        0.006, 0.035, 0.999, -0.1,
        0, 0, 0, 1;

    std::cout << "Wait, matching..." << std::endl;

    // =======================   optimized icp   =======================
    // 设置icp初始变换矩阵
    OptimizedICPGN icp_optimized;

    // 设置目标点云
    icp_optimized.SetTargetCloud(cloud_target_ptr);

    // 最大迭代次数和对应点距离
    icp_optimized.SetMaxIterations(30);
    icp_optimized.SetMaxCorrespondDistance(0.3);
    // 误差阈值，当误差小于该值时，认为ICP已经收敛
    icp_optimized.SetTransformationEpsilon(1e-4);

    // 优化ICP配准
    Eigen::Matrix4f T_opti;
    icp_optimized.Match(cloud_source_ptr, T_predict, cloud_source_opti_transformed_ptr, T_opti);

    // 输出结果
    std::cout << "============== Optimized ICP =================" << std::endl;
    std::cout << "最终变换矩阵 T: \n"
              << T_opti << std::endl;
    std::cout << "匹配得分: " << icp_optimized.GetFitnessScore() << std::endl;

    if (icp_optimized.HasConverged())
    {
        std::cout << "优化ICP已收敛。" << std::endl;
    }
    else
    {
        std::cout << "优化ICP未收敛。" << std::endl;
    }

    // =======================   optimized icp   =======================

    // =======================   svd icp   =======================
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp_svd; // 创建SVD ICP对象

    // 设置目标点云和源点云
    icp_svd.setInputTarget(cloud_target_ptr);
    icp_svd.setInputSource(cloud_source_ptr);

    // 设置最大对应点距离
    icp_svd.setMaxCorrespondenceDistance(0.3);

    // 最大迭代次数
    icp_svd.setMaximumIterations(30);

    // 设置欧氏误差阈值和变换收敛阈值
    icp_svd.setEuclideanFitnessEpsilon(1e-4);
    icp_svd.setTransformationEpsilon(1e-4);

    // 开始SVD ICP配准
    icp_svd.align(*cloud_source_svd_transformed_ptr, T_predict);

    std::cout << "\n============== SVD ICP =================" << std::endl;
    std::cout << "T final: \n"
              << icp_svd.getFinalTransformation() << std::endl;
    std::cout << "fitness score: " << icp_svd.getFitnessScore() << std::endl;

    // =======================   svd icp   =======================

    // 可视化
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("viewer"));
    viewer->initCameraParameters(); // 初始化相机参数

    int v1(0); // 视口1
    int v2(1); // 视口2

    viewer->createViewPort(0.0, 0.0, 0.5, 1.0, v1);
    viewer->setBackgroundColor(0, 0, 0, v1); // 背景色和文本说明
    viewer->addText("Optimized ICP", 10, 10, "optimized icp", v1);

    // 为优化后的点云设置颜色并添加到视口1
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_opti_color(cloud_source_opti_transformed_ptr, 255, 0, 0);
    viewer->addPointCloud<pcl::PointXYZ>(cloud_source_opti_transformed_ptr, source_opti_color, "source opti cloud", v1);

    // 为目标点云设置颜色并添加到视口1
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> target_color_0(cloud_target_ptr, 0, 0, 255);
    viewer->addPointCloud<pcl::PointXYZ>(cloud_target_ptr, target_color_0, "target cloud1", v1);

    // 设置视口2并添加SVD ICP结果
    viewer->createViewPort(0.5, 0.0, 1.0, 1.0, v2);
    viewer->setBackgroundColor(0.0, 0.0, 0.0, v2);
    viewer->addText("SVD ICP", 10, 10, "svd icp", v2);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> target_color_1(cloud_target_ptr, 0, 0, 255);
    viewer->addPointCloud<pcl::PointXYZ>(cloud_target_ptr, target_color_1, "target cloud2", v2);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_svd_color(cloud_source_svd_transformed_ptr, 0, 255, 0);
    viewer->addPointCloud<pcl::PointXYZ>(cloud_source_svd_transformed_ptr, source_svd_color, "source svd cloud", v2);

    // 设置点云的渲染属性
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "source opti cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "source svd cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "target cloud1");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "target cloud2");
    viewer->addCoordinateSystem(1.0);

    // 设置相机位置
    viewer->setCameraPosition(0, 0, 20, 0, 10, 10, v1);
    viewer->setCameraPosition(0, 0, 20, 0, 10, 10, v2);

    // 启动可视化
    viewer->spin();

    return 0;
}