#include <iostream>

template <typename T, typename ... Ts> auto custom_min <double> (T x,  Ts ... ys)
{
    static double min = x
}