#include <iostream>
#define EPS 1e-6

int main()
{
	double ghost = 1, sum = 0;

	for (size_t i = 1; ghost > EPS; i++)
	{
		sum += ghost;

		ghost /= i;
	}

	std::cout << sum << std::endl;

}
