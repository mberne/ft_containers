#ifndef AVL_TREE_ITERATOR_HPP
# define AVL_TREE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	// Node structure

	template<typename Val>
		struct	Avl_tree_node
		{
			typedef Avl_tree_node<Val>* 		Node;
			typedef const Avl_tree_node<Val>*	Const_Node;
			typedef Val							value_type;
			typedef typename Val::first_type	key_type;

			Node		parent;
			Node		left_child;
			Node		right_child;
			value_type	value;
			int			height;

			key_type			key()			{ return value.first; }
			const key_type		key() const		{ return value.first; }
			value_type*			valptr()		{ return &value; }
			const value_type*	valptr() const	{ return &value; }

			Node	minimum()
			{
				Node tmp = this;
				while (tmp->left_child)
					tmp = tmp->left_child;
				return tmp;
			}

			Node	maximum()
			{
				Node tmp = this;
				while (tmp->right_child)
					tmp = tmp->right_child;
				return tmp;
			}
		};

	// Utils

	template<typename T>
		static Avl_tree_node<T>*	_Avl_tree_increment(Avl_tree_node<T>* current) throw ()
		{
			if (current->right_child)
			{
				current = current->right_child;
				while (current->left_child)
					current = current->left_child;
			}
			else
			{
				Avl_tree_node<T>* parent = current->parent;
				while (current == parent->right_child)
				{
					current = parent;
					parent = parent->parent;
				}
				if (current->right_child != parent)
					current = parent;
			}
			return current;
		}

	template<typename T>
		Avl_tree_node<T>* 		Avl_tree_increment(Avl_tree_node<T>* current) throw ()			{ return _Avl_tree_increment(current); }
	template<typename T>
		const Avl_tree_node<T>* Avl_tree_increment(const Avl_tree_node<T>* current) throw ()	{ return _Avl_tree_increment(const_cast<Avl_tree_node<T>*>(current)); }

	template<typename T>
		static Avl_tree_node<T>*	_Avl_tree_decrement(Avl_tree_node<T>* current) throw ()
		{
			if (current == current->parent->parent)
				current = current->right_child;
			else if (current->left_child)
			{
				Avl_tree_node<T>* rightmost = current->left_child;
				while (rightmost->right_child)
					rightmost = rightmost->right_child;
				current = rightmost;
			}
			else
			{
				Avl_tree_node<T>* parent = current->parent;
				while (current == parent->left_child)
				{
					current = parent;
					parent = parent->parent;
				}
				current = parent;
			}
			return current;
		}

	template<typename T>
		Avl_tree_node<T>*		Avl_tree_decrement(Avl_tree_node<T>* current) throw ()			{ return _Avl_tree_decrement(current); }
	template<typename T>
		const Avl_tree_node<T>*	Avl_tree_decrement(const Avl_tree_node<T>* current) throw ()	{ return _Avl_tree_decrement(const_cast<Avl_tree_node<T>*>(current)); }

	// Iterator

	template<typename T>
		struct Avl_tree_iterator
		{
			typedef ptrdiff_t							difference_type;
			typedef Avl_tree_node<T>*					Node;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::bidirectional_iterator_tag		iterator_category;
	
			Node	node;

	// Constructors

			Avl_tree_iterator() : node() {}
			explicit Avl_tree_iterator(Node src) : node(src) {}

	// Member functions
	
			reference	operator*() const	{ return *node->valptr(); }
			pointer		operator->() const	{ return node->valptr(); }
			Avl_tree_iterator		&operator++()
			{
				node = Avl_tree_increment(node);
				return *this;
			}
			Avl_tree_iterator		operator++(int)
			{
				Avl_tree_iterator tmp = *this;
				node = Avl_tree_increment(node);
				return tmp;
			}
			Avl_tree_iterator		&operator--()
			{
				node = Avl_tree_decrement(node);
				return *this;
			}
			Avl_tree_iterator		operator--(int)
			{
				Avl_tree_iterator tmp = *this;
				node = Avl_tree_decrement(node);
				return tmp;
			}

			friend bool		operator==(const Avl_tree_iterator& x, const Avl_tree_iterator& y)	{ return x.node == y.node; }
			friend bool		operator!=(const Avl_tree_iterator& x, const Avl_tree_iterator& y)	{ return x.node != y.node; }
		};

	// Const iterator

	template<typename T>
		struct Avl_tree_const_iterator
		{
			typedef Avl_tree_iterator<T>				iterator;
			typedef ptrdiff_t							difference_type;
			typedef const Avl_tree_node<T>*				Node;
			typedef T									value_type;
			typedef const T*							pointer;
			typedef const T&							reference;
			typedef std::bidirectional_iterator_tag		iterator_category;

			Node	node;

	// Constructors

			Avl_tree_const_iterator() : node() {}
			explicit Avl_tree_const_iterator(Node src) : node(src) {}
			Avl_tree_const_iterator(const iterator& it) : node(it.node) {}

	// Member functions

			reference	operator*() const	{ return *node->valptr(); }
			pointer		operator->() const	{ return node->valptr(); }

			Avl_tree_const_iterator	&operator++()
			{
				node = Avl_tree_increment(node);
				return *this;
			}
			Avl_tree_const_iterator	operator++(int)
			{
				Avl_tree_const_iterator tmp = *this;
				node = Avl_tree_increment(node);
				return tmp;
			}
			Avl_tree_const_iterator	&operator--()
			{
				node = Avl_tree_decrement(node);
				return *this;
			}
			Avl_tree_const_iterator	operator--(int)
			{
				Avl_tree_const_iterator tmp = *this;
				node = Avl_tree_decrement(node);
				return tmp;
			}

			friend bool		operator==(const Avl_tree_const_iterator& x, const Avl_tree_const_iterator& y)	{ return x.node == y.node; }
			friend bool		operator!=(const Avl_tree_const_iterator& x, const Avl_tree_const_iterator& y)	{ return x.node != y.node; }
		};
}

#endif
