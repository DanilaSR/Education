#include <iostream>
#include <cmath>

long int bine(int n)
{
	double const sqrt5 = std::sqrt(5);

	double const s1 = (1 + sqrt5)/2;
	double const s2 = (1 - sqrt5)/2;

	return (std::pow(s1, n) - std::pow(s2, n))/sqrt5;
	
}


int main()
{
	int n = 0;

	std::cout << "Write a number" << std::endl;
	std::cin >> n;

	std::cout << static_cast <int> (bine(n)) << std::endl;


	return 1;
}
