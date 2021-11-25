
#ifndef REDBLACKBINARYTREE_H
# define REDBLACKBINARYTREE_H

# include <memory> //std::allocator


# define BLACK 0
# define RED 1

namespace ft {
    template < class value_type >
	class	Tree {
        public:
            //
            struct leaf
            {
                leaf(value_type &value): key(value) {}
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
        private :
            leaf_pointer    root;
            leaf_allocator_type    _leaf_alloc;
        public :
            Tree():root(NULL){};
            leaf_pointer	newleaf(value_type &value, bool color) {
                leaf	new_leaf(value);
                new_leaf.left = NULL;
                new_leaf.right = NULL;
                new_leaf.color = color;
                leaf_pointer pointer = _leaf_alloc.allocate(1);
                _leaf_alloc.construct(pointer, new_leaf);
                return(pointer);
            }

            leaf_pointer	add_leaf(value_type value)
			{
				if (!root)
                { 
                    root = newleaf(value, BLACK);
                    return (root);
                }
                leaf_pointer	iter = root;
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
                    prev->left = newleaf(value, RED);
                else if (value.first > prev->key.first)
                    prev->right = newleaf(value, RED);
                return (prev);
            }
        };
}

#endif