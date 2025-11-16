#include <iostream>
#include <cmath>
#define NMAX 1000

int main()
{
	double array [NMAX], tmp;

	std::size_t size = 0;

	while(std::cin >> tmp)
	{
		array[size] = tmp;
		size++;
	
	}

	double min = array[0];
	double max = array[0];

	double sum = array[0];

	for (auto i = 1uz; i < size; i++)
	{
		min = std::min(min, array[i]);
		max = std::max(max, array[i]);

		sum += array[i];

	}

	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl; 

	sum /= size;

	std::cout << "Mean:  " << sum << std::endl;

	double s = 0;

	for (auto i = 0uz; i < size; i++)
	{
		s += std::pow(sum - array[i], 2);
		
	}

	std::cout << "Deviation: " << std::sqrt(s)/size << std::endl;



}
