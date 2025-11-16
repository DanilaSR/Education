#include <iostream>


template < int S > struct fibonacci
{
    constexpr static auto value = fibonacci<S - 1>::value + fibonacci <S - 2>::value;
};

template <> struct fibonacci < 0 >
{
    constexpr static auto value = 0;
};

template <> struct fibonacci < 1 >
{
    constexpr static auto value = 1;
};


template < int S > constexpr auto fibonacci_v = fibonacci< S >::value;

int main()
{
    static_assert(fibonacci_v<7> == 13);
}