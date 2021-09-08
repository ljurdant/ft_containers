
#include "ft_containers.hpp"
#include <vector>

#define LIB ft

int main()
{
    try

    
    {
    size_t  size = 10;
    size_t  index = 2;
    size_t  value = 7;

    LIB::vector<int>            vector(size, value);
    LIB::vector<int>::iterator  it;
    LIB::vector<int>            vector_empty;
    
    for (size_t i = 0; i < size - 1; i++)
        vector[i] = i + i * 4;

    std::cout << "operator[]" << std::endl;
    std::cout << "vector[" << index << "] = " << vector[index] << std::endl << std::endl;
    std::cout << "front" << std::endl;
    std::cout << "vector.front() = " << vector.front() << std::endl;
    std::cout << "back" << std::endl;
    std::cout << "vector.back() = " << vector.back() << std::endl << std::endl;
    
    std::cout << "iterators" << std::endl;
   
    it = vector.begin();
    std::cout << "vector.begin() = " << *it << std::endl;

    LIB::vector<int>::iterator it2(it);
    std::cout << "copy constructor -> *it2(it)  = " << *it2 << std::endl;
    LIB::vector<int>::iterator  it3;
    it3 = it2;
    std::cout << "it3 = it2 = " << *it3 << std::endl;
    std::cout << "it3 == it2 = " << (it3 == it2) << std::endl;
    std::cout << "it3 != it2 = " << (it3 != it2) << std::endl;
    it2 = (it++);
    std::cout << "it2 = " << *(it2) << std::endl;
    std::cout << "++it = " << *(++it) << std::endl;
	std::cout << "*it++ = " << *it++ << std::endl;
	std::cout << "it-- = " << *(it--) << std::endl;
    std::cout << "--it = " << *(--it) << std::endl;
	std::cout << "*it-- = " << *it-- << std::endl;
	size_t n = 3;
	std::cout << "it + " << n << " = " << *(it + n) << std::endl;
	std::cout << n << " + it = " << *(n + it) << std::endl;
    std::cout << "it - " << n << " = " << *(it - n) << std::endl;
    std::cout << "it - it2 = " << (it - it2) << std::endl;
    std::cout << "it < it3 = " << (it < ++it3) << std::endl;
    std::cout << "it > it3 = " << (it > it3) << std::endl;
    std::cout << "it <= it3 = " << (it <= it3) << std::endl;
    std::cout << "it >= it3 = " << (it >= it3) << std::endl;
    std::cout << "it += 4 = " << *(it+=4) << std::endl;
    std::cout << "it -= 3 = " << *(it-=3) << std::endl;
    std::cout << "it[1] = " << it[1] << std::endl;


    LIB::vector<int>::reverse_iterator  rit = vector.rbegin();
    std::cout << "vector.rbegin() = " << *rit << std::endl;
    std::cout << "++rit = " << *(++rit) << std::endl;
    std::cout << "Capacity" << std::endl;
    std::cout << "vector.size() = " << vector.size() << std::endl;
    std::cout << "vector.size_max() = " << vector.max_size() << std::endl;
	std::cout << "vector.resize(" << vector.size() + 3 << ")" << std::endl;
    vector.resize(size + 3, 60);
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << "vector[" << i << "] = " << vector[i] << ", ";
	std::cout << std::endl << std::endl;
    std::cout << "vector.resize(" << vector.size() - 6 << ")" << std::endl;
    vector.resize(size - 3, 60);
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << "vector[" << i << "] = " << vector[i] << ", ";
    std::cout << std::endl;
    std::cout << "vector.capacity = " << vector.capacity() << std:: endl;
    std::cout << "vector.empty() = " << vector.empty() << std::endl;
    vector.reserve(vector.size() * 4);
    std::cout << "vector.reserve(" << vector.size() * 4 << ") -> vector.capacity() = " << vector.capacity() << std::endl;
    for (size_t i = 0; i < vector.size(); i++)
		std::cout << "vector[" << i << "] = " << vector[i] << ", ";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}