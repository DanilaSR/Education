////////////////////////////////////////////////////////////////////////////////////

// support : www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <numeric>
#include <utility>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void order(std::vector < T > & vector, std::size_t left, std::size_t right)
{
	for (auto i = left + 1; i < right; ++i) 
	{
		for (auto j = i; j > left; --j)
		{
			if (vector[j - 1] > vector[j]) 
			{
				std::swap(vector[j], vector[j - 1]);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
auto qsort(std::vector < T > & vector, std::size_t left, std::size_t right)
{
	
	auto pivot = vector[right];

	auto i = left;

	for (auto j = left; j < right; ++j) 
	{
		if (vector[j] <= pivot)
		{
			std::swap(vector[i], vector[j]);
			i++;
		}	
	}

	std::swap(vector[i], vector[right]);

	return i;
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void split(std::vector < T > & vector, std::size_t left, std::size_t right)
{
	if (right - left > 16)
	{
		auto partition  = qsort(vector, left, right);

		split(vector, left, partition - 1);
		
		split(vector, partition + 1, right );
	}
	else
	{
		order(vector, left,   right );
	}
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void sort(std::vector < T > & vector)
{
	split(vector, 0, std::size(vector));
}

////////////////////////////////////////////////////////////////////////////////////


int main()
{
	std::size_t  size = 1000;

//  ---------------------------------------

	std::vector <int> vector(size, 0);

//  ---------------------------------------

	for (auto i = 0uz; i < size; ++i)
	{
		vector[i] = size - i;
	}

//  ---------------------------------------

	sort<int>(vector);

//  ---------------------------------------

	assert(std::ranges::is_sorted(vector));
}

////////////////////////////////////////////////////////////////////////////////////
