
#include "ft_containers.hpp"

struct test {
	test(): value(4){}
	test(int val): value(val){}
	int	value;
};

template <typename T>
void	print_vector(LIB::vector<T> &vector)
{
	for (typename LIB::vector<T>::size_type i = 0; i < vector.size(); i++)
	{
		std::cout << "vector[" << i << "] = " << vector[i] ;
		if (i != vector.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
void	constructor_tests()
{
	std::cout << "Default Constructor: ";
	LIB::vector<T>	vector1;
	std::cout << "vector.size() = " << vector1.size();
	std::cout << "vecotr.capacity() = " << vector1.capacity();

	std::cout << "Constructor: vector(size): ";
	LIB::vector<T>	vector2(6);
	print_vector(vector2);
	LIB::vector<T>	vector3(0);
	print_vector(vector3);
	LIB::vector<T>	vector5(100000);
	print_vector(vector5);

	std::cout << "Constructor: vector(size, value): ";
	LIB::vector<T>	vector6(6, 89);
	print_vector(vector6);
	LIB::vector<T>	vector7(0, -3);
	print_vector(vector7);
	LIB::vector<T>	vector9(100000, 6);
	print_vector(vector9);
	
	std::cout << "Constructor: vector(vector): ";
	LIB::vector<T>	vector10(vector6);
	print_vector(vector10);

}

template<typename T>
void	operator_tests() {
	LIB::vector<T>	vector1(12, 4);
	LIB::vector<T>	vector2;

	std::cout << "Operator=: (empty left side)";
	vector2 = vector1;
	print_vector(vector2);

	LIB::vector<T>	vector3(1001, 90);
	LIB::vector<T>	vector4;
	std::cout << "Operator=: (empty right side)";
	vector3 = vector4;
	print_vector(vector3);

	LIB::vector<T>	vector5(1001, 90);
	LIB::vector<T>	vector6(2, 9);
	std::cout << "Operator=: ";
	vector5 = vector6;
	print_vector(vector5);

	LIB::vector<T>	vector7(1001, 90);
	LIB::vector<T>	vector8(2, 9);
	std::cout << "Operator>=: -> " << (vector7 >= vector8) << std::endl;
	std::cout << "Operaror>: -> " << (vector7 > vector8) << std::endl;
	std::cout << "Operator<: -> " << (vector7 < vector8) << std::endl;
	std::cout << "Operator<=: vector -> " << (vector7 <= vector8) << std::endl;
	std::cout << "Operaator==: (not equal) -> " << (vector7 == vector8) << std::endl;
	std::cout << "Operator!=: (not equal) -> " << (vector7 != vector8) << std::endl;

	LIB::vector<T>	vector9(2005, 254);
	LIB::vector<T>	vector10(2005, 254);
	std::cout << "Operator>=: -> " << (vector9 >= vector10) << std::endl;
	std::cout << "Operaror>: -> " << (vector9 > vector10) << std::endl;
	std::cout << "Operator<: -> " << (vector9 < vector10) << std::endl;
	std::cout << "Operator<=: vector -> " << (vector9 <= vector10) << std::endl;
	std::cout << "Operaator==: (not equal) -> " << (vector9 == vector10) << std::endl;
	std::cout << "Operator!=: (not equal) -> " << (vector9 != vector10) << std::endl;
}

template <class T>
void	iterator_integral() {
	LIB::vector<T>	vector1(12, 5);

	typename LIB::vector<T>::iterator	it1 = vector1.begin();
	typename LIB::vector<T>::iterator	it2 = vector1.begin();
	std::cout << "iterator == iterator (equal) -> " << (it1 == it2) << std::endl;
	std::cout << "iterator != iterator (equal) -> " << (it1 != it2) << std::endl;

	typename LIB::vector<T>::iterator	it3 = vector1.end();
	std::cout << "iterator == iterator (unequal) -> " << (it3 == it2) << std::endl;
	std::cout << "iterator != iterator (unequal) -> " << (it3 != it2) << std::endl;
	std::cout << "*iterator " << *it1 << std::endl;	
	std::cout << "class iterator++ " << *(it1++) << std::endl;
	std::cout << "++iterator "<< *(++it1) << std::endl;
	std::cout << "iterator-- " << *(it1--) << std::endl;
	std::cout << "--iterator "<< *(--it1) << std::endl;
	std::cout << "iterator + 4 " << *(it1 + 4) << std::endl;
}

template <class T>
void	iterator_class() {
	LIB::vector<T>	vector1(12, 5);

	typename LIB::vector<T>::iterator	it1 = vector1.begin();
	typename LIB::vector<T>::iterator	it2 = vector1.begin();
	std::cout << "iterator == iterator (equal) -> " << (it1 == it2) << std::endl;
	std::cout << "iterator != iterator (equal) -> " << (it1 != it2) << std::endl;

	typename LIB::vector<T>::iterator	it3 = vector1.end();
	std::cout << "iterator == iterator (unequal) -> " << (it3 == it2) << std::endl;
	std::cout << "iterator != iterator (unequal) -> " << (it3 != it2) << std::endl;
	std::cout << "iterator-> " << it1->value << std::endl;
	std::cout << "iterator-- " << (it1--)->value << std::endl;
	std::cout << "--iterator "<< (--it1)->value << std::endl;
	std::cout << "iterator + 4 " << (it1 + 4)->value << std::endl;
}

void	vector_tests()
{
	constructor_tests<int>();
	constructor_tests<char>();
	constructor_tests<long long int>();
	iterator_integral<int>();
	iterator_integral<char>();
	iterator_integral<long long int>();
	iterator_class<test>();
	// LIB::vector<int>            vector(10, 4);
	// // LIB::vector<int>::const_reverse_iterator	rit = vector.rbegin();

	

	// try {
	// 	size_t  size = 10;
	// 	size_t  index = 2;
	// 	size_t  value = 7;

	// 	LIB::vector<int>            vector(size, value);
	// 	LIB::vector<int>::iterator  it;
	// 	LIB::vector<int>            vector_empty;
	// 	for (size_t i = 0; i < size - 1; i++)
	// 		vector[i] = i + i * 4;

	// 	std::cout << "operator[]" << std::endl;
	// 	std::cout << "vector[" << index << "] = " << vector[index] << std::endl << std::endl;
	// 	std::cout << "front" << std::endl;
	// 	std::cout << "vector.front() = " << vector.front() << std::endl;
	// 	std::cout << "back" << std::endl;
	// 	std::cout << "vector.back() = " << vector.back() << std::endl << std::endl;
		
	// 	std::cout << "iterators" << std::endl;
	
	// 	it = vector.begin();
	// 	std::cout << "vector.begin() = " << *it << std::endl;
	// 	std::cout << "vector.end() -1= " << *(vector.end()-1) << std::endl;

	// 	LIB::vector<int>::iterator it2(it);
	// 	std::cout << "copy constructor -> *it2(it)  = " << *it2 << std::endl;
	// 	LIB::vector<int>::iterator  it3;
	// 	it3 = it2;
	// 	print_vector(vector);
	// 	std::cout << "it3 = it2 = " << *it3 << std::endl;
	// 	std::cout << "it3 == it2 = " << (it3 == it2) << std::endl;
	// 	std::cout << "it3 != it2 = " << (it3 != it2) << std::endl;
	// 	it2 = (it++);
	// 	std::cout << "it2 = " << *(it2) << std::endl;
	// 	std::cout << "++it = " << *(++it) << std::endl;
	// 	std::cout << "*it++ = " << *it++ << std::endl;
	// 	std::cout << "it-- = " << *(it--) << std::endl;
	// 	std::cout << "--it = " << *(--it) << std::endl;
	// 	std::cout << "*it-- = " << *it-- << std::endl;
	// 	size_t n = 3;
	// 	std::cout << "it + " << n << " = " << *(it + n) << std::endl;
	// 	std::cout << n << " + it = " << *(n + it) << std::endl;
	// 	it++;
	// 	std::cout << "it - " << 1 << " = " << *(it - 1) << std::endl;
	// 	std::cout << "it - it2 = " << (it - it2) << std::endl;
	// 	std::cout << "it < it3 = " << (it < ++it3) << std::endl;
	// 	std::cout << "it > it3 = " << (it > it3) << std::endl;
	// 	std::cout << "it <= it3 = " << (it <= it3) << std::endl;
	// 	std::cout << "it >= it3 = " << (it >= it3) << std::endl;
	// 	std::cout << "it += 4 = " << *(it+=4) << std::endl;
	// 	std::cout << "it -= 3 = " << *(it-=3) << std::endl;
	// 	std::cout << "it[1] = " << it[1] << std::endl;


	// 	LIB::vector<int>::reverse_iterator  rit = vector.rbegin();
	// 	std::cout << "vector.rbegin() = " << *rit << std::endl;
	// 	std::cout << "++rit = " << *(++rit) << std::endl;
	// 	rit = vector.rend();
	// 	std::cout << "vector.rend() = " << *rit << std::endl;
	// 	std::cout << "Capacity" << std::endl;
	// 	std::cout << "vector.size() = " << vector.size() << std::endl;
	// 	std::cout << "vector.size_max() = " << vector.max_size() << std::endl;
	// 	std::cout << "vector.resize(" << vector.size() + 3 << ")" << std::endl;
	// 	vector.resize(size + 3, 60);
	// 	print_vector(vector);
	// 	std::cout << std::endl << std::endl;
	// 	std::cout << "vector.resize(" << vector.size() - 6 << ")" << std::endl;
	// 	vector.resize(size - 3, 60);
	// 	print_vector(vector);
	// 	std::cout << std::endl;
	// 	// std::cout << "vector.capacity = " << vector.capacity() << std:: endl;
	// 	std::cout << "vector.empty() = " << vector.empty() << std::endl;
	// 	vector.reserve(vector.size() * 4);
	// 	// std::cout << "vector.reserve(" << vector.size() * 4 << ") -> vector.capacity() = " << vector.capacity() << std::endl;
	// 	print_vector(vector);
	// 	std::cout << std::endl << "Modifiers" << std::endl;
	// 	it = vector.begin();
	// 	it2 = vector.end();
	// 	vector_empty.assign(it, it2);
	// 	std::cout << "assign(it2, it)" << std::endl;
	// 	print_vector(vector_empty);
	// 	std::cout << std::endl;
	// 	vector_empty.push_back(98);
	// 	std::cout << "push_back(98)" << std::endl;
	// 	print_vector(vector_empty);
	// 	std::cout << "pop_back()" << std::endl;
	// 	print_vector(vector_empty);
	// 	vector_empty.insert(vector_empty.begin() + 3, 42);
	// 	std::cout << "vector.insert(begin() + 3, 42)" << std::endl;
	// 	print_vector(vector_empty);
	// 	std::cout << "vector.insert(begin() + 4, 5, -75)" << std::endl;
	// 	vector_empty.insert(vector_empty.begin() + 4, 5, -75);
	// 	std::cout << "vector_empty:" << std::endl;
	// 	print_vector(vector_empty);
	// 	std::cout << std::endl;
	// 	std::cout << "vector:" << std::endl;
	// 	print_vector(vector);
	// 	std::cout << std::endl;
	// 	std::cout << "vector.insert(begin(), anothervector.begin(), anothervector.end())" << std::endl;
	// 	vector.insert(vector.begin(), vector_empty.begin(),vector_empty.end());
	// 	print_vector(vector);
	// 	std::cout << "it = vector.erase(begin() + 5)" << std::endl;
	// 	it = vector.erase(vector.begin() + 5);
	// 	print_vector(vector);
	// 	std::cout << "*it = " << *it << std::endl;
	// 	std::cout << "it = vector.erase(begin() + 5, begin() + 9)" << std::endl;
	// 	it = vector.erase(vector.begin() + 5, vector.begin() + 9);
	// 	print_vector(vector);
	// 	std::cout << "*it = " << *it << std::endl;
	// 	std::cout << "vector = vector2" << std::endl;
	// 	vector = vector_empty;
	// 	print_vector(vector);
	// 	LIB::vector<int> vector2(vector);
	// 	std::cout << "Copy constructor:" << std::endl;
	// 	std::cout << "vector2(vector)" << std::endl;
	// 	print_vector(vector2);
	// 	LIB::vector<int> vector4(size,value);
	// 	std::cout << "vector.swap(vector_3)" << std::endl;
	// 	vector.swap(vector4);
	// 	print_vector(vector);
	// 	print_vector(vector4);
	// 	std::cout << "vector.clear()" << std::endl;
	// 	vector.clear();
	// 	print_vector(vector);
	// 	std::cout << "vector >= vector4 -> " << (vector >= vector4) << std::endl;
	// 	std::cout << "vector > vector4 -> " << (vector > vector4) << std::endl;
	// 	std::cout << "vector < vector4 -> " << (vector < vector4) << std::endl;
	// 	std::cout << "vector <= vector4 -> " << (vector <= vector4) << std::endl;
	// 	std::cout << "vector == vector4 (not equal) -> " << (vector == vector4) << std::endl;
	// 	std::cout << "vector != vector4 (not equal) -> " << (vector != vector4) << std::endl;
	// 	vector = vector4;
	// 	std::cout << "vector >= vector4 -> " << (vector >= vector4) << std::endl;
	// 	std::cout << "vector > vector4 (equal) -> " << (vector > vector4) << std::endl;
	// 	std::cout << "vector <= vector4 (equal) -> " << (vector <= vector4) << std::endl;
	// 	std::cout << "vector < vector4 (equal) -> " << (vector < vector4) << std::endl;
	// 	std:: cout << "vector == vector4 (equal) -> " << (vector == vector4) << std::endl;
	// 	std:: cout << "vector != vector4 (equal) -> " << (vector != vector4) << std::endl;
	// 	swap(vector,vector4);
	// 	print_vector(vector);
	// 	print_vector(vector4);
	// 	std::cout << "equal(vector.begin(),vector.end(),vector4.begin()) -> " << LIB::equal(vector.begin(),vector.end(),vector4.begin()) << std::endl;
	// 	std::cout << "lexicographical_compare(vector.begin(),vector.end(),vector4.begin()) -> " << LIB::lexicographical_compare(vector.begin(),vector.end(),vector4.begin(), vector4.end()) << std::endl;
	// }
    // catch(std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}