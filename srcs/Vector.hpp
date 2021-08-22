
#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>
# include <memory>

namespace ft {
template	<typename T, class Alloc = std::allocator<T> >
class Vector {
		private:
			typedef T	value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::pointer	pointer;
			typedef	size_t	size_type;
			typedef	value_type&	reference;	
			allocator_type	_alloc;
			pointer _pointer;
			size_type	_size;
		public:
			explicit Vector	(const allocator_type& alloc = allocator_type()): _alloc(alloc) {}
			
			explicit Vector	(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc),
			_pointer(_alloc.allocate(n)),
			_size(n) {
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_pointer + i, val);
			}
			
			reference	operator[](size_type n) {
				return (*(_pointer + n));
			}

			Vector	(const Vector& x);

	};
}
#endif