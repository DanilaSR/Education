#include <iostream>
#include <cmath>

int main()
{
	double const eps = 1e-6;
	double m = 1;
	double e = m;
	for (auto i = 1; m > eps; i++ )
	{
		e += m;
		m /= i;
	}

	std::cout << e << std::endl;

}

