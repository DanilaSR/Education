////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <print>
#include <utility>
#include <cassert>

////////////////////////////////////////////////////////////////////////////////////

class Vector
{
public :

	Vector() : m_array(nullptr), m_size(0)
	{
		std::print("Vector:: Vector (1)\n");
	}

//  --------------------------------------------------------------------------------

	auto capacity()
	{
		return m_capacity;
	}

//  --------------------------------------------------------------------------------

	auto size()
	{
		return m_size;
	}

//  --------------------------------------------------------------------------------

	void increase_capacity()
	{
		m_capacity *= 2;
		int * new_array = new int[m_capacity]{};

		std::ranges::copy(new_array, new_array + m_size, m_array);

		m_array = std::exchange(new_array, nullptr);
	}

//  --------------------------------------------------------------------------------

	void push_back(const int value)
	{
		if (m_capacity <= m_size)
		{
			increase_capacity();
		}

		m_array[m_size] = value;
		m_size += 1;
	
	}

//  --------------------------------------------------------------------------------

	void clear()
	{
		m_capacity = 0;
		m_capacity = 0;
		m_array = nullptr;
	}


//  --------------------------------------------------------------------------------

	bool is_empty()
	{
		bool flag = false;

		if (m_array == nullptr)
		{
			flag = true;
		}

		return flag;
	}

//  --------------------------------------------------------------------------------

	Vector(std::initializer_list < int > list) : m_size(std::size(list)), m_capacity(m_size)
	{
		std::print("Vector:: Vector (2)\n");

		m_array = m_size ? new int[m_size]{} : nullptr;

		std::ranges::copy(list, m_array);
	}

//  --------------------------------------------------------------------------------

	Vector(Vector const & other) : m_size(other.m_size), m_capacity(m_size)
	{
		std::print("Vector:: Vector (3)\n");

		m_array = m_size ? new int[m_size]{} : nullptr;

		std::ranges::copy(other.m_array, other.m_array + other.m_size, m_array);
	}

//  --------------------------------------------------------------------------------

	Vector(Vector && other)
	:
		m_array(std::exchange(other.m_array, nullptr)),

		m_size (std::exchange(other.m_size,  0      )),

		m_capacity(m_size)
	{
		std::print("Vector:: Vector (4)\n");
	}

//  --------------------------------------------------------------------------------

   ~Vector()
	{
		std::print("Vector::~Vector\n");

		delete[] m_array;
	}
	
//  --------------------------------------------------------------------------------

//	auto & operator=(Vector const & other) // error
//	{
//		std::print("Vector::operator= (1)\n");
//
//		if (this != &other)
//		{
//			delete[] m_array;
//
//			m_array = (m_size = other.m_size) ? new int[m_size]{} : nullptr;
//
//			std::ranges::copy(other.m_array, other.m_array + other.m_size, m_array);
//		}
//
//		return *this;
//	}

//  --------------------------------------------------------------------------------

//	auto & operator=(Vector const & other) // bad
//	{
//		std::print("Vector::operator= (2)\n");
//
//		if (this != &other)
//		{
//			auto array = other.m_size ? new int[other.m_size]{} : nullptr;
//
//			std::ranges::copy(other.m_array, other.m_array + other.m_size, array);
//
//			delete[] std::exchange(m_array, array);
//
//			m_size = other.m_size;
//		}
//
//		return *this;
//	}

//  --------------------------------------------------------------------------------

//	auto & operator=(Vector && other) // bad
//	{
//		std::print("Vector::operator= (3)\n");
//
//		if (this != &other)
//		{
//			delete[] m_array;
//
//			m_array = std::exchange(other.m_array, nullptr);
//
//			m_size  = std::exchange(other.m_size,  0      );
//		}
//
//		return *this;
//	}

//  --------------------------------------------------------------------------------

	auto & operator=(Vector other)
	{
		std::print("Vector::operator= (4)\n");

		swap(other);

		return *this;
	}

//  --------------------------------------------------------------------------------

	void swap(Vector & other)
	{
		std::swap(m_array, other.m_array);

		std::swap(m_size,  other.m_size );
	}

private :

	int * m_array = nullptr;

	std::size_t m_size = 0;

	std::size_t m_capacity = 0;
};

////////////////////////////////////////////////////////////////////////////////////

void swap(Vector & lhs, Vector & rhs)
{
	lhs.swap(rhs);
}

////////////////////////////////////////////////////////////////////////////////////

int main()
{
	Vector vector_1;

	Vector vector_2 = { 1, 2, 3, 4, 5 };

	Vector vector_3 = vector_2;

	Vector vector_4 = std::move(vector_3);

//  --------------------------------------

	vector_3 = vector_2;

	vector_4 = std::move(vector_3);

//  --------------------------------------

	//swap(vector_1, vector_2);

//  --------------------------------------

	assert(vector_2.capacity() == 5);

	assert(vector_2.size() == 5);

	vector_2.push_back(6);

	assert(vector_2.capacity() == 10);

	assert(vector_2.size() == 6);

//  --------------------------------------

	vector_2.clear();

	assert(vector_2.is_empty());

}

////////////////////////////////////////////////////////////////////////////////////