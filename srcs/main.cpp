
#include "ft_containers.hpp"

int main()
{
    size_t  size = 4;
    size_t  index = 2;
    size_t  value = 7;

    ft::Vector<int> ft_vector(size, value);
    
    std::cout << "<<<<<<<<<< operator '[]' >>>>>>>>>>" << std::endl;
    std::cout << "ft_vector[" << index << "] = " << ft_vector[index] << std::endl;
}