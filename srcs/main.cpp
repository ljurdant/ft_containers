
#include "ft_containers.hpp"
#include <vector>

#define LIB ft

int main()
{
    size_t  size = 4;
    size_t  index = 2;
    size_t  value = 7;

    LIB::vector<int> vector(size, value);
    LIB::vector<int>::iterator it;
    

    for (size_t i = 0; i < size; i++)
        vector[i] = i + i *4;

    std::cout << "operator[]" << std::endl;
    std::cout << "vector[" << index << "] = " << vector[index] << std::endl << std::endl;
    std::cout << "front" << std::endl;
    std::cout << "vector.front() = " << vector.front() << std::endl;
    std::cout << "back" << std::endl;
    std::cout << "vector.back() = " << vector.back() << std::endl << std::endl;
    
    std::cout << "iterators" << std::endl;
   
    it = vector.begin();
    std::cout << "vector.begin() = " << *it << std::endl;
    it++;
    std::cout << "it++ = " << *it << std::endl;
    LIB::vector<int>::iterator it2(it);
    std::cout << "copy constructor -> *it2(it)  = " << *it2 << std::endl;
    LIB::vector<int>::iterator  it3;
    it3 = it2;
    std::cout << "it3 = it2 = " << *it3 << std::endl;
    std::cout << "it3 == it2" << (it3 == it2) << std::endl;
    std::cout << "it3 != it2" << (it3 != it2) << std::endl;

}