#ifndef FT_UTILITIES_H
# define FT_UTILITIES_H

#include <limits>

namespace ft
{
	struct input_interator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template <class Iterator> struct iterator_traits {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T> struct iterator_traits<T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T *								pointer;
		typedef T &								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template <class T> struct iterator_traits<const T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T *						pointer;
		typedef const T &						reference;
		typedef random_access_iterator_tag	iterator_category;
	};
	
	// template <typename T>
	// 	struct is_integral {
  	// 		static const bool value;
	// 	};
	// template <typename T>
	// 	const bool is_integral<T>::value = std::numeric_limits<T>::is_integer;

	template <bool B>
	struct integral_const{ static const bool	value = B;};
	template <typename T>
		struct is_integral: integral_const<false> {};
	template <>
	struct is_integral<bool> : integral_const<true> {};
	template <>
	struct is_integral<char> : integral_const<true> {};
	template <>
	struct is_integral<wchar_t> : integral_const<true> {};
	template <>
	struct is_integral<signed char> : integral_const<true> {};
	template <>
	struct is_integral<short int> : integral_const<true> {};
	template <>
	struct is_integral<int> : integral_const<true> {};
	template <>
	struct is_integral<long int> : integral_const<true> {};
	template <>
	struct is_integral<long long int> : integral_const<true> {};
	template <>
	struct is_integral<unsigned char> : integral_const<true> {};
	template <>
	struct is_integral<unsigned short int> : integral_const<true> {};
	template <>
	struct is_integral<unsigned int> : integral_const<true> {};
	template <>
	struct is_integral<unsigned long int> : integral_const<true> {};
	template <>
	struct is_integral<unsigned long long int> : integral_const<true> {};

	template<bool B, class T = void>
		struct enable_if {};
 
	template<class T>
		struct enable_if<true, T> { typedef T type; };

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
			while (first1 != last1) 
			{
				if (!pred(*first1, *first2))
					return (false);
				first1++;
				first2++;
			}
			return (true);
		}
	template <class InputIterator1, class InputIterator2>
  		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
			while (first1 != last1) 
			{
				if (!(*first1 == *first2))
					return (false);
				first1++;
				first2++;
			}
			return (true);
		}
	
	template <class InputIterator1, class InputIterator2, class Compare>
  		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
			while (first1 != last1)
			{
				if (first2 == last2 || comp(*first2, *first1))
					return (false);
				else if (comp(*first1, *first2))
					return (true);
				first1++;
				first2++;
			}
			return (first2 != last2);
		}
	template <class InputIterator1, class InputIterator2>
  		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
			while (first1 != last1)
			{
				if (first2 == last2 || *first2 < *first1)
					return (false);
				else if (*first1 < *first2)
					return (true);
				first1++;
				first2++;
			}
			return (first2 != last2);
		}
	template <class T1, class T2> struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair():
		first(first_type()), second(second_type()){
		}
		pair (const first_type& a, const second_type& b):
		first(a), second(b) {
		}
		template<class U, class V>
			pair (const pair<U,V>& pr): 
			first(pr.first), second(pr.second) {
			}
		pair& operator= (const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
		bool operator== (const pair<T1,T2>& rhs) { return (first == rhs.first && second == rhs.second); }

		bool operator!= (const pair<T1,T2>& rhs) { return (!(*this == rhs)); }

		bool operator< (const pair<T1,T2>& rhs) { return (first < rhs.first || (!(rhs.first < first) && second < rhs.second)); }

		bool operator<= (const pair<T1,T2>& rhs) { return (!(rhs < *this)); }

		bool operator>  (const pair<T1,T2>& rhs) { return (rhs < *this); }

		bool operator>= (const pair<T1,T2>& rhs) { return (!(*this < rhs)); }
	};
	template <class T1,class T2>
  		pair<T1,T2> make_pair (T1 x, T2 y) { return ( pair<T1,T2>(x,y) ); }
}
# endif