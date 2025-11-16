#include <iostream>
#include <cmath>

int main()
{
	std::size_t size = 0, volume = 1;

	double tmp;
	double* array = new double[volume];


	while(std::cin >> tmp)
	{
		if (size > volume)
		{
			volume = 2*volume;
			double* new_array = new double[volume];
			
			for (auto i = 0uz; i < size; i++)
			{
				new_array[i] = array[i];
			}

			array = new_array;
		}
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
