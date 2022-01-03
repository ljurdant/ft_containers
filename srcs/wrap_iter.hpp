#ifndef WRAP_ITER_H
# define WRAP_ITER_H

#include "RedBlackBinaryTree.hpp"
#include "ft_utilities.hpp"

namespace ft {

template<class _Iter>						
	class	 __wrap_iter {
		public:
			typedef _Iter															iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			typedef	const value_type *												const_iterator_type;
		protected:
			iterator_type	__i;

		public:
			__wrap_iter() {}
			__wrap_iter(__wrap_iter const &copy) {*this = copy;}
			__wrap_iter					&operator=(__wrap_iter<iterator_type>  const &rhs) {
				__i = rhs.__i;
				return (*this);
			}
			reference		operator*() const { return (*__i);}
			pointer			operator->() const { return (__i);}
			__wrap_iter		operator++(int) { return (__i++); }
			__wrap_iter		&operator++() { ++__i; return (*this); }
			__wrap_iter		operator--(int) { return (__i--); }
			__wrap_iter		&operator--() { --__i; return(*this);}			
			__wrap_iter		operator+(difference_type n) const { return (__i + n); }
			__wrap_iter		operator-(difference_type n) const { return (__i - n); }
			difference_type	operator-(__wrap_iter const &rhs) const { return(__i - (rhs.__i)); }
			__wrap_iter		operator+=(difference_type n) { return (__i += n ); }
			__wrap_iter		operator-=(difference_type n) { return (__i -= n); }
			reference		operator[](difference_type n) const { return (__i[n]); }			

			__wrap_iter(iterator_type const &p): __i(p){}

			operator const __wrap_iter<const_iterator_type>() {
				__wrap_iter<const_iterator_type>	ret(const_cast<const iterator_type>(__i));
				return (ret);
			}
	};
template<class _Iter>
	__wrap_iter<_Iter>	operator+(typename __wrap_iter<_Iter>::difference_type n, __wrap_iter<_Iter> &it) { return (it + n); }

template<class T, class U>
	bool			operator==(__wrap_iter<T> const &lhs, __wrap_iter<U> const &rhs) { return (&(*lhs) == &(*rhs)); }

template<class T, class U>
	bool			operator!=(__wrap_iter<T> const &lhs, __wrap_iter<U> const &rhs) { return (!(lhs == rhs)); }

template<class T, class U>
	bool			operator<(__wrap_iter<T> const &lhs, __wrap_iter<U> const &rhs) { return (&(*lhs) < &(*rhs)); }

template<class T, class U>
bool			operator<=(__wrap_iter<T> const &lhs, __wrap_iter<U> const &rhs) { return (lhs < rhs || lhs == rhs); }

template<class T, class U>
bool			operator>(__wrap_iter<T> const &lhs, __wrap_iter<U> const &rhs) { return (!(lhs <= rhs)); }

template<class T, class U>
bool			operator>=(__wrap_iter<T> const &lhs, __wrap_iter<U> const &rhs) { return (!(lhs < rhs)); }

template<class _Iter>						
	class	 __wrap_reverse_iter {
		public:
			typedef _Iter															iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			typedef const value_type *												const_iterator_type;

		protected:
			iterator_type	__i;		
		public:
			__wrap_reverse_iter() {}
			__wrap_reverse_iter(__wrap_reverse_iter const &copy) {*this = copy;}
			__wrap_reverse_iter	&operator=(__wrap_reverse_iter<iterator_type>  const &rhs) {
				__i = rhs.__i;
				return (*this);
			}
			iterator_type	base() const { return (__i); }
			bool			operator==(__wrap_reverse_iter const &rhs) const { return (__i == rhs.__i);}
			bool			operator!=(__wrap_reverse_iter const &rhs) const { return (__i != rhs.__i);}
			reference		operator*() const { 
				iterator_type	base(__i);
				base--;
				return (*base); 
			}
			iterator_type	operator->() const { return (&(operator*())); }
			bool			operator<(__wrap_reverse_iter const &rhs) { return (__i > rhs.__i); }
			bool			operator>(__wrap_reverse_iter const &rhs) { return (__i < rhs.__i); } 
			bool			operator<=(__wrap_reverse_iter const &rhs) { return (__i >= rhs.__i); }
			bool			operator>=(__wrap_reverse_iter const &rhs) { return (__i <= rhs.__i); }
			reference		operator[](difference_type n) const { return (*(__i - n - 1)); }			

			__wrap_reverse_iter(iterator_type const &p): __i(p){}

