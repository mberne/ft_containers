#ifndef AVL_TREE_ITERATOR_HPP
# define AVL_TREE_ITERATOR_HPP

# include "avl_tree.hpp"

namespace ft
{
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
			if (current->left_child)
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
		Avl_tree_node<T>*		Avl_tree_decrement(Avl_tree_node<T>* current) throw ()		{ return _Avl_tree_decrement(current); }
	template<typename T>
		const Avl_tree_node<T>*	Avl_tree_decrement(const Avl_tree_node<T>* current) throw ()	{ return _Avl_tree_decrement(const_cast<Avl_tree_node<T>*>(current)); }

	// Iterator

	template<typename T>
		struct Avl_tree_iterator
		{
			protected:
				typedef	iterator_traits<T>	traits_type;
		
			public:
				Node_type	node;

				typedef typename traits_type::difference_type	difference_type;
				typedef Avl_tree_node<T>*				        Node_type;
				typedef typename traits_type::value_type		value_type;
				typedef typename traits_type::pointer			pointer;
				typedef typename traits_type::reference			reference;
				typedef std::bidirectional_iterator_tag		    iterator_category;
		
	// Constructors

				Avl_tree_iterator() : node() {}
				explicit Avl_tree_iterator(Node_type src) : node(src) {}

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

			private:
				template<typename T1>
					friend bool		operator==(const Avl_tree_iterator<T1>& current, const Avl_tree_iterator<T1>& y)
		};

	// Non member functions overload

	template<typename T>
		bool		operator==(const Avl_tree_iterator<T>& current, const Avl_tree_iterator<T>& y)	{ return current.node == y.node; }
	template<typename T>
		bool		operator!=(const Avl_tree_iterator<T>& current, const Avl_tree_iterator<T>& y)	{ return !(current == y); }

	// Const iterator

	template<typename T>
		struct Avl_tree_const_iterator
		{
			protected:
				typedef	iterator_traits<T>	traits_type;
		
			public:
				Node_type	node;

				typedef Avl_tree_iterator<T>	iterator;

				typedef typename traits_type::difference_type	difference_type;
				typedef const Avl_tree_node<T>*					Node_type;
				typedef typename traits_type::value_type		value_type;
				typedef typename traits_type::pointer			pointer;
				typedef typename traits_type::reference			reference;
				typedef std::bidirectional_iterator_tag		    iterator_category;

	// Constructors

				Avl_tree_const_iterator() : node() {}
				explicit Avl_tree_const_iterator(Node_type src) : node(src) {}
				Avl_tree_const_iterator(const iterator& it) : node(it.node) {}

	// Member functions

				iterator	_const_cast() const	{ return iterator(const_cast<typename iterator::Node_type>(node)); }

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

			private:
				template<typename T1>
					friend bool		operator==(const Avl_tree_const_iterator<T1>& current, const Avl_tree_const_iterator<T1>& y)
		};

	// Non member functions overload

	template<typename T>
		bool		operator==(const Avl_tree_const_iterator<T>& current, const Avl_tree_const_iterator<T>& y)	{ return current.node == y.node; }
	template<typename T>
		bool		operator!=(const Avl_tree_const_iterator<T>& current, const Avl_tree_const_iterator<T>& y)	{ return !(current == y); }
}

#endif
