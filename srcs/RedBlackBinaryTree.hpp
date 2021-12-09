
#ifndef REDBLACKBINARYTREE_H
#define REDBLACKBINARYTREE_H

#include <memory> //std::allocator
#include <iostream>
#include <list>

#define BLACK 0
#define RED 1

namespace ft
{
    template <class value_type>
    struct leaf
    {
        leaf(value_type &value) : _value(value) {}
        value_type _value;
        leaf *parent;
        leaf *left;
        leaf *right;
        bool color;
    };

    template <class T, class Compare, class alloc = std::allocator<leaf<T> > >
    class Tree
    {
    public:
        typedef leaf<T> node_type;
        typedef alloc leaf_allocator_type;
        typedef typename leaf_allocator_type::reference leaf_reference;
        typedef typename leaf_allocator_type::const_reference leaf_const_reference;
        typedef typename leaf_allocator_type::pointer leaf_pointer;
        typedef typename leaf_allocator_type::const_pointer leaf_const_pointer;
        typedef Compare value_compare;

    protected:
        leaf_pointer _root;
        leaf_pointer _last;
        leaf_pointer _begin;
        leaf_allocator_type _leaf_alloc;
        value_compare _value_compare;

    public:
        Tree(value_compare comp) : _root(NULL), _last(NULL), _begin(NULL), _value_compare(comp){};

        leaf_pointer getLast() { return (_last); }
        leaf_pointer getBegin() { return (_begin); }
        leaf_pointer newleaf(T &value, leaf_pointer parent, bool color)
        {
            node_type new_leaf(value);
            new_leaf.left = NULL;
            new_leaf.right = NULL;
            new_leaf.parent = parent;
            new_leaf.color = color;
            leaf_pointer pointer = _leaf_alloc.allocate(1);
            _leaf_alloc.construct(pointer, new_leaf);
            if (!_last || value.first > _last->_value.first)
                _last = pointer;
            if (!_begin || value.first < _begin->_value.first)
                _begin = pointer;
            return (pointer);
        }

        leaf_pointer add_leaf(T value)
        {
            leaf_pointer iter = _root;
            leaf_pointer new_leaf;
            leaf_pointer prev;
            if (!_root)
            {
                _root = newleaf(value, NULL, BLACK);
                return (_root);
            }
            while (iter && iter->_value.first != value.first)
            {
                prev = iter;
                if (_value_compare(value, iter->_value))
                    iter = iter->left;
                else if (value.first != iter->_value.first && !_value_compare(value, iter->_value))
                    iter = iter->right;
            }
            if (iter)
            {
                new_leaf = iter;
                return (new_leaf);
            }
            else
            {
                new_leaf = newleaf(value, prev, RED);
                if (value.first < prev->_value.first)
                    prev->left = new_leaf;
                else if (value.first > prev->_value.first)
                    prev->right = new_leaf;
                return (checkLeaf(new_leaf));
            }
        }

        void leftrotate(leaf_pointer x)
        {
            leaf_pointer y = x->right;
            x->right = y->left;
            if (y->left)
                y->left->parent = x;
            y->parent = x->parent;
            if (!x->parent)
                _root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }

        void rightrotate(leaf_pointer x)
        {
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

        void printLeaf(leaf_pointer leaf)
        {
            if (leaf && leaf->color == RED)
                std::cout << "\033[0;41m";
            else
                std::cout << "\033[0;40m";
            if (leaf)
                std::cout << "(" << leaf->_value.first << ")";
            std::cout << "\033[0;m";
        }

        struct printNode
        {
            printNode(leaf_pointer l, int i) : leaf(l), indent(i) {}
            leaf_pointer leaf;
            int indent;
        };

        printNode makeprintNode(leaf_pointer l, int i) { return (printNode(l, i)); }

        void printIndent(int indent)
        {
            for (int i = 0; i < indent; i++)
                std::cout << " ";
        }

        std::list<printNode> printBranches(std::list<printNode> nodes, int level)
        {
            std::list<printNode> new_nodes;
            int cumulativeIndent = 0;
            for (typename std::list<printNode>::iterator it = nodes.begin(); it != nodes.end(); it++)
            {
                if ((*it).leaf->left)
                {
                    printIndent((*it).indent - level - cumulativeIndent);
                    new_nodes.push_back(makeprintNode((*it).leaf->left, (*it).indent - level));
                    printLeaf((*it).leaf->left);
                    cumulativeIndent += (*it).indent - level - cumulativeIndent + 3;
                }
                if ((*it).leaf->right)
                {
                    printIndent((*it).indent + level - cumulativeIndent);
                    new_nodes.push_back(makeprintNode((*it).leaf->right, (*it).indent + level));
                    printLeaf((*it).leaf->right);
                    cumulativeIndent += (*it).indent + level - cumulativeIndent + 3;
                }
            }
            return (new_nodes);
        }

        void printTree(int indent, int level)
        {
            std::list<printNode> nodes(1, makeprintNode(_root, indent));
            printIndent(indent);
            printLeaf(_root);
            std::cout << std::endl;
            while (nodes.size())
            {
                nodes = printBranches(nodes, level);
                level -= 3;
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        leaf_pointer checkLeaf(leaf_pointer node)
        {
            if (node->parent && node->parent->parent)
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
                            if (node == node->parent->left)
                            {
                                rightrotate(node->parent);
                                node = checkLeaf(node->right)->parent;
                            }
                            else
                            {
                                node->parent->parent->color = RED;
                                leftrotate(node->parent->parent);
                                node->parent->color = BLACK;
                            }
                        }
                        else if (node->parent == node->parent->parent->left)
                        {
                            if (node == node->parent->right)
                            {
                                leftrotate(node->parent);
                                node = checkLeaf(node->left)->parent;
                            }
                            else
                            {
                                node->parent->parent->color = RED;
                                rightrotate(node->parent->parent);
                                node->parent->color = BLACK;
                            }
                        }
                    }
                }
            }
            if (_root->color == RED)
                _root->color = BLACK;
            return (node);
        }


