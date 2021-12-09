
#include "ft_containers.hpp"

int main()
{
	// vector_tests();
	// map_tests();
	// stack_tests();
	LIB::vector<int>	Lucas(5, 0);

	LIB::vector<int>::const_iterator	it;
	it = Lucas.begin();
	std::cout << *it << std::endl;
}
