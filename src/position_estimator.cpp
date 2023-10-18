

// c++
#include <vector>
#include <mutex>  
#include <math.h>
#include <cmath>

// CV
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
//#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <image_transport/image_transport.h>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/header.hpp"
//#include <rclcpp/rclcpp.hpp>
#include <std_msgs/Float64MultiArray.h>
//#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <geometry_msgs/Point.h>
#include <happymimi_recognition_msgs/PositionEstimator.h>

//??
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>


class 3dPositionEstimator : public rclcpp::Node {
  public:
    3dPositionEstimator() : Node("3d_position_estimator"){
      // depth_topic
      rs_sub = this->create_subscription<sensor_msgs::msg::Image>("/camera/aligned_depth_to_color/image_raw", 1, std::bind(&3dPositionEstimator::rsCB, this, _1))
      m_angle_sub = this->create_subscription<std_msgs::msg::Float64MultipleArray>("/servo/angle_list", 1, std::bind(&motorAngleCB, this, _1))
    }



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<3dPositionEstimator>());
  rclcpp::shutdown();
  return 0;
}


