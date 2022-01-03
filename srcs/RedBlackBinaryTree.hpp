
#ifndef REDBLACKBINARYTREE_H
#define REDBLACKBINARYTREE_H

#include <memory> //std::allocator
#include <iostream>
#include <list>
#include "ft_utilities.hpp"

#define BLACK 0
#define RED 1

namespace ft
{
 template <class value_type>
    struct leaf
    {
        leaf(value_type &value) : _value(value) {}
        leaf() : parent(NULL), left(NULL), right(NULL), color(BLACK), _value(value_type()) {}
        leaf(leaf const & copy) : _value(copy._value), parent(copy.parent), left(copy.left), right(copy.right), color(copy.color){}
        leaf(leaf const & copy, value_type value) : _value(value), parent(copy.parent), left(copy.left), right(copy.right), color(copy.color){}
        leaf & operator=(leaf &rhs) {
            new (this) leaf(rhs);
            return (*this);
        }
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
        typedef Compare key_compare;
        class value_compare: public std::binary_function<T,T,bool> {
            friend class Tree;
            protected:
                Compare comp;
                value_compare	(Compare c): comp(c) {};

            public:
                typedef	bool result_type;
                typedef T	first_argument_type;
                typedef T	second_argument_type;
                value_compare	(value_compare const & c): comp(c.comp) {};
                bool	operator() (const T &x, const T &y) const
                {
                    return comp(x.first, y.first);
                }
        };

    protected:
        leaf_pointer        _root;
        leaf_allocator_type _leaf_alloc;
        key_compare _key_compare;
        value_compare _value_compare;


    public:
        
        Tree(key_compare comp) : _root(NULL), _key_compare(comp), _value_compare(_key_compare){};
        Tree(Tree const & copy) : _root(NULL), _key_compare(copy._key_compare), _value_compare(copy._value_compare){
            *this = copy;
        }
        ~Tree() {
            clear();
        }
        Tree    & operator=(Tree const & rhs) {
            clear();
            _key_compare = rhs._key_compare;
            _value_compare = rhs._value_compare;
            iterator    end(NULL, rhs.getLast());
            for (iterator it = rhs.getBegin() ; it != end; it++)
                add_leaf(*it);
            return (*this);
        }

        void    clear() {
            while (_root != NULL)
                deleteNode(_root->_value);
        }

