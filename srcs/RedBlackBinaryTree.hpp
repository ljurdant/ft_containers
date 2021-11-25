
#ifndef REDBLACKBINARYTREE_H
# define REDBLACKBINARYTREE_H

# include <memory> //std::allocator


# define BLACK 0
# define RED 1

namespace ft {
    template < class value_type >
	struct	leaf {        
        leaf(value_type &value): key(value) {}
        value_type	key;
        leaf		*left;
        leaf		*right;
        bool		color;
    };

 
    template < class leaf,  class alloc = std::allocator<leaf> >
    typename alloc::pointer newleaf(value_type &value, bool color, alloc _leaf_alloc) {
        leaf	new_leaf(value);
        new_leaf.left = NULL;
        new_leaf.right = NULL;
        new_leaf.color = color;
        alloc::pointer pointer = _leaf_alloc.allocate(1);
        _leaf_alloc.construct(pointer, new_leaf);
        return(pointer);
    }
}

#endif