#include <iostream>
#include <vector>
#include <algorithm>

std::size_t callatz(unsigned long long int n, std::vector <std::size_t> vector)
{	
	std::size_t size = 1;

	while (true)
	{
		if (n % 2 == 1)
		{
			n = 3*n + 1;
		}else
		{
			n = n/2;
		}
		
		if (n == 1)
		{
			break;		
		}
		
		if (n < 100 && vector[n] != 0)
		{		
			size += vector[n];
		        break;	
		}

		size++;
	}

	return size;

}


int main()
{
	std::vector <std::size_t> vector (100, 0);

	for (unsigned long long int n = 1;  n < 100; n++)
	{
		vector[n] = callatz(n, vector);
	}
	
	std::cout << "Max Value: " << *std::max_element(vector.begin(), vector.end()) << std::endl;
	
}
