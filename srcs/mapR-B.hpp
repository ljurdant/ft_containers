# ifndef MAP_H
# define MAP_H

# include <memory> //std::allocator
# include <iterator> //std::iterator_traits
# include <iostream>
# include "wrap_iter.hpp"
# include "ft_utilities.hpp"
# include "RedBlackBinaryTree.hpp"
# define BLACK 0
# define RED 1

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
		class map {
			public:
				typedef	Key																key_type;
				typedef T																mapped_type;
				typedef pair<const key_type, mapped_type>								value_type;
				typedef	Compare															key_compare;
				typedef	Alloc															allocator_type;
				typedef typename allocator_type::reference								reference;
				typedef typename allocator_type::const_reference						const_reference;
				typedef typename allocator_type::pointer								pointer;
				typedef typename allocator_type::const_pointer							const_pointer;
				typedef	std::iterator_traits<pointer>									iterator_traits;
				typedef	typename iterator_traits::difference_type						difference_type;
				typedef	size_t															size_type;
				class value_compare: public std::binary_function<value_type,value_type,bool> {
					friend class map;
					protected:
						Compare comp;
						value_compare	(Compare c): comp(c) {};

					public:
						typedef	bool result_type;
						typedef value_type	first_argument_type;
						typedef value_type	second_argument_type;
						value_compare	(value_compare const & c): comp(c.comp) {};
						bool	operator() (const value_type &x, const value_type &y) const
						{
							return comp(x.first, y.first);
						}
				};
				typedef	Tree<value_type, key_compare>												tree_type;
				typedef __wrap_biiter< typename tree_type::iterator >		iterator;
				typedef	__wrap_biiter<const typename tree_type::iterator>	const_iterator;
				typedef	__wrap_reverse_biiter<iterator>												reverse_iterator;
			protected:
				allocator_type		_alloc;
				key_compare			_key_compare;
				value_compare		_value_compare;
				size_type			_size;
				pointer				_pointer;
				size_type const		_max_size;
			public:
				tree_type	_tree;

			//Constructors
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _key_compare(comp), _value_compare(_key_compare), _size(0), _max_size(max_size())
					, _tree(_key_compare){
				}
				template <class InputIterator>
  					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _key_compare(comp), _value_compare(_key_compare), _size(0), _max_size(max_size()){
						insert(first, last);
				}
				// map (const map& x): _value_compare(x._value_compare),_size(0), _max_size(x.max_size()) {
				// 	*this = x;
				// }
				~map() {
					erase(begin(), end());
				}
				// map& operator= (const map& x) {
				// 	this->~map();
				// 	return (*this);
				// }

			// //Iterators
				iterator begin() { 
					typename tree_type::iterator	tree_it(_tree.getBegin());
					iterator						it(tree_it);
					return (it); 
				}
				const_iterator begin() const { return (_pointer); }
				iterator end() {
					typename tree_type::iterator	tree_it(NULL, _tree.getLast());
					iterator						it(tree_it);
					return (it);
				}
				const_iterator end() const { 
					typename tree_type::iterator	tree_it(NULL, _tree.getLast());
					const_iterator					it(tree_it);
					return (it);
				}
				reverse_iterator	rbegin() { return (end() - 1); }
				reverse_iterator	rend() { return (begin()); }
			// //Capacity
				bool empty() const { return (!_size); }
				size_type size() const { return (_size); }
				size_type	max_size() const {
					size_type	max_size = ~0;

					typename allocator_type::size_type	_alloc_size = _alloc.max_size();
					return (max_size > _alloc_size ? _alloc_size : max_size);
				};
			// //Element access
				mapped_type& operator[] (const key_type& k) {
					if (find(k) == end())
						_size++;
					leaf<value_type>	*node = _tree.add_leaf(ft::make_pair(k, mapped_type()));
					return (node->_value.second);	
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
			iterator insert (iterator position, const value_type& val) {
				(void)position;
				return (insert(val).first);
			}

			template <class InputIterator>
				void insert (InputIterator first, InputIterator last) {
					for (InputIterator  it = first; it != last; it++)
						insert(*it);
				}
			void erase (iterator position) {
				erase(position, ++position);
			}
			void erase (iterator first, iterator last) {
				iterator 	it = first;
				iterator	tmp;
				size_type	difference = 0;
				for (iterator ite = first; ite != last; ite++)
					difference++;

				for (size_type i = 0; i < difference; i++)
				{
					tmp = it;
					if (i != difference - 1)
						it++;
					key_type	k((*it).first);
					std::cout << "here = " << (*tmp).first << std::endl;
					_tree.deleteNode(*tmp);
					if (i != difference -1)
						it = find(k);
				}
				_size -= difference;
			}
			// void swap (map& x) {
			// 	map<key_type, mapped_type, key_compare, allocator_type> tmp(*this);
			// 	*this = x;
			// 	x = tmp;
			// }
			// void	clear() {
			// 	*this = map();
			// }
			// //Observers
				key_compare key_comp() const { return (_key_compare); }

			// //Operations
				iterator find (const key_type& k) {
					typename tree_type::iterator	tree_it(_tree.find(k), NULL);
					iterator	it(tree_it);
					return (it);
				}
				const_iterator find (const key_type& k) const{
					typename tree_type::iterator	tree_it(_tree.find(k), NULL);
					const_iterator	it(tree_it);
					return (it);
				}
			// 	size_type count (const key_type& k) const {
			// 		if (find(k) != end())
			// 			return(1);
			// 		return(0);
			// 	}
			// 	iterator lower_bound (const key_type& k) {
			// 		iterator	it = begin();
			// 		while (it != end() && _key_compare(it->first, k))
			// 			it++;
			// 		return (it);
			// 	}
			// 	const_iterator lower_bound (const key_type& k) const {
			// 		const_iterator	it = begin();
			// 		while (it != end() && _key_compare(it->first, k))
			// 			it++;
			// 		return (it);
			// 	}
			// 	iterator upper_bound (const key_type& k) {
			// 		iterator	it = begin();
			// 		while (it != end() && !_key_compare(k, it->first))
			// 			it++;
			// 		return (it);
			// 	}
			// 	const_iterator upper_bound (const key_type& k) const {
			// 		const_iterator	it = begin();
			// 		while (it != end() && !_key_compare(k, it->first))
			// 			it++;
			// 		return (it);
			// 	}
			// 	pair<iterator,iterator> equal_range (const key_type& k) {
			// 		return (make_pair(lower_bound(k),upper_bound(k)));
			// 	}
			// 	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			// 		return (make_pair(lower_bound(k),upper_bound(k)));
			// 	}
		};
}

#endif