#ifndef COSINE_CURVE_GENERATE
#define COSINE_CURVE_GENERATE

#include "rclcpp/rclcpp.hpp"

class CosineCurve
{
private:
    int sign = 1;
    double pos_start = 0.0;
    double pos_end = 0.0;
    double pos_dis = 0.0;
    double A = 0.0;
    double w = 0.0;
    double T[3] = {0.0, 0.0, 0.0};
    double V0;
    double delt_t = 0.005;
    void cosineCurveGeneration(void);
    void cosineCurveGenerationWithoutDeceleclertion(void);

public:
    CosineCurve(double pos_start, double pos_end, double vel_max, double acc_max, double v0, bool if_stop);
};

#endif