			__wrap_reverse_iter		operator++(int) { return (__i--); }
			__wrap_reverse_iter		&operator++() { --__i; return (*this); }
			__wrap_reverse_iter		operator--(int) { return (__i++); }
			__wrap_reverse_iter		&operator--() { ++__i; return (*this);}			
			__wrap_reverse_iter		operator+(difference_type n) const { return (__i - n); }
			__wrap_reverse_iter		operator-(difference_type n) const { return (__i + n); }
			difference_type			operator-(__wrap_reverse_iter const &rhs) const { return (rhs.__i - __i); }
			__wrap_reverse_iter		operator+=(difference_type n) { return (__i -= n); }
			__wrap_reverse_iter		operator-=(difference_type n) { return (__i += n); }

			operator __wrap_reverse_iter<__wrap_iter<const_iterator_type> >() {
				__wrap_iter<const_iterator_type>	it(__i);
				__wrap_reverse_iter<__wrap_iter<const_iterator_type> >	rit(it);
				return (rit);
			}			
	};
template<class _Iter>
		__wrap_reverse_iter<_Iter>	operator+(typename __wrap_reverse_iter<_Iter>::difference_type n, const __wrap_reverse_iter<_Iter> &it) {return (it + n); }
template<class T, class U>
	bool			operator==(__wrap_reverse_iter<T> const &lhs, __wrap_reverse_iter<U> const &rhs) { return (&(*lhs) == &(*rhs)); }

template<class T, class U>
	bool			operator!=(__wrap_reverse_iter<T> const &lhs, __wrap_reverse_iter<U> const &rhs) { return (!(lhs == rhs)); }

template<class T, class U>
	bool			operator<(__wrap_reverse_iter<T> const &lhs, __wrap_reverse_iter<U> const &rhs) { return (&(*lhs) > &(*rhs)); }

template<class T, class U>
bool			operator<=(__wrap_reverse_iter<T> const &lhs, __wrap_reverse_iter<U> const &rhs) { return (lhs < rhs || lhs == rhs); }

template<class T, class U>
bool			operator>(__wrap_reverse_iter<T> const &lhs, __wrap_reverse_iter<U> const &rhs) { return (!(lhs <= rhs)); }

template<class T, class U>
bool			operator>=(__wrap_reverse_iter<T> const &lhs, __wrap_reverse_iter<U> const &rhs) { return (!(lhs < rhs)); }


template < class _Iter >
class	 __wrap_biiter   {
	public:
			typedef _Iter															iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			typedef	const iterator_type												const_iterator_type;

		protected:
			iterator_type	__i;

		public:
			__wrap_biiter() {}
			__wrap_biiter(__wrap_biiter const &copy): __i(copy.__i) {}
			__wrap_biiter					&operator=(__wrap_biiter<iterator_type>  const &rhs) {
				__i = rhs.__i;
				return (*this);
			}
			bool			operator==(__wrap_biiter const &rhs) const { return (__i == rhs.__i);}
			bool			operator!=(__wrap_biiter const &rhs) const { return (__i != rhs.__i);}
			reference		operator*() const { return (*__i);}
			pointer			operator->() const { return (__i);}
			__wrap_biiter	operator++(int) { return (__i++); }
			__wrap_biiter	&operator++() { ++__i; return (*this); }
			__wrap_biiter	operator--(int) { return (__i--); }
			__wrap_biiter	&operator--() { --__i; return(*this);}			

			__wrap_biiter(iterator_type const &p): __i(p){}
		};

template<class _Iter>						
	class	 __wrap_reverse_biiter {
	public:
		typedef _Iter															iterator_type;
		typedef typename std::iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename std::iterator_traits<iterator_type>::value_type		value_type;
		typedef typename std::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename std::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename std::iterator_traits<iterator_type>::reference			reference;
	protected:
		iterator_type	__i;

	public:
		__wrap_reverse_biiter() {}
		__wrap_reverse_biiter(__wrap_reverse_biiter const &copy) {*this = copy;}
		__wrap_reverse_biiter					&operator=(__wrap_reverse_biiter<iterator_type>  const &rhs) {
			__i = rhs.__i;
			return (*this);
		}
		bool					operator==(__wrap_reverse_biiter const &rhs) const { return (__i == rhs.__i);}
		bool					operator!=(__wrap_reverse_biiter const &rhs) const { return (__i != rhs.__i);}
		reference				operator*() const { return (*__i);}
		pointer					operator->() const { return (__i);}
		__wrap_reverse_biiter	operator++(int) { return (__i--); }
		__wrap_reverse_biiter	&operator++() { --__i; return (*this); }
		__wrap_reverse_biiter	operator--(int) { return (__i++); }
		__wrap_reverse_biiter	&operator--() { ++__i; return (*this);}			

		__wrap_reverse_biiter(iterator_type const &p): __i(p){}

	};
}
#endif