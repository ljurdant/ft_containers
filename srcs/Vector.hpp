
#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <memory>
# include <iterator>

namespace ft {
template	<typename T, class Alloc = std::allocator<T> >
class vector {
		public:
			typedef T	value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::pointer	pointer;
			typedef	size_t	size_type;
			typedef	value_type&	reference;
			typedef value_type const & const_reference;
		class: public std:: iterator<random_access_iterator_tag,T> iterator {
			
		};
		
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
			iterator begin() {
			 	return ();
			}

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
#endif