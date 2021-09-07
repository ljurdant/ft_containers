
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
			size_type	max_size() const {
				size_type	max_size = ~0;
				typename allocator_type::size_type	_alloc_size = _alloc.max_size();
				return (max_size > _alloc_size ? _alloc_size : max_size);
			};
			void	resize(size_type n, value_type val = value_type()) {
				pointer	new_pointer;
				new_pointer = _alloc.allocate(n);
				for (size_type i = 0; i < n && i < _size; i++)
					_alloc.construct(new_pointer + i, *(_pointer + i));
				for (size_type i = _size; i < n; i++)
					_alloc.construct(new_pointer + i, val);
				_alloc.deallocate(_pointer, _size);
				_alloc.destroy(_pointer);
				_pointer = new_pointer;
				_size = n;
				return ;
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