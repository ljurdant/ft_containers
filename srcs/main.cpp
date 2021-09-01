
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
        vector[i] = i;

    std::cout << "operator[]" << std::endl;
    std::cout << "vector[" << index << "] = " << vector[index] << std::endl << std::endl;
    std::cout << "front" << std::endl;
    std::cout << "vector.front() = " << vector.front() << std::endl << std::endl;
    std::cout << "back" << std::endl;
    std::cout << "vector.back() = " << vector.back() << std::endl << std::endl;
    std::cout << "begin" << std::endl;
    it = vector.begin();
    std::cout << "vector.begin() = " << *vector.begin() << std::endl << std::endl;
}