        leaf_pointer getLast() const{ 
            leaf_pointer leaf = _root;
            if (!_root)
                return (_root);
            while (leaf->right)
                leaf = leaf->right;
            return (leaf); 
        }
        leaf_pointer getBegin() const{ 
            leaf_pointer leaf = _root;
            if (!_root)
                return (_root);
            while (leaf->left)
                leaf = leaf->left;
            return (leaf); 
         }
        leaf_pointer newleaf(T &value, leaf_pointer parent, bool color)
        {
            node_type new_leaf(value);
            new_leaf.left = NULL;
            new_leaf.right = NULL;
            new_leaf.parent = parent;
            new_leaf.color = color;
            leaf_pointer pointer = _leaf_alloc.allocate(1);
            _leaf_alloc.construct(pointer, new_leaf);
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
            if (getColor(leaf) == RED)
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
            if (!_root)
                return ;
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

        bool    getColor(leaf_pointer leaf)
        {
            if (!leaf)
                return (BLACK);
            else
                return (leaf->color);
        }

        leaf_pointer checkLeaf(leaf_pointer node)
        {
            if (node->parent && node->parent->parent)
            {
                leaf_pointer    uncle;
                if (node->parent->parent->right == node->parent)
                    uncle = node->parent->parent->left;
                else
                    uncle = node->parent->parent->right;
                if (node->parent->color == RED)
                {
                    if (getColor(uncle) == RED)
                    {
                        node->parent->color = BLACK;
                        uncle->color = BLACK;
                        node->parent->parent->color = RED;
                    }
                    else if (getColor(uncle) == BLACK)
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



        class iterator
        {
        public:
            typedef T value_type;
            typedef size_t difference_type;
            typedef value_type &reference;
            typedef value_type *pointer;
            typedef ft::bidirectional_iterator_tag  iterator_category;

        protected:
            leaf_pointer __i;
            leaf_pointer _prev;

        public:
            iterator() {}
            iterator(iterator const &copy) { *this = copy; }
            iterator &operator=(iterator const &rhs)
            {
                __i = rhs.__i;
                _prev = rhs._prev;
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
                    if (_prev == __i)
                        __i = NULL;
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
                    __i = _prev;
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
                    __i = _prev;
                return (*this);
            }

            iterator(leaf_pointer const &p, leaf_pointer const &prev  = NULL) : __i(p), _prev(prev) {}
        };

        leaf_pointer    swapnodes(leaf_pointer a, leaf_pointer b) {
            leaf<T> acopy(*a, b->_value);
            leaf<T> bcopy(*b, a->_value);

            *b = bcopy;
            *a = acopy;
            if (!a->parent)
                _root = a;
            if (!b->parent)
                _root = b;
            return (b);
        }

        leaf_pointer    getSibling(leaf_pointer leaf)
        {
            leaf_pointer    sibling;

            if (leaf->parent->left && leaf == leaf->parent->left)
                sibling = leaf->parent->right;
            else
                sibling = leaf->parent->left;
            return (sibling);
        }

        void    deleteCheck(leaf_pointer leaf)
        {
            leaf_pointer    sibling;

            if (leaf == _root)
                return ;
            sibling = getSibling(leaf);
            if (sibling && sibling == leaf->parent->right)
            {
                if (getColor(sibling) == RED)
                {
                    sibling->color = BLACK;
                    leaf->parent->color = RED;
                    leftrotate(leaf->parent);
                    sibling = leaf->parent->right;
                }
                if (sibling && sibling->color == BLACK)
                {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK)
                    {
                        sibling->color = RED;
                        if (leaf->parent->color == RED)
                            leaf->parent->color = BLACK;
                        else
                            deleteCheck(leaf->parent);
                    }
                    else if (getColor(sibling->left) == RED && getColor(sibling->right) == BLACK)
                    {
                        sibling->color = RED;
                        sibling->left->color = BLACK;
                        rightrotate(sibling->left);
                    }
                    else if (getColor(sibling->right) == RED)
                    {
                        sibling->right->color = BLACK;
                        leaf->parent->color = BLACK;
                        leftrotate(leaf->parent);
                        if (leaf->parent->parent)
                            leaf->parent->parent->color = RED;
                    }
                }
            }
            else if (sibling)
            {
                if (getColor(sibling) == RED)
                {
                    sibling->color = BLACK;
                    leaf->parent->color = RED;
                    rightrotate(leaf->parent);
                    sibling = leaf->parent->left;
                }
                sibling = getSibling(leaf);
                if (getColor(sibling) == BLACK)
                {
                    if (getColor(sibling->right) == BLACK && getColor(sibling->left) == BLACK)
                    {
                        sibling->color = RED;
                        if (leaf->parent->color == RED)
                            leaf->parent->color = BLACK;
                        else
                            deleteCheck(leaf->parent);
                    }
                    else if (getColor(sibling->right) == RED && getColor(sibling->left) == BLACK)
                    {
                        sibling->color = RED;
                        sibling->right->color = BLACK;
                        leftrotate(sibling->right);
                    }
                    else if (getColor(sibling->left) == RED)
                    {
                        sibling->left->color = BLACK;
                        leaf->parent->color = BLACK;
                        leftrotate(leaf->parent);
                        if (leaf->parent->parent)
                            leaf->parent->parent->color = RED;
                    }
                }
            }
        }
  
        void    deleteLeaf(leaf_pointer leaf)
        {
            leaf_pointer    child;
              
            child = NULL;
            if (leaf->left)
                child = leaf->left;
            else if(leaf->right)
                child = leaf->right;
            if (child)
                child->parent = leaf->parent;
            if (leaf->parent)
            {
                if (leaf->parent->left == leaf)
                {
                    if (child)
                        leaf->parent->left = child;
                    else
                        leaf->parent->left = NULL;
                }
                else
                {
                    if (child)
                        leaf->parent->right = child;
                    else
                        leaf->parent->right = NULL;
                }
            }
            else
            {
                if (child)
                    child->parent = NULL;
                _root = child;
            }
            _leaf_alloc.destroy(leaf);
            _leaf_alloc.deallocate(leaf, 1);
        }

        void deleteNode(T value)
        {
            leaf_pointer    leaf = NULL;
            leaf_pointer    node;

            node = findLeaf(value);
            leaf = node;
            if (node->left && node->right)
            {
                leaf = node->right;
                while (leaf->left)
                    leaf = leaf->left;
                swapnodes(leaf, node);
            }
            if (leaf->color == BLACK)
            {
                if (leaf->left && leaf->left->color == RED)
                    leaf->left->color = BLACK;
                else if (leaf->right && leaf->right->color == RED)
                {
                    leaf->right->color = BLACK;
                }
                else
                    deleteCheck(leaf);
            }
            deleteLeaf(leaf);
        }

        leaf_pointer findLeaf(T value)
        {
            leaf_pointer iter = _root;

            while (iter && iter->_value != value)
            {
                if (_value_compare(iter->_value, value))
                    iter = iter->right;
                else
                    iter = iter->left;
            }
            return (iter);
        }

        leaf_pointer find(typename T::first_type value) const
        {
            leaf_pointer iter = _root;

            while (iter && iter->_value.first != value)
            {
                if (_key_compare(iter->_value.first, value))
                    iter = iter->right;
                else
                    iter = iter->left;
            }
            return (iter);
        }
    };
}

#endif