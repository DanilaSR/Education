#include <iostream>
#include <vector>


struct Rectangle
{
	double lup = 0, rdown = 0;
};

int main()
{
	std::size_t size = 10;

	std::vector <struct Rectangle> vector[size];

	for (auto i = 1uz, j = 1uz; i < size; i++, j++)
	{
		(vector.at(i)).lup = 0;
	}



}

