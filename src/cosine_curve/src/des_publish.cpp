#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "cosine_curve/cosine_curve_generate.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  // CosineCurve myPos(-0.5,-2.750,1,0.8);//x
  CosineCurve myPos(0.339, 3, 1, 2, 1,false); // y
  // rclcpp::spin();
  rclcpp::shutdown();
  return 0;
}
