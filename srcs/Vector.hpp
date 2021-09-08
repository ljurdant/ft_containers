
#ifndef VECTOR_H
# define VECTOR_H

# include <iostream> //std::cout
# include <memory> //std::allocator
# include <iterator> //std::iterator_traits
# include "wrap_iter.hpp"

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
			typedef	__wrap_iter<pointer>					iterator;
			typedef	__wrap_iter<const_pointer>				const_iterator;
			typedef	std::reverse_iterator<iterator>			reverse_iterator;
		
		private:
			allocator_type	_alloc;
			pointer _pointer;
			size_type	_size;
			size_type	_capacity;
			size_type	const _max_size;

		
		public:
			//Constructors:
			explicit vector	(const allocator_type& alloc = allocator_type()): _alloc(alloc)
			,_size(0) 
			, _capacity(0)
			, _max_size(max_size())
			{}
			
			explicit vector	(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_size(0)
			, _capacity(0)
			, _max_size(max_size())
			{
				_alloc = alloc;
				reserve(n);
				_size = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_pointer + i, val);
			}
			
			//Iterators:
			iterator	begin() {
				iterator	it(_pointer);
				return (it); 
			}
			const_iterator	begin() const { 
				const_iterator	it(_pointer);
				return (it);
			}
			iterator	end() { 
				iterator	it(_pointer + _size);
				return (it); 
			}
			const_iterator	end() const { 
				const_iterator	it(_pointer + _size);
				return (_pointer + _size); 
			}
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
			size_type	max_size() const {
				size_type	max_size = ~0;
				typename allocator_type::size_type	_alloc_size = _alloc.max_size();
				return (max_size > _alloc_size ? _alloc_size : max_size);
			};
			void	resize(size_type n, value_type val = value_type()) {
				reserve(n); 
				std::cout << "_size = " << _size << std::endl;
				while (_size < n)
					_alloc.construct(_pointer + _size++, val);
				while (n < _size)
					_alloc.destroy(_pointer + _size--);
				return ;
			}
			size_type	capacity() const { return (_capacity); }
			bool		empty() const { return (!_size); }
			void		reserve(size_type n) {
				pointer	new_pointer;
				if (n > _max_size)
					throw std::length_error("vector");
				if (n > _capacity)
				{
					size_type	new_capacity = (_capacity ? _capacity : 1);
					while (new_capacity < n)
						new_capacity = new_capacity * 2;
					new_pointer = _alloc.allocate(new_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(new_pointer  + i, *(_pointer + i));
					if (_capacity)
						_alloc.deallocate(_pointer, _capacity);
					_pointer = new_pointer;
					_capacity = new_capacity;
				}
			}

			// Element access:
			reference	operator[](size_type n) { return (*(_pointer + n)); }
			const_reference operator[] (size_type n) const { return (*this[n]); }
			reference at (size_type n) { return (*this[n]); }
			const_reference at (size_type n) const { return (*this[n]); }
		    reference front() { return (*_pointer); }
			const_reference front() const { return (front()); }
			reference back() { return (*(_pointer + _size - 1)); }
			const_reference back() const { return (back()); }


			vector	(const vector& x);
	};
}
template<typename T>
typename ft::vector<T>::iterator
	operator+(typename ft::vector<T>::iterator::difference_type n, typename ft::vector<T>::iterator it) {
		return (it + n);
	}
#endif