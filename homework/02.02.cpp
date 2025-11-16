#include <iostream>
#include <cmath>
#include <type_traits>
#define EPS 1e-6

void read_coeffs(double& a, double& b, double& c)
{
	size_t got_coeffs = 0;
	double arr[3];
	double tmp;

	std::string str_coefs = "abc";

	while (got_coeffs != 3)
	{
		std::cout << "Write \""<< str_coefs[got_coeffs] << "\" coefficient" << std::endl;
		if (!(std::cin >> tmp))
		{
			std::cout << "Wrong number, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');

			continue;
		}

		arr[got_coeffs] = tmp;

		got_coeffs++;
	}

	a = arr[0];
	b = arr[1];
	c = arr[2];

}


int main()
{	
	double a, b, c, D, x1, x2;

	std::cout<<"Put the coeffs a, b, c of quadratic equation" << std::endl;

	read_coeffs(a, b, c);

	std::cout << "Input equation: \n"<< a << "x^2 + " << b << "x +  " <<  c << std::endl;

	D = b*b - 4*a*c;	
	
	if (std::abs(a) < EPS)
	{
		std::cout << "Equation has 1 root" << std::endl;

		std::cout << "x = " << -c/b << std::endl;		
	
	}else
	{
		if (D < 0)
		{
			std::cout << "Equation has no roots" << std::endl;

		}else if (std::abs(D) < EPS)
		{
			std::cout << "Equation has 1 root" << std::endl;

			std::cout << "x = " << -b/2/a << std::endl;
		}else
		{
			std::cout << "Equation has 2 roots" << std::endl;
			
			x1 = (-b - std::sqrt(D))/2/a;
			x2 = (-b + std::sqrt(D))/2/a;

			std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2 << std::endl;
		
		}
	}

	


}
