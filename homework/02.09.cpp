#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <cassert>


auto gcd (int a, int b) -> int
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);

}

auto lcm (int a, int b)
{

	return a/gcd(a, b)*b;
}


int main()
{
	
	assert(gcd(15, 25)==std::gcd(15, 25));
	assert(lcm(15, 25)==std::lcm(15, 25));

}
