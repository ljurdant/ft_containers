# ifndef MAP_H
# define MAP_H

# include <memory> //std::allocator
# include <iterator> //std::iterator_traits
# include "wrap_iter.hpp"
# include "ft_utilities.hpp"
# define BLACK 0
# define RED 1

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
		class map {
			public:
				typedef	Key											key_type;
				typedef T											mapped_type;
				typedef pair<const key_type, mapped_type>			value_type;
				typedef	Compare										key_compare;
				typedef	Alloc										allocator_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;
				typedef	std::iterator_traits<pointer>				iterator_traits;
				typedef __wrap_biiter<pointer>						iterator;
				typedef	__wrap_biiter<const_pointer>				const_iterator;
				typedef	__wrap_reverse_biiter<iterator>				reverse_iterator;
				typedef	typename iterator_traits::difference_type	difference_type;
				typedef	size_t										size_type;
				class value_compare: public std::binary_function<value_type,value_type,bool> {
					friend class map;
					protected:
						Compare comp;
						value_compare	(Compare c): comp(c) {};

					public:
						typedef	bool result_type;
						typedef value_type	first_argument_type;
						typedef value_type	second_argument_type;
						bool	operator() (const value_type &x, const value_type &y) const
						{
							return comp(x.first, y.first);
						}
				};
			protected:
				allocator_type	_alloc;
				key_compare		_key_compare;
				value_compare	_value_compare;
				size_type		_size;
				pointer			_pointer;
				size_type const	_max_size;
				struct	leaf {
							value_type	key;
							leaf		*left;
							leaf		*right;
							bool		color;
				};
				typedef	std::allocator<leaf>	leaf_allocator_type;
				typedef typename leaf_allocator_type::reference			leaf_reference;
				typedef typename leaf_allocator_type::const_reference	leaf_const_reference;
				typedef typename leaf_allocator_type::pointer			leaf_pointer;
				typedef typename leaf_allocator_type::const_pointer		leaf_const_pointer;
				leaf_allocator_type				_leaf_alloc;
				leaf_pointer	Tree;
				leaf_pointer	newleaf(value_type const &value, bool &color) {
					leaf	new_leaf;
					new_leaf.key = value;
					new_leaf.left = NULL;
					new_leaf.right = NULL;
					new_leaf.color = color;
					leaf_pointer pointer = _leaf_alloc.allocate(1);
					_leaf_alloc.construct(pointer, new_leaf);
					return(pointer);
				}
				void	add_leaf(value_type const &value)
				{
					if (!Tree)
					{
						Tree = newleaf(value, BLACK);
						return ;
					}
					leaf_pointer	iter = Tree;
					leaf_pointer	prev = iter;
					while (iter && prev->key.first != value.first)
					{
						prev = iter;
						if (value.first < iter->key.first)
							iter = iter->left;
						else if (value.first > iter->key.first)
							iter = iter->right;
					}
					if (value.first < prev->key.first)
						prev->left = newleaf(value, RED)
					else if (value.first > prev->key.first)
						prev->right = newleaf(value, RED);
					else
						prev->key = value;
					
				}

			public:
			//Constructors
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _key_compare(comp), _value_compare(_key_compare), _size(0), _max_size(max_size()),Tree(NULL) {
				}
				template <class InputIterator>
  					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _key_compare(comp), _value_compare(_key_compare), _size(0), _max_size(max_size()), Tree(NULL) {
						for (InputIterator it = first; it != last; it++)
							insert(it);
				}
				map (const map& x): _value_compare(x._value_compare),_size(0), _max_size(x.max_size()), Tree(NULL) {
					*this = x;
				}
				~map() {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_pointer + i);
					if (_size)
						_alloc.deallocate(_pointer, _size);
					_size = 0;
				}
				map& operator= (const map& x) {
					this->~map();
					for (const_iterator it = x.begin(); it != x.end(); it++)
						insert(*it);
					_key_compare=x._key_compare;
					_value_compare=x._value_compare;
					_alloc=x._alloc;
					return (*this);
				}

			//Iterators
				iterator begin() { return (_pointer); }
				const_iterator begin() const { return (_pointer); }
				iterator end() { return (_pointer + _size); }
				const_iterator end() const { return (_pointer + _size); }
				reverse_iterator	rbegin() { return (end() - 1); }
				reverse_iterator	rend() { return (begin()); }
			//Capacity
				bool empty() const { return (!_size); }
				size_type size() const { return (_size); }
				size_type	max_size() const {
				size_type	max_size = ~0;

				typename allocator_type::size_type	_alloc_size = _alloc.max_size();
				return (max_size > _alloc_size ? _alloc_size : max_size);
			};
			//Element access
				mapped_type& operator[] (const key_type& k) {
					if (find(k) == end())
					{
						pointer	new_pointer;
						new_pointer = _alloc.allocate(_size + 1);
						iterator it = begin();
						size_type	i = 0;
						while(it != end() && _key_compare(it->first, k))
						{
							_alloc.construct(new_pointer + i, _pointer[i]);
							it++;
							i++;
						}
						_alloc.construct(new_pointer + i, ft::make_pair(k, mapped_type()));
						it++;
						i++;
						_size++;
						while (it != end())
						{							
							_alloc.construct(new_pointer + i, _pointer[i - 1]);
							it++;
							i++;
						}
						for (size_type i = 0; i < _size - 1; i++)
							_alloc.destroy(_pointer + i);
						if (_size - 1)
							_alloc.deallocate(_pointer, _size);
						_pointer = new_pointer;
					}
					return (find(k)->second);	
				}
			//Modifiers
				pair<iterator,bool> insert (const value_type& val) {
					bool	exists;
					
					exists = find(val.first) == end();
					if (exists)
						(*this)[val.first] = val.second;
					iterator	it = find(val.first);
					pair<iterator, bool> ret(it, exists);
					return (ret);
				}
			void erase (iterator position) {
				erase(position, ++position);
			}
			void erase (iterator first, iterator last) {
				size_type	diff = 0;
				for (iterator it = first; it != last; it++)
					diff++;
				pointer	new_pointer = _alloc.allocate(_size - diff);
				size_type	i = 0;
				for (iterator it = begin(); it != first; it++)
				{
					_alloc.construct(new_pointer + i, *it);
					i++;
				}
				for (iterator it = last; it != end(); it++)
				{
					_alloc.construct(new_pointer + i, *it);
					i++;
				}
				for (size_type i = 0; i < _size - 1; i++)
						_alloc.destroy(_pointer + i);
					if (_size - 1)
						_alloc.deallocate(_pointer, _size);
				_pointer = new_pointer;
				_size-=diff;
			}
			void swap (map& x) {
				map<key_type, mapped_type, key_compare, allocator_type> tmp(*this);
				*this = x;
				x = tmp;
			}
			void	clear() {
				*this = map();
			}
			//Observers
				key_compare key_comp() const { return (_key_compare); }

			//Operations
				iterator find (const key_type& k) {
					iterator	it = begin();
					while (it != end() && it->first != k)
						it++;
					return (it);
				}
				const_iterator find (const key_type& k) const{
					const_iterator	it = begin();
					while (it != end() && it->first != k)
						it++;
					return (it);
				}
				size_type count (const key_type& k) const {
					if (find(k) != end())
						return(1);
					return(0);
				}
				iterator lower_bound (const key_type& k) {
					iterator	it = begin();
					while (it != end() && _key_compare(it->first, k))
						it++;
					return (it);
				}
				const_iterator lower_bound (const key_type& k) const {
					const_iterator	it = begin();
					while (it != end() && _key_compare(it->first, k))
						it++;
					return (it);
				}
				iterator upper_bound (const key_type& k) {
					iterator	it = begin();
					while (it != end() && !_key_compare(k, it->first))
						it++;
					return (it);
				}
				const_iterator upper_bound (const key_type& k) const {
					const_iterator	it = begin();
					while (it != end() && !_key_compare(k, it->first))
						it++;
					return (it);
				}
				pair<iterator,iterator> equal_range (const key_type& k) {
					return (make_pair(lower_bound(k),upper_bound(k)));
				}
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
					return (make_pair(lower_bound(k),upper_bound(k)));
				}
		};
}

#endif