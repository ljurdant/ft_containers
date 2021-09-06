
#ifndef VECTOR_H
# define VECTOR_H

# include <iostream> //std::cout
# include <memory> //std::allocator
# include <iterator> //std::iterator_traits

namespace ft {
template	<typename T, class Alloc = std::allocator<T> >
class vector {
		public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef	size_t									size_type;
			typedef	value_type &							reference;
			typedef value_type const & 						const_reference;
			typedef	std::iterator_traits<pointer>			iterator_traits;
			// template<class _Iter>						
			// class	 __wrap_iter {
			// 	public:
			// 		typedef _Iter															iterator_type;
			// 		typedef typename std::iterator_traits<iterator_type>::iterator_category	iterator_category;
			// 		typedef typename std::iterator_traits<iterator_type>::value_type		value_type;
			// 		typedef typename std::iterator_traits<iterator_type>::difference_type	difference_type;
			// 		typedef typename std::iterator_traits<iterator_type>::pointer			pointer;
			// 		typedef typename std::iterator_traits<iterator_type>::reference			reference;
				
			// 	private:
			// 		iterator_type	__i;
			// 	public:
			// 		__wrap_iter() {}
			// 		__wrap_iter(__wrap_iter const &copy) {*this = copy;}
			// 		__wrap_iter		&operator=(__wrap_iter<iterator_type>  const &rhs) {
			// 			__i = rhs.__i;
			// 			return (*this);
			// 		}
			// 		bool			operator==(__wrap_iter const &rhs) const { return (__i == rhs.__i);}
			// 		bool			operator!=(__wrap_iter const &rhs) const { return (__i != rhs.__i);}
			// 		reference		operator*() const { return (*__i);}
			// 		pointer			operator->() const { return (__i);}
			// 		iterator_type	operator++(int) { return (__i++);}
			// 		iterator_type	operator++() { return (++__i);}
			// 		iterator_type	operator--(int) { return (__i--);}
			// 		iterator_type	operator--() { return (--__i);}			
			// 		iterator_type	operator+(difference_type n) const {return (__i + n);}

					
			// 		__wrap_iter(iterator_type const &p): __i(p){}
			// };
			// typedef __wrap_iter<pointer>			iterator;
			typedef	pointer							iterator;
			typedef	const_pointer					const_iterator;
			typedef	std::reverse_iterator<iterator>	reverse_iterator;
		
		private:
			allocator_type	_alloc;
			pointer _pointer;
			size_type	_size;
		
		public:
			//Constructors:
			explicit vector	(const allocator_type& alloc = allocator_type()): _alloc(alloc) {}
			
			explicit vector	(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc),
			_pointer(_alloc.allocate(n)),
			_size(n) {
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_pointer + i, val);
			}
			
			//Iterators:
			iterator	begin() { return (_pointer); }
			const_iterator	begin() const { return (_pointer);}
			iterator	end() { return (_pointer + _size); }
			const_iterator	end() const { return (_pointer + _size); }
			reverse_iterator	rbegin() {
				reverse_iterator	rit(end());
				return (rit);	
			}
			reverse_iterator	rend() {
				reverse_iterator	rit(begin());
				return (rit);	
			}

			//Capacity
			size_type	size() const { return (_size); };
			size_type	max_size() const {return (4611686018427387903); };

			// Element access:
			reference	operator[](size_type n) {
				return (*(_pointer + n));
			}
			const_reference operator[] (size_type n) const {
				return (*this[n]);
			}
			reference at (size_type n) {
				return (*this[n]);
			}
			const_reference at (size_type n) const {
				return (*this[n]);
			}
		    reference front() {
				return (*_pointer);
			}
			const_reference front() const {
				return (front());
			}
			reference back() {
				return (*(_pointer + _size - 1));
			}
			const_reference back() const {
				return (back());
			}


			vector	(const vector& x);
	};
}
template<typename T>
typename ft::vector<T>::iterator
	operator+(typename ft::vector<T>::iterator::difference_type n, typename ft::vector<T>::iterator it) {
		return (it + n);
	}
#endif