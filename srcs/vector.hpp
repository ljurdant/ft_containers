
#ifndef VECTOR_H
# define VECTOR_H

# include <memory> //std::allocator
# include <iterator> //std::iterator_traits
# include "wrap_iter.hpp"
# include "ft_utilities.hpp"
# include <stdexcept>
# include <string>

namespace ft {
template	<typename T, class Alloc = std::allocator<T> >
class vector {
		public:	

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	size_t										size_type;
			typedef	value_type &								reference;
			typedef value_type const & 							const_reference;
			typedef	std::iterator_traits<pointer>				iterator_traits;
			typedef	__wrap_iter<pointer>						iterator;
			typedef	__wrap_iter<const_pointer>					const_iterator;
			typedef	__wrap_reverse_iter<iterator>				reverse_iterator;
			typedef	__wrap_reverse_iter<const_iterator>			const_reverse_iterator;
			typedef	typename iterator_traits::difference_type	difference_type;

		
		protected:
			allocator_type	_alloc;
			pointer _pointer;
			size_type	_size;
			size_type	_capacity;
			size_type	const _max_size;

		
		public:
			//Constructors:
			explicit vector	(const allocator_type& alloc = allocator_type()): 
				_alloc(alloc), _pointer(NULL), _size(0) , _capacity(0), _max_size(max_size()) {
			}
			
			explicit vector	(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _pointer(NULL), _size(0), _capacity(0), _max_size(max_size()) {
				assign(n, val);
			}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
			 _alloc(alloc), _pointer(NULL), _size(0), _capacity(0), _max_size(max_size()) {
				assign(first, last);
			 }

			vector (const vector& x): _alloc(allocator_type()), _pointer(NULL), _size(0), _capacity(0), _max_size(x._max_size) {
				*this = x;
			}

			//Destructor
			~vector() {
				clear();
				if (_capacity)
					_alloc.deallocate(_pointer, _capacity);
				_capacity = 0;
			}

			//Operator=
			vector& operator= (const vector& x){
				clear();
				assign(x.begin(), x.end());
				return (*this);
			}

			//Iterators:
			iterator				begin() { return (_pointer); }
			const_iterator			begin() const { return (const_cast<const_pointer>(_pointer)); }
			iterator				end() { return (_pointer + _size); }
			const_iterator			end() const { return (_pointer + _size); }
			reverse_iterator		rbegin() { return (end() - 1); }
			const_reverse_iterator	rbegin() const { return (end() - 1); }
			reverse_iterator		rend() { return(begin() - 1); }
			const_reverse_iterator	rend() const { return(begin() - 1); }

			//Capacity
			size_type	size() const { return (_size); };
			size_type	max_size() const {
				size_type	max_size = ~0;

				typename allocator_type::size_type	_alloc_size = _alloc.max_size();
				return (max_size > _alloc_size ? _alloc_size : max_size);
			};
			void	resize(size_type n, value_type val = value_type()) {
				reserve(n); 
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
					{
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(_pointer  + i);
						_alloc.deallocate(_pointer, _capacity);
					}
					_pointer = new_pointer;
					_capacity = new_capacity;
				}
			}

			// Element access:
			reference	operator[](size_type n) { return (_pointer[n]); }
			const_reference operator[] (size_type n) const { return (_pointer[n]); }
			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("vector");
				return ((*this)[n]); 
			}
			const_reference at (size_type n) const { 
				if (n >= _size)
					throw std::out_of_range("vector");
				return ((*this)[n]); 
			}
		    reference front() { return (*_pointer); }
			const_reference front() const { return (*_pointer); }
			reference back() { return (_pointer[_size - 1]); }
			const_reference back() const { return (_pointer[_size - 1]); }

			//Modifiers
			template <class InputIterator>
 				 void assign (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
				size_type	new_size = 0;

				for (InputIterator it = first; it != last; it++)
					new_size++;
				reserve(new_size);
				size_type i = 0;
				for (InputIterator it = first; it != last; it++)
					_alloc.construct(_pointer + i++, *it);
				_size = new_size;
			}
			void	assign(size_type n, const value_type &val) {
				resize(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_pointer + i, val);
			}
			void	push_back(const value_type &val) {
				reserve(_size + 1);
				_alloc.construct(_pointer + _size, val);
				_size++;
			}
			void	pop_back() {
				_alloc.destroy(_pointer + _size);
				_size--;
			}
			iterator	insert (iterator position, const value_type& val) {
				typename iterator::difference_type diff = position - begin();
				reserve(_size + 1);
				_size++;
				iterator new_position = begin() + diff;
				for (iterator it = end() - 1 ; it > new_position; it--)
					_alloc.construct(&(*it),*(it - 1));
				_alloc.construct(&(*new_position), val);
				return (new_position);
			}
			void insert (iterator position, size_type n, const value_type& val) {
				for (size_type i = 0; i < n; i++)
					position = insert(position, val);
			}
			template <class InputIterator>
    			void insert (iterator position, InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
						last--;
						first--;
						for (InputIterator it = last ; it != first ; it--)
					 		position = insert(position, *it);
				}
			iterator erase (iterator position) {
				return (erase(position, position + 1));
			}
			iterator erase (iterator first, iterator last) {
				typename iterator::difference_type diff = last - first;

				for (iterator it = first + diff; it != end(); it++)
					_alloc.construct(&(*(it - diff)), *(it));
				for (iterator it = end() - 1; it != (end() - diff); it--)
					_alloc.destroy(&(*(it)));
				_size -= last - first;
				return(first);
			}
			void swap (vector& x) {
				vector<value_type, allocator_type> tmp(*this);

				*this = x;
				x = tmp;
			}
			void clear() {
				while (_size)
					_alloc.destroy(_pointer + _size--);
			}

			allocator_type get_allocator() const {
				return (_alloc);
			}
	};
template<typename T>
typename vector<T>::iterator
	operator+(typename vector<T>::iterator::difference_type n, typename vector<T>::iterator it) {
		return (it + n);
	}
//Relational operators
template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		else
			for (typename vector<T,Alloc>::size_type i = 0; i < lhs.size(); i++)
				if (lhs[i] != rhs[i])
					return (false);
		return (true);
  }
template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs==rhs));
  }
template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T,Alloc>::size_type i = 0;
		while (i < lhs.size() && i < rhs.size() && lhs[i] == rhs[i])
			i++;
		if ((i == lhs.size() && lhs.size() != rhs.size()) || (lhs[i] < rhs[i] && i != lhs.size()))
			return (true);
		else
			return (false);
  }
template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ((lhs == rhs || lhs < rhs));
	  }
template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs <= rhs));
	}
template <class T, class Alloc>
	bool operator>=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}
template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	  x.swap(y);
  }
}
#endif