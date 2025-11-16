#include <iostream>
#include <cassert>
#include <bitset>
#include <print>

class IPv4
{
public:

    IPv4(std::initializer_list < uint8_t > list)
    {
        if (std::size(list) == 4)
        {
            std::ranges::copy(list, m_ip);

        }else
        {
            std::cout << "Incorrect size of IP" << std::endl;
        }
    }

//  --------------------------------------------------

    auto operator== (IPv4 const & other) const
    {
        return m_ip[0] == other.m_ip[0] && m_ip[1] == other.m_ip[1] && m_ip[2] == other.m_ip[2]
         && m_ip[3] == other.m_ip[3];
    }

//  --------------------------------------------------

    void show()
    {
        std::cout << static_cast<int>(m_ip[0]) << "." << static_cast<int>(m_ip[1]) << "."
        << static_cast<int>(m_ip[2]) << "." << static_cast<int>(m_ip[3])<< std::endl;
    }
    
//  -------------------------------------------------------------------------------------------

    auto const operator++(int) { auto x = *this; m_ip[3]++; m_ip[3] ? : (++m_ip[2] ? : (++m_ip[1] ? : m_ip[0]++) ); 
        return x; }

	auto const operator--(int) { auto x = *this; m_ip[3]--; (m_ip[3]%255) ? : ((--m_ip[2]%255) ? : ((--m_ip[1]%255) ? : --m_ip[0]));
         return x; }

//  -------------------------------------------------------------------------------------------

	auto & operator++() {m_ip[3]++; m_ip[3] ? : (++m_ip[2] ? : (++m_ip[1] ? : m_ip[0]++) ); return *this; }

	auto & operator--() {  m_ip[3]--; (m_ip[3]%255) ? : ((--m_ip[2]%255) ? : ((--m_ip[1]%255) ? : --m_ip[0]));
         return *this; }

//  -------------------------------------------------------------------------------------------


private:

    std::uint8_t m_ip[4]{};
};


int main()
{

    IPv4 ip_full = {255, 255, 255, 255};
    IPv4 ip_zero = {0, 0, 0, 0};
    ip_full++;

    assert(ip_full == ip_zero);
    
    --ip_zero;
    --ip_full;

    assert(ip_full == ip_zero);

    return 0;
}