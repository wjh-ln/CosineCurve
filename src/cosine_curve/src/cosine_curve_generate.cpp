#include "cosine_curve/cosine_curve_generate.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
ofstream cosine_outfile;

CosineCurve::CosineCurve(double pos_start, double pos_end, double vel_max, double acc_max)
{

    cosine_outfile.open("outfile.txt");

    if (pos_start >= pos_end) // 起点位置大于终点位置
    {
        sign = -1;
    }
    else
    {
        sign = 1;
    }
    this->pos_start = pos_start;

    A = 0.5 * vel_max;
    w = acc_max / A;
    pos_dis = abs(pos_end - pos_start);

    T[0] = M_PI / w;
    T[2] = T[0];
    T[1] = (pos_dis - A * 2 * M_PI / w) / (2 * A);

    if (T[1] <= 0) // 不能达到最大速度
    {
        cout << "cannot reach max velocity!" << endl;
        vel_max = sqrt(pos_dis * acc_max / M_PI_2);

        A = 0.5 * vel_max; // 重新计算正弦曲线参数
        w = acc_max / A;
        T[0] = M_PI / w;
        T[2] = T[0];
        T[1] = 0;
    }
    cout << "A = " << A << setw(10) << "w = " << w << setw(10) << "T0 = " << T[0] << setw(10) << "T1 = " << T[1] << setw(10) << "T2 = " << T[2] << endl;

    cosineCurveGeneration();
}

void CosineCurve::cosineCurveGeneration(void)
{
    double T_sum = T[0] + T[1] + T[2];
    cout << "T_sum = " << T_sum << endl;

    int time_slice_sum = T_sum / delt_t;
    cout << "time_slice_sum = " << time_slice_sum << endl;

    for (int i = 0; i < time_slice_sum; i++)
    {
        double t = delt_t * i;
        double velocity = 0.0;
        double acceleration = 0.0;
        double position = 0.0;

        if (t <= T[0])
        {
            position = this->pos_start + sign * (A / w * sin(w * t + M_PI) + A * t);
            velocity = sign * (A * cos(w * t + M_PI) + A);
            acceleration = sign * (-A * w * sin(w * t + M_PI));
        }
        else if (t > T[0] && t <= T[0] + T[1])
        {
            position = this->pos_start + sign * (2.0 * A * t - A * M_PI / w);
            velocity = sign * 2.0 * A;
            acceleration = 0;
        }
        else if (t > T[0] + T[1] && t <= T[0] + T[1] + T[2])
        {
            if (T[1] > 0) // 能到最大速度时
                position = this->pos_start + sign * (A / w * sin(w * (t - T[0] - T[1])) + A * t + pos_dis / 2 - A * M_PI / w);
            else // 不能达到最大速度时
                position = this->pos_start + sign * (A / w * sin(w * (t - T[0] - T[1])) + A * t);

            velocity = sign * (A * cos(w * (t - T[0] - T[1])) + A);
            acceleration = sign * (-A * w * sin(w * (t - T[0] - T[1])));
        }
        cosine_outfile << position << " " << velocity << " " << acceleration << endl;
    }
}