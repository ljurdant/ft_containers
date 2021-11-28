
#ifndef REDBLACKBINARYTREE_H
# define REDBLACKBINARYTREE_H

# include <memory> //std::allocator


# define BLACK 0
# define RED 1

namespace ft {
    template <class value_type>
    struct leaf
    {
        leaf(value_type &value): _value(value) {}
        value_type	_value;
        leaf        *parent;
        leaf		*left;
        leaf		*right;
        bool		color;
    };

    template < class value_type, class alloc = std::allocator<leaf <value_type> > >
	class	Tree {
        public:
            typedef leaf<value_type>                                node_type;
            typedef alloc                                           leaf_allocator_type;
            typedef typename leaf_allocator_type::reference			leaf_reference;
            typedef typename leaf_allocator_type::const_reference	leaf_const_reference;
            typedef typename leaf_allocator_type::pointer			leaf_pointer;
            typedef typename leaf_allocator_type::const_pointer		leaf_const_pointer;
        private :
            leaf_pointer    _root;
            leaf_allocator_type    _leaf_alloc;
        public :
            Tree():_root(NULL){};
            leaf_pointer	newleaf(value_type &value, leaf_pointer parent, bool color) {
                node_type	new_leaf(value);
                new_leaf.left = NULL;
                new_leaf.right = NULL;
                new_leaf.parent = parent;
                new_leaf.color = color;
                leaf_pointer pointer = _leaf_alloc.allocate(1);
                _leaf_alloc.construct(pointer, new_leaf);
                return(pointer);
            }

            leaf_pointer	add_leaf(value_type value)
			{
                leaf_pointer	iter = _root;
				leaf_pointer    new_leaf;
                leaf_pointer    prev;
                if (!_root)
                { 
                    _root = newleaf(value, NULL, BLACK);
                    return (_root);
                }
                while (iter && iter->_value.first != value.first)
                {
                    prev = iter;
                    if (value.first < iter->_value.first)
                        iter = iter->left;
                    else if (value.first > iter->_value.first)
                        iter = iter->right;
                }
                if (iter)
                    new_leaf = iter;
                else
                {   
                    new_leaf = newleaf(value, prev, RED);
                    if (value.first < prev->_value.first)
                        prev->left = new_leaf;
                    else if (value.first > prev->_value.first)
                        prev->right = new_leaf;
                }
                return (new_leaf);
            }

            void    leftrotate(leaf_pointer x) {
                leaf_pointer y = x->right;
                x->right = NULL;
                y->parent = x->parent;
                y->left = x;
                if (!y->parent)
                    _root = y;
            }

            void    printLeaf(leaf_pointer leaf)
            {
                int count = 10;
                // int level = 0;
                leaf_pointer    iter = leaf->parent;
                leaf_pointer    tmp = leaf;
                while (iter)
                {
                    if (tmp == iter->right)
                        count++;
                    if (tmp == iter->left)
                        count--;
                    tmp = iter;    
                    iter = iter->parent;
                    // level++;
                }
                for (int i = 0; i < count; i++)
                    std::cout << "    ";
                if (leaf->color == RED)
                    std::cout << "\033[0;41m";
                else
                    std::cout << "\033[0;40m";
                std::cout << "(" << leaf->_value.first << ")" ;
                std::cout << "\033[0;m";
            }

            void    printBranches(leaf_pointer  leaf)
            {   
                // if (leaf)
                // {
                    if (!leaf->parent)
                    {
                        printLeaf(leaf);
                        std::cout << std::endl;
                    }
                    leaf_pointer    iter = leaf->parent;
                    leaf_pointer    tmp = leaf;

                    if (leaf->left)
                        printLeaf(leaf->left);
                    if (leaf->right)
                        printLeaf(leaf->right);
                    while (iter && tmp == iter->right)
                    {
                        tmp = iter;
                        iter = iter->parent;
                    }
                    if (!iter)
                        std::cout << std::endl;
                    if (leaf->left)
                        printBranches(leaf->left);
                    if (leaf->right)
                        printBranches(leaf->right);
                // }
            }

            void    printTree() {
                printBranches(_root);
            
            }
        };
}

#endif