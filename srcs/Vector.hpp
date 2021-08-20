
#ifndef VECTOR_H
# define VECTOR_H

# include <iostream>

template	<typename T, class Alloc = std::allocator<T>>
class Vector {
	private:
		typedef T	value_type;
		typedef Alloc	allocator_type;
		typedef allocator_type::pointer	pointer;
	public:
		explicit Vector	(const allocator_type& alloc = allocator_type) {
			;
		}
		explicit Vector	(size_t n, const value_type& val = value_type, const allocator_type& alloc = allocator_type) {
			pointer = allocator_type::allocate(n);
		}
		Vector	(const Vector& x);

};

#endif