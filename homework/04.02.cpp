#include <iostream>

// template <typename T, typename ... Ts> auto custom_min <double> (T x,  Ts ... ys)
// {
//     static double min = x
// }

auto my_min(auto x)
{
    return x;
}

auto my_min(auto x, auto ... xs) -> int
{

    return (x < ... < xs) ? x : my_min(xs...);
}


int main()
{
    std::cout << my_min(3, 2, 1) << std::endl;
}