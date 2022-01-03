
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
	std::cout << "<" << typeid(T).name() << "> " << "vector.size() = " << vector1.size();
	std::cout << "<" << typeid(T).name() << "> " << "vecotr.capacity() = " << vector1.capacity();

	std::cout << "<" << typeid(T).name() << "> " << "Constructor: vector(size): ";
	LIB::vector<T>	vector2(6);
	print_vector(vector2);
	LIB::vector<T>	vector3(0);
	print_vector(vector3);
	LIB::vector<T>	vector5(3000);
	print_vector(vector5);

	std::cout << "<" << typeid(T).name() << "> " << "Constructor: vector(size, value): ";
	LIB::vector<T>	vector6(6, 89);
	print_vector(vector6);
	LIB::vector<T>	vector7(0, -3);
	print_vector(vector7);
	LIB::vector<T>	vector9(3000, 6);
	print_vector(vector9);
	
	std::cout << "<" << typeid(T).name() << "> " << "Constructor: vector(vector): ";
	LIB::vector<T>	vector10(vector6);
	print_vector(vector10);

}

template<typename T>
void	operator_tests() {
	LIB::vector<T>	vector1(12, 4);
	LIB::vector<T>	vector2;

	std::cout << "<" << typeid(T).name() << "> " << "Operator=: (empty left side)";
	vector2 = vector1;
	print_vector(vector2);

	LIB::vector<T>	vector3(1001, 90);
	LIB::vector<T>	vector4;
	std::cout << "<" << typeid(T).name() << "> " << "Operator=: (empty right side)";
	vector3 = vector4;
	print_vector(vector3);

	LIB::vector<T>	vector5(1001, 90);
	LIB::vector<T>	vector6(2, 9);
	std::cout << "<" << typeid(T).name() << "> " << "Operator=: ";
	vector5 = vector6;
	print_vector(vector5);

	LIB::vector<T>	vector7(1001, 90);
	LIB::vector<T>	vector8(2, 9);
	std::cout << "<" << typeid(T).name() << "> " << "Operator>=: -> " << (vector7 >= vector8) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operaror>: -> " << (vector7 > vector8) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operator<: -> " << (vector7 < vector8) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operator<=: vector -> " << (vector7 <= vector8) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operaator==: (not equal) -> " << (vector7 == vector8) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operator!=: (not equal) -> " << (vector7 != vector8) << std::endl;

	LIB::vector<T>	vector9(2005, 254);
	LIB::vector<T>	vector10(2005, 254);
	std::cout << "<" << typeid(T).name() << "> " << "Operator>=: -> " << (vector9 >= vector10) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operaror>: -> " << (vector9 > vector10) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operator<: -> " << (vector9 < vector10) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operator<=: vector -> " << (vector9 <= vector10) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operaator==: (not equal) -> " << (vector9 == vector10) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "Operator!=: (not equal) -> " << (vector9 != vector10) << std::endl;
}

