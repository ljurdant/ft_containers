
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
                return (checkLeaf(new_leaf));
            }

            void    leftrotate(leaf_pointer x) {
                leaf_pointer y = x->right;
                x->right = y->left;
                if (y->left)
                    y->left->parent = x;
				y->parent= x->parent;
                if (!x->parent)
                    _root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->left = x;
                x->parent = y;
            }

			void    rightrotate(leaf_pointer x) {
                leaf_pointer y = x->left;
                x->left = y->right;
				if (y->right)
                    y->right->parent = x;
                y->parent = x->parent;
                if (!x->parent)
                    _root = y;
                else if (x == x->parent->right)
                    x->parent->right = y;
                else
                    x->parent->right = y;
                y->right = x;
                x->parent = y;
            }

			void	recolor(leaf_pointer x) {
				if (x->color == RED)
					x->color = BLACK;
				else
					x->color = RED;
			}

            void    printLeaf(leaf_pointer leaf)
            {
                if (leaf->color == RED)
                    std::cout << "\033[0;41m";
                else
                    std::cout << "\033[0;40m";
                std::cout << "(" << leaf->_value.first << ")" ;
                std::cout << "\033[0;m";
            }

			void	printIndent(int indent) {
				for (int i = 0; i < indent; i++)
					std::cout << " ";
			}

            void    printBranches(leaf_pointer  leaf, int indent, int level)
            {   
                // if (leaf)
                // {
                    if (!leaf->parent)
                    {
						printIndent(indent);
                        printLeaf(leaf);
                        std::cout << std::endl;
                    }
                    leaf_pointer    iter = leaf->parent;
                    leaf_pointer    tmp = leaf;

                    if (leaf->left)
					{
						printIndent(indent - level);
                        printLeaf(leaf->left);
					}
                    if (leaf->right)
                    {
						printIndent((leaf->left ? 2*level - 3: indent + level));
						printLeaf(leaf->right);
					}
					while (iter && tmp == iter->right)
                    {
                        tmp = iter;
                        iter = iter->parent;
                    }
                    if (!iter)
                        std::cout << std::endl;
                    if (leaf->left)
                        printBranches(leaf->left, indent - level, level - 2);
                    if (leaf->right)
                        printBranches(leaf->right, indent + level, level - 2);
                // }
            }

            void    printTree(int indent, int level) {
                printBranches(_root, indent, level);
                std::cout << std::endl;
            }

            void    blackUncle(void (*rotate1)(leaf_pointer), void (*rotate2)(leaf_pointer), leaf_pointer node, std::string dir)
            {
                if ((dir == "right" && node == node->parent->left)
                || (dir == "left" && node == node->parent->right))
                {
                    rotate1(node->parent);
                    blackUncle(rotate1, rotate2, dir);
                }
                node->parent->parent->color = RED;
                rotate2(node->parent->parent);
                node->parent->color = BLACK;      
            }
			leaf_pointer	checkLeaf(leaf_pointer node) {
				
				if (node->parent->parent)
				{
				leaf_pointer uncle;
					if (node->parent->parent->right == node->parent)
						uncle = node->parent->parent->left;
					else
						uncle = node->parent->parent->right;
					if (node->parent->color == RED)
					{
						if (uncle && uncle->color == RED)
						{
							node->parent->color = BLACK;
							uncle->color = BLACK;
							node->parent->parent->color = RED;
						}
						else if (!uncle || uncle->color == BLACK)
						{
							if (node->parent == node->parent->parent->right)
							{
                                // blackUncle(leftrotate, rightrotate, node,"right");
                                if (node == node->parent->left)
                                {
                                    rightrotate(node->parent);
                                    return (checkLeaf(node));
                                }
                                node->parent->parent->color = RED;
                                leftrotate(node->parent->parent);
                                node->parent->color = BLACK;
							}
                            else if (node->parent == node->parent->parent->left)
                            {
                                // blackUncle(rightrotate, leftrotate, node, "left");
                                if (node == node->parent->right)
                                {
                                    leftrotate(node->parent);
                                    return (checkLeaf(node));
                                }
                                node->parent->parent->color = RED;
                                rightrotate(node->parent->parent);
                                node->parent->color = BLACK;
                            }
						}

					}
				}
                // while (node->parent && node->parent->color == RED)
                // {
                //     if (node->parent->parent && node->parent == node->parent->parent->right)
                //     {
                //         uncle = node->parent->parent->left;
                //         if (uncle->color && uncle->color == RED)
                //         {
                //             uncle->color = BLACK;
                //             node->parent->color = BLACK;
                //             node->parent->parent->color = RED;
                //             node = node->parent->parent;
                //         }
                //         else if (node == node->parent->left)
                //         {
                //             node = node->parent;
                //             leftrotate(node);
                //         }
                //         node->parent->color = BLACK;
                //         node->parent->parent->color = RED;
                //         rightrotate
                // }
				return (node);
			}
        };
}

#endif