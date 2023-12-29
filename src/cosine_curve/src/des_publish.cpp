#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "cosine_curve/cosine_curve_generate.hpp"




int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);
  CosineCurve myPos(-2,7,2,1);
  
  // rclcpp::spin();
  rclcpp::shutdown();
  return 0;
}