        void deleteLeaf(leaf_pointer leaf)
        {
            if (leaf->parent)
            {
                if (leaf == leaf->parent->left)
                {
                    if (leaf->left)
                    {
                        leaf->parent->left = leaf->left;
                        leaf->left->parent = leaf->parent;
                    }
                    else if (leaf->right)
                    {
                        leaf->parent->left = leaf->right;
                        leaf->right->parent = leaf->parent;
                    }
                    else
                        leaf->parent->left = NULL;
                }
                else
                {
                    if (leaf->left)
                    {
                        leaf->parent->right = leaf->left;
                        leaf->left->parent = leaf->parent;
                    }
                    else if (leaf->right)
                    {
                        leaf->parent->right = leaf->right;
                        leaf->right->parent = leaf->parent;
                    }
                    else
                        leaf->parent->right = NULL;
                }
            }
            else
            {
                if (leaf->left)
                {
                    _root = leaf->left;
                    leaf->left->parent = NULL;
                }
                else if (leaf->right)
                {
                    _root = leaf->right;
                    leaf->right->parent = NULL;
                }
                else
                    _root = NULL;
            }
            _leaf_alloc.destroy(leaf);
            _leaf_alloc.deallocate(leaf, 1);
        }

        class iterator
        {
        public:
            typedef T value_type;
            typedef size_t difference_type;
            typedef value_type &reference;
            typedef value_type *pointer;

        protected:
            leaf_pointer __i;
            leaf_pointer _prev;

        public:
            iterator() {}
            iterator(iterator const &copy) { *this = copy; }
            iterator &operator=(iterator const &rhs)
            {
                __i = rhs.__i;
                return (*this);
            }
            bool operator==(iterator const &rhs) const { return (__i == rhs.__i); }
            bool operator!=(iterator const &rhs) const { return (__i != rhs.__i); }
            reference operator*() const { return (__i->_value); }
            pointer operator->() const { return (&(__i->_value)); }
            iterator operator++(int)
            {
                if (__i && __i->right)
                {
                    _prev = __i;
                    __i = __i->right;
                    while (__i->left)
                        __i = __i->left;
                }
                else if (__i)
                {
                    _prev = __i;
                    while (__i->parent && __i == __i->parent->right)
                        __i = __i->parent;
                    __i = __i->parent;
                }
                return (*this);
            }
            iterator operator++()
            {
                if (__i && __i->right)
                {
                    _prev = __i;
                    __i = __i->right;
                    while (__i->left)
                        __i = __i->left;
                }
                else if (__i)
                {
                    _prev = __i;
                    while (__i->parent && __i == __i->parent->right)
                        __i = __i->parent;
                    __i = __i->parent;
                }
                return (*this);
            }
            iterator operator--(int)
            {
                if (__i && __i->left)
                {
                    __i = __i->left;
                    while (__i->right)
                        __i = __i->right;
                }
                else if (__i)
                {
                    while (__i->parent && __i == __i->parent->left)
                        __i = __i->parent;
                    __i = __i->parent;
                }
                else
                {
                    __i = _prev;
                }
                return (*this);
            }
            iterator operator--()
            {
                if (__i && __i->left)
                {
                    __i = __i->left;
                    while (__i->right)
                        __i = __i->right;
                }
                else if (__i)
                {
                    while (__i->parent && __i == __i->parent->left)
                        __i = __i->parent;
                    __i = __i->parent;
                }
                else
                {
                    __i = _prev;
                }
                return (*this);
            }

            iterator(leaf_pointer const &p) : __i(p) {}
        };

        // void deleteNode(ft::map::iterator it)
        // {
        //     leaf_pointer leaf;
        //     leaf_pointer node = findLeaf(*it);

        //     if (!node->left || !node->right)
        //         leaf = node;
        //     else
        //     {
        //         leaf = node->right;
        //         while (leaf->left)
        //             leaf = leaf->left;
        //         node->value = leaf->value;
        //     }
        //     deleteLeaf(leaf);
        // }
        leaf_pointer findLeaf(T value)
        {
            leaf_pointer iter = _root;

            while (iter->_value != value)
            {
                if (iter && iter->right)
                {
                    iter = iter->right;
                    while (iter->left)
                        iter = iter->left;
                }
                else if (iter)
                {
                    while (iter->parent && iter == iter->parent->right)
                        iter = iter->parent;
                    iter = iter->parent;
                }
            }
            return (iter);
        }
    };
}

#endif