template <class T>
void	iterator_integral() {
	LIB::vector<T>	vector1(12, 5);
	int	i = 3;
	for (typename LIB::vector<T>::iterator it = vector1.begin(); it != vector1.end(); it++)
		*it = i++;

	typename LIB::vector<T>::iterator	it1 = vector1.begin();
	typename LIB::vector<T>::iterator	it2 = vector1.begin();
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator == iterator (equal) -> " << (it1 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator != iterator (equal) -> " << (it1 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator < iterator (equal) -> " << (it1 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator <= iterator (equal) -> " << (it1 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator > iterator (equal) -> " << (it1 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator <= iterator (equal) -> " << (it1 >= it2) << std::endl;


	typename LIB::vector<T>::iterator	it3 = vector1.end();
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator == iterator (unequal) -> " << (it3 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator != iterator (unequal) -> " << (it3 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator < iterator (unequal) -> " << (it3 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator <= iterator (unequal) -> " << (it3 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator > iterator (unequal) -> " << (it3 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator >= iterator (unequal) -> " << (it3 >= it2) << std::endl;

	std::cout << "<" << typeid(T).name() << "> " << "*iterator " << *it1 << std::endl;	
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator++ " << *(it1++) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral ++iterator "<< *(++it1) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator-- " << *(it1--) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral --iterator "<< *(--it1) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator + 4 " << *(it1 + 4) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral 4 + iterator " << *(4 + it1) << std::endl;
	it1 = (4 + it1);
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator - 3 " << *(it1 - 3) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "end - begin " << vector1.end() - vector1.begin() << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator+=5 " << *(it1+=5) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral iterator-=6 " << *(it1-=6) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "intergal iterator[5] " << it1[5] << std::endl;

	typename LIB::vector<T>::const_iterator	it4 = vector1.begin();
	(void)it4;
}

template <class T>
void	iterator_class() {
	LIB::vector<T>	vector1(12, 5);
	int	i = 3;
	for (typename LIB::vector<T>::iterator it = vector1.begin(); it != vector1.end(); it++)
		it->value = i++;

	typename LIB::vector<T>::iterator	it1 = vector1.begin();
	typename LIB::vector<T>::iterator	it2 = vector1.begin();
	std::cout << "<" << typeid(T).name() << "> " << "class iterator == iterator (equal) -> " << (it1 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator != iterator (equal) -> " << (it1 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator < iterator (equal) -> " << (it1 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator <= iterator (equal) -> " << (it1 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator > iterator (equal) -> " << (it1 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator <= iterator (equal) -> " << (it1 >= it2) << std::endl;

	typename LIB::vector<T>::iterator	it3 = vector1.end();
	std::cout << "<" << typeid(T).name() << "> " << "class iterator == iterator (unequal) -> " << (it3 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator != iterator (unequal) -> " << (it3 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator < iterator (unequal) -> " << (it3 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator <= iterator (unequal) -> " << (it3 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator > iterator (unequal) -> " << (it3 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator >= iterator (unequal) -> " << (it3 >= it2) << std::endl;

	std::cout << "<" << typeid(T).name() << "> " << "iterator-> " << it1->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator++ " << (it1++)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class ++iterator "<< (++it1)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator-- " << (it1--)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class --iterator "<< (--it1)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator + 4 " << (it1 + 4)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class 4 + iterator " << (4 + it1)->value << std::endl;
	it1 = (4 + it1);
	std::cout << "<" << typeid(T).name() << "> " << "class iterator - 3 " << (it1 - 3)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "end - begin " << vector1.end() - vector1.begin() << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator+=5 " << (it1+=5)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator-=6 " << (it1-=6)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class iterator[5] " << it1[5].value << std::endl;

	typename LIB::vector<T>::const_iterator	it4 = vector1.begin();
	(void)it4;
}

template <typename T>
void	reverse_iterator_integral() {
	LIB::vector<T>	vector1(12, 5);
	int	i = 3;
	for (typename LIB::vector<T>::iterator it = vector1.begin(); it != vector1.end(); it++)
		*it = i++;

	typename LIB::vector<T>::reverse_iterator	it1 = vector1.rbegin();
	typename LIB::vector<T>::reverse_iterator	it2 = vector1.rbegin();
	
	it1--;
	LIB::vector<T> vct(5);
	typename LIB::vector<T>::iterator it_ = vct.begin();
	typename LIB::vector<T>::reverse_iterator it(it_);
	for (int i = 0; i < 5; ++i)
		vct[i] = (i + 1) * 5;
	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;
	std::cout << *(it.base() + 1) << std::endl;
	// std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	// it -= 3;
	// std::cout << *it.base() << std::endl;
	// std::cout << *(it) << std::endl;
	// std::cout << *(it).base() << std::endl;
	// std::cout << *(it - 0) << std::endl;
	// std::cout << *(it - 0).base() << std::endl;
	// std::cout << *(it - 1).base() << std::endl;

	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator == reverse_iterator (equal) -> " << (it1 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator != reverse_iterator (equal) -> " << (it1 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator < reverse_iterator (equal) -> " << (it1 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator <= reverse_iterator (equal) -> " << (it1 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator > reverse_iterator (equal) -> " << (it1 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator <= reverse_iterator (equal) -> " << (it1 >= it2) << std::endl;


	typename LIB::vector<T>::reverse_iterator	it3 = vector1.rend();
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator == reverse_iterator (unequal) -> " << (it3 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator != reverse_iterator (unequal) -> " << (it3 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator < reverse_iterator (unequal) -> " << (it3 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator <= reverse_iterator (unequal) -> " << (it3 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator > reverse_iterator (unequal) -> " << (it3 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator >= reverse_iterator (unequal) -> " << (it3 >= it2) << std::endl;

	std::cout << "<" << typeid(T).name() << "> " << "*reverse_iterator " << *it1 << std::endl;	
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator++ " << *(it1++) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral ++reverse_iterator "<< *(++it1) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator-- " << *(it1--) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral --reverse_iterator "<< *(--it1) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator + 4 " << *(it1 + 4) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral 4 + reverse_iterator " << *(4 + it1) << std::endl;
	it1 = (4 + it1);
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator - 3 " << *(it1 - 3) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral rbegin - rend " << vector1.rbegin() - vector1.rend() << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator+=5 " << *(it1+=5) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator-=6 " << *(it1-=6) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "integral reverse_iterator[5] " << it1[5] << std::endl;

	typename LIB::vector<T>::const_reverse_iterator	it4 = vector1.rbegin();
	std::cout << "<" << typeid(T).name() << "> " << "*const_reverse_iterator (rbegin)" << *(it4) << std::endl;
	it4 = vector1.rend();
	std::cout << "<" << typeid(T).name() << "> " << "*const_reverse_iterator (rend - 1)" << *(it4 - 1) << std::endl;
}

template <class T>
void	reverse_iterator_class() {
	LIB::vector<T>	vector1(12, 5);
	int	i = 3;
	for (typename LIB::vector<T>::iterator it = vector1.begin(); it != vector1.end(); it++)
		it->value = i++;

	typename LIB::vector<T>::reverse_iterator	it1 = vector1.rbegin();
	typename LIB::vector<T>::reverse_iterator	it2 = vector1.rbegin();
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator == reverse_iterator (equal) -> " << (it1 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator != reverse_iterator (equal) -> " << (it1 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator < reverse_iterator (equal) -> " << (it1 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator <= reverse_iterator (equal) -> " << (it1 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator > reverse_iterator (equal) -> " << (it1 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator <= reverse_iterator (equal) -> " << (it1 >= it2) << std::endl;

	typename LIB::vector<T>::reverse_iterator	it3 = vector1.rend();
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator == reverse_iterator (unequal) -> " << (it3 == it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator != reverse_iterator (unequal) -> " << (it3 != it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator < reverse_iterator (unequal) -> " << (it3 < it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator <= reverse_iterator (unequal) -> " << (it3 <= it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator > reverse_iterator (unequal) -> " << (it3 > it2) << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator >= reverse_iterator (unequal) -> " << (it3 >= it2) << std::endl;

	std::cout << "<" << typeid(T).name() << "> " << "reverse_iterator-> " << it1->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator++ " << (it1++)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class ++reverse_iterator "<< (++it1)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator-- " << (it1--)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class --reverse_iterator "<< (--it1)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator + 4 " << (it1 + 4)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class 4 + reverse_iterator " << (4 + it1)->value << std::endl;
	it1 = (4 + it1);
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator - 3 " << (it1 - 3)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator+=5 " << (it1+=5)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator-=6 " << (it1-=6)->value << std::endl;
	std::cout << "<" << typeid(T).name() << "> " << "class reverse_iterator[5] " << it1[5].value << std::endl;

	typename LIB::vector<T>::const_reverse_iterator	it4 = vector1.rbegin();
	std::cout << "<" << typeid(T).name() << "> " << "const_reverse_iterator-> (rbegin)" << (it4)->value << std::endl;
	it4 = vector1.rend();
	std::cout << "<" << typeid(T).name() << "> " << "const_reverse_iterator-> (rend - 1) " << (it4 - 1)->value << std::endl;
}

template<typename T>
void	capacity_tests() {
	LIB::vector<T>	vector1(0);
	LIB::vector<T>	vector2(3000);

	std::cout << "size() = " << vector1.size();
	std::cout << "empty()" << vector1.empty();
	std::cout << "size() = " << vector2.size();
	std::cout << "empty()" << vector2.empty();
	std::cout << "max_size() = " << vector1.max_size();
	vector1.resize(4);

	std::cout << "resize from 0 to 4 -> size = " << vector1.size() << std::endl;
	vector1[3] = 5;
	vector2.resize(0);
	std::cout << "resize from 3000 to 0 -> size = " << vector2.size() << std::endl;
	vector1.reserve(11);
	std::cout << "reserve(11) -> size = " << vector1.size() << std::endl;
	vector1.reserve(0);
	std::cout << "reserve(0) -> size = " << vector1.size() << std::endl;
}

template<typename T>
void	element_access_tests() {
	LIB::vector<T>	vector1(3000);

	std::cout << "vector1[400] = " << vector1[400] << std::endl;
	vector1[401] = 89;
	vector1[399] = 88;
	std::cout << "vector1[400] = " << vector1[400] << std::endl;
	std::cout << "vector1[401] = " << vector1[401] << std::endl;
	vector1.resize(300);
	vector1.reserve(2000);
	vector1.reserve(4000);
	typename LIB::vector<T>::const_reference a = vector1[299];
	std::cout << "const_reference vector[401] = " << a << std::endl;

	LIB::vector<T>	vector2(3000);
	std::cout << "vector2[400] = " << vector2.at(400) << std::endl;
	vector2[401] = 89;
	vector2[399] = 88;
	std::cout << "vector2[400] = " << vector2.at(400) << std::endl;
	std::cout << "vector2[401] = " << vector2.at(401) << std::endl;
	vector2.resize(300);
	// try
	// {
	// 	std::cout << "vector2[401] = " << vector2.at(401) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "bad length error" << '\n';
	// }
	vector2.reserve(2000);
	// try
	// {
	// 	std::cout << "vector2[2200] = " << vector2.at(2200) << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "bad length error" << std::endl;
	// }
	vector2.reserve(4000);
	// try
	// {
	// 	std::cout << "vector2[3300] = " << vector2.at(3300)<< std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "bad length error" << std::endl;
	// }

	typename LIB::vector<T>::const_reference b = vector1.at(299);
	std::cout << "const_reference vector.at(401) = " << b << std::endl;
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
	reverse_iterator_integral<int>();
	// reverse_iterator_integral<char>();
	// reverse_iterator_integral<long long int>();
	// reverse_iterator_class<test>();
	capacity_tests<int>();
	capacity_tests<char>();
	capacity_tests<long long>();
	capacity_tests<test>();
	element_access_tests<int>();
}