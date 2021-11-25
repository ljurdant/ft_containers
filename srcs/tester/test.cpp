#include <iostream>
#include <string>
#include <iterator>
#include <typeinfo>

#if VERSION
	# include "../vector.hpp"
#else
	#include <vector>
	namespace ft =std;
#endif

void print_itests(ft::vector<int> &vec)
{
	ft::vector<int> other(20000, 100);

	std::cout << typeid(vec.get_allocator()).name() << std::endl;

	std::cout << "\ntest" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.assign(1000, 3);

	std::cout << "\nafter count assign" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.assign(other.begin(), other.end());

	std::cout << "\nafter iterator assign" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	std::cout << vec.at(5) << std::endl;
	try
	{
		std::cout << vec.at(20001) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error" << std::endl;
	}
	try
	{
		std::cout << vec.at(-1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error" << std::endl;
	}
	std::cout << vec[10] << std::endl;
	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;
	// std::cout << *vec.data() << std::endl;

	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	for (ft::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << std::endl;

	vec.reserve(vec.size() - 100);
	std::cout << "\nafter reserve" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.reserve(vec.size() + 100);
	std::cout << "\nafter reserve" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.insert(vec.begin(), 82);
	std::cout << "\nafter insert 1" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 20, 40, 2);
	std::cout << "\nafter insert 2" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.insert(vec.begin() + 50, other.begin(), other.begin() + 30);
	std::cout << "\nafter insert 3" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.erase(vec.begin() + 10);
	std::cout << "\nafter erase 1" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

void print_stests(ft::vector<std::string> &vec)
{
	std::cout << "\ntest" << std::endl;
	std::cout << vec.empty() << std::endl;
	std::cout << vec.size() << std::endl;
	std::cout << vec.max_size() << std::endl;
	std::cout << vec.capacity() << std::endl;
}


int	main()
{
	std::allocator<int> a; 
	ft::vector<int> itest1;
	ft::vector<int> itest2(a);
	ft::vector<int> itest3(100, 10);
	ft::vector<int> itest5(itest3.begin(), itest3.begin() + 20);
	ft::vector<int> itest6(itest5);
	ft::vector<std::string> stest1;
	ft::vector<std::string> stest2;
	ft::vector<std::string> stest3(100, "abc");
	ft::vector<std::string> stest5(stest3.begin(), stest3.begin() + 20);
	ft::vector<std::string> stest6(stest5);
	
	std::cout << std::boolalpha;

	std::cout << "***** first tests *****" << std::endl;
	itest2 = itest5;

	print_itests(itest1);
	print_itests(itest2);
	print_itests(itest3);
	print_itests(itest5);
	print_itests(itest6);

	std::cout << "***** string tests *****" << std::endl;

	stest2 = stest5;

	print_stests(stest1);
	print_stests(stest2);
	print_stests(stest3);
	print_stests(stest5);
	print_stests(stest6);

	std::cout << "finish" << std::endl;

	return 0;
}