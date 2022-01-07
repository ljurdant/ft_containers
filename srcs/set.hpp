# ifndef SET_H
# define SET_H

# include <memory> //std::allocator
# include <iterator> //std::iterator_traits
# include <iostream>
# include "wrap_iter.hpp"
# include "ft_utilities.hpp"
# include "setTree.hpp"
# define BLACK 0
# define RED 1

namespace ft {
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > 
		class set {
			public:
				typedef	T													key_type;
				typedef T					                                value_type;
				typedef	Compare												key_compare;
                typedef	Compare												value_compare;
				typedef	Alloc												allocator_type;
				typedef typename allocator_type::reference					reference;
				typedef typename allocator_type::const_reference			const_reference;
				typedef typename allocator_type::pointer					pointer;
				typedef typename allocator_type::const_pointer				const_pointer;
				typedef	size_t												size_type;

			private:
                typedef	typename allocator_type::template rebind<ft::leaf<value_type> >::other	leaf_allocator;
				typedef	setTree<value_type, key_compare, leaf_allocator>							tree_type;
                typedef	setTree<const value_type, key_compare>						                const_tree_type;

			public:
				typedef __wrap_biiter<typename tree_type::iterator, const_tree_type>		iterator;
				typedef	__wrap_biiter<typename const_tree_type::iterator, const_tree_type >	const_iterator;
				typedef	__wrap_reverse_biiter<iterator, const_tree_type>					reverse_iterator;
				typedef	__wrap_reverse_biiter<const_iterator, const_tree_type>				const_reverse_iterator;
				typedef	ft::iterator_traits<iterator>										iterator_traits;
				typedef	typename iterator_traits::difference_type							difference_type;
			protected:
				allocator_type		_alloc;
				key_compare			_key_compare;
				value_compare		_value_compare;
				size_type			_size;
				// pointer				_pointer;
				size_type const		_max_size;
				tree_type	_tree;

			public:
			//Constructors
				explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _key_compare(comp), _value_compare(_key_compare), _size(0), _max_size(max_size())
					, _tree(_key_compare){
				}
				template <class InputIterator>
  					set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _key_compare(comp), _value_compare(_key_compare), _size(0), _max_size(max_size()), _tree(_key_compare) {
						insert(first, last);
				}
				set (const set& x): _value_compare(x._value_compare), _size(0), _max_size(x.max_size()), _tree(_key_compare) {
					*this = x;
				}
				~set() {}
				set& operator= (const set& rhs) {
					clear();
					_tree = rhs._tree;
					_alloc = rhs._alloc;
					_key_compare = rhs._key_compare;
					_value_compare = rhs._value_compare;
					_size = rhs._size;
					return (*this);
				}

			// //Iterators
				iterator begin() { 
					return (iterator(typename tree_type::iterator(_tree.getBegin()))); 
				}
				const_iterator begin() const { 
                    return (const_iterator(typename tree_type::iterator(_tree.getBegin())));  
				 }
				iterator end() {
                    return (iterator(typename tree_type::iterator(NULL, _tree.getLast()))); 
				}
				const_iterator end() const { 
                    return (const_iterator(typename tree_type::iterator(NULL, _tree.getLast()))); 
				}
				reverse_iterator	rbegin() {
					return (end()); 
				 }
				const_reverse_iterator	rbegin() const {
					return (end()); 
				}
				reverse_iterator	rend() { 
					return (begin());
				}
				const_reverse_iterator	rend() const { 
					return (begin());
				}
			// //Capacity
				bool empty() const { return (!_size); }
				size_type size() const { return (_size); }
				size_type	max_size() const {
					size_type	max_size = ~0;

					typename allocator_type::size_type	_alloc_size = _alloc.max_size();
					return (max_size > _alloc_size ? _alloc_size : max_size);
				};

			//Modifiers
			pair<iterator,bool> insert (const value_type& val) {
				bool	exists;
				
				exists = find(val) == end();
				if (exists)
				{
                    _size++;
					_tree.add_leaf(val);
                }	
				iterator	it = find(val);
				return (pair<iterator, bool>(it, exists));
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
			size_type erase (const key_type& k) {
				bool	exists;
				exists = find(k) != end();
				if (exists)
                {
                    _tree.deleteNode(k);
                    _size--;
                }
				return (exists);
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
					key_type	k(*it);
                    erase(*tmp);
					if (i != difference -1)
						it = find(k);
				}
			}
			void swap (set& x) {
				allocator_type	tmp_alloc = _alloc;
				size_type		tmp_size = _size;

				_alloc = x._alloc;
				_size = x._size;
				x._alloc = tmp_alloc;
				x._size = tmp_size;
				_tree.swap(x._tree);
			}
			void	clear() {
				_tree.clear();
				_size = 0;
			}
			//Observers
				key_compare key_comp() const { return (_key_compare); }
				value_compare value_comp() const { return (_value_compare); }

			//Operations
				iterator find (const key_type& k) {
					typename tree_type::iterator	tree_it(_tree.find(k));
					iterator	it(tree_it);
					return (it);
				}
				const_iterator find (const key_type& k) const{
					// std::cout << k << std::endl;
					typename tree_type::iterator	tree_it(_tree.find(k));
					const_iterator	it(tree_it);
					return (it);
				}
				size_type count (const key_type& k) const {
					if (find(k) != end())
						return(1);
					return(0);
				}
				iterator lower_bound (const key_type& k) {
					iterator	it = begin();
					while (it != end() && _key_compare(*it, k))
						it++;
					return (it);
				}
				const_iterator lower_bound (const key_type& k) const {
					const_iterator	it = begin();
					while (it != end() && _key_compare(*it, k))
						it++;
					return (it);
				}
				iterator upper_bound (const key_type& k) {
					iterator	it = begin();
					while (it != end() && !_key_compare(k, *it))
						it++;
					return (it);
				}
				const_iterator upper_bound (const key_type& k) const {
					const_iterator	it = begin();
					while (it != end() && !_key_compare(k, *it))
						it++;
					return (it);
				}
				pair<iterator,iterator> equal_range (const key_type& k) {
					return (ft::make_pair(lower_bound(k),upper_bound(k)));
				}
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
					return (ft::make_pair(lower_bound(k),upper_bound(k)));
				}
		};
	template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			if (lhs.size() != rhs.size())
				return (false);
			else
			for (typename ft::set<T,Compare,Alloc>::const_iterator it = lhs.begin(), it2 = rhs.begin(); it != lhs.end(); it++, it2++)
				if (*it != *it2)
					return (false);
			return (true);
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (!(lhs == rhs));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<= (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs) {
			return ((lhs == rhs || lhs < rhs));
		}
	template< class Key, class T, class Compare, class Alloc >
		bool operator>  (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs) {
			return (!(lhs <= rhs));
		}
	template< class Key, class T, class Compare, class Alloc >
		bool operator>=  (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs) {
			return (!(lhs < rhs));
		}
}

#endif