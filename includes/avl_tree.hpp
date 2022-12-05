#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include <memory>
# include "pair.hpp"
// # include "Avl_tree_utils.hpp"
// # include "iterator_base_types.hpp"
# include "reverse_iterator.hpp"
# include "avl_tree_iterator.hpp"
// # include "algorithm.hpp"

namespace ft
{
	// Node structure

	template<typename Val>
		struct	Avl_tree_node
		{
			typedef Avl_tree_node<Val>* 		Node;
			typedef const Avl_tree_node<Val>*	Const_Node_type;
			typedef Val							value_type;
			typedef Val::first_type				key_type

			Node	parent;
			Node	left_child;
			Node	right_child;
			value_type	value;
			int			height;

			key_type			key()			{ return value.first; }
			value_type*			valptr()		{ return &value; }
			const value_type*	valptr() const	{ return &value; }
		};

	// AVL tree class

	template<typename Key, typename Val, typename Compare, typename Alloc = std::allocator<Val> >
		class Avl_tree
		{
			protected:
				typedef Avl_tree_node<Val>* 											Node;
				typedef const Avl_tree_node<Val>*										Const_Node_type;
				typedef typename Alloc::template rebind<Avl_tree_node<Val> >::other     Node_allocator;

			public:
				typedef Key										key_type;
				typedef Val										value_type;
				typedef value_type*								pointer;
				typedef const value_type*						const_pointer;
				typedef value_type&								reference;
				typedef const value_type&						const_reference;
				typedef Avl_tree_iterator<value_type>			iterator;
				typedef Avl_tree_const_iterator<value_type>		const_iterator;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef size_t									size_type;
				typedef ptrdiff_t								difference_type;
				typedef Alloc									allocator_type;

			protected:
				Compare				_key_comp;
				allocator_type		_allocator;
				Node_allocator		_node_allocator;
				size_t				_node_count;
				Avl_tree_node		_header;

				Node	_create_node(const value_type& val)
				{
					Node	node = _node_allocator.allocate(1);

					try			{ _node_allocator.construct(node->valptr(), val); }
					catch(...)	{ _node_allocator.deallocate(node, 1); throw; }
					return node;
				}

				void	_destroy_node(Node node)
				{
					_node_allocator.destroy(node->valptr());
					_node_allocator.deallocate(node, 1);
				}

				Node	_clone_node(Const_Node_type src)
				{
					Node clone = _create_node(*src->valptr());

					clone->parent = NULL;
					clone->left_child = NULL;
					clone->right_child = NULL;
					clone->height = src->height;
					return clone;
				}

				Node&			_root()				{ return _header.parent; }
				Const_Node_type	_root() const		{ return _header.parent; }
				Node&			_leftmost()			{ return _header.left_child; }
				Const_Base_ptr	_leftmost() const	{ return _header.left_child; }
				Node&			_rightmost()		{ return _header.right_child; }
				Const_Base_ptr	_rightmost() const	{ return _header.right_child; }
				Node			_end()				{ return &_header; }
				Const_Base_ptr	_end() const		{ return &_header; }

				static Node				_minimum(Node node)				{ while (node->left_child) node = node->left_child; return node; }
				static Const_Node_type	_minimum(Const_Node_type node)	{ while (node->left_child) node = node->left_child; return node; }
				static Node				_maximum(Node node)				{  while (node->right_child) node = node->right_child; return node; }
				static Const_Node_type	_maximum(Const_Node_type node)	{  while (node->right_child) node = node->right_child; return node; }

			private:
				Node	_copy(Const_Node_type src, Node parent)
				{
					Node node = _clone_node(src);

					node->parent = parent;
					try
					{
						if (src->right_child)
							node->right_child = _copy(src->right_child, node);
						parent = node;
						src = src->left_child;
						while (src)
						{
							Node left_node = _clone_node(src);
							parent->left_child = left_node;
							left_node->parent = parent;
							if (src->right_child)
								left_node->right_child = _copy(src->right_child, left_node);
							parent = left_node;
							src = src->left_child;
						}
					}
					catch(...) { _delete(node); throw; }
					return node;
				}

				Node	_copy(const Avl_tree& src)
				{
					Node root = _copy(src._root(), NULL);

					_leftmost() = _minimum(root);
					_rightmost() = _maximum(root);
					_node_count = src._node_count;
					return root;
				}

				void		_delete(Node node)
				{
					while (node)
					{
						_delete(node->right_child);
						Node tmp = node->left_child;
						_destroy_node(node);
						node = tmp;
					}
				}

				void	_reset()
				{		
					_header.parent = NULL;
					_header.left_child = &_header;
					_header.right_child = &_header;
					_node_count = 0;
				}

			public:

	// Constructors

				Avl_tree(const Compare& comp, const allocator_type& alloc = allocator_type()) : _key_comp(comp), _allocator(alloc)
				{
					_resest();
				}

				Avl_tree(const Avl_tree& src) : _key_comp(src._key_comp), _allocator(src._allocator)
				{
					_resest();
					if (src._root())
						_root() = _copy(src);
				}

	// Destructor

				~Avl_tree() { _delete(_root()); }

	// Operator=

				Avl_tree&	operator=(const Avl_tree& src)
				{
					if (this != &src)
					{
						_reset();
						_key_comp = src._key_comp;
						if (src._root())
							_root() = _copy(src);
					}
					return *this;
				}

	// Iterators

				iterator				begin()			{ return iterator(_leftmost()); }
				const_iterator			begin() const	{ return const_iterator(_leftmost()); }
				iterator				end()			{ return iterator(_end()); }
				const_iterator			end() const		{ return const_iterator(_end()); }
				reverse_iterator		rbegin()		{ return reverse_iterator(end()); }
				const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(end()); }
				reverse_iterator		rend()			{ return reverse_iterator(begin()); }
				const_reverse_iterator	rend() const	{ return const_reverse_iterator(begin()); }

	// Capacity
	
				bool		empty() const		{ return _node_count == 0; }
				size_type	size() const		{ return _node_count; }
				size_type	max_size() const	{ return _node_allocator.max_size(); }

	// Modifiers
	
			private:
				pair<Node, Node>	_get_insert_unique_pos(const key_type& key)
				{
					typedef pair<Node, Node> Result;
					Node	x = _root();
					Node	y = _end();

					iterator	j = find(key);
					if (j != end())
						return Result(j.node, NULL);
					while (x)
					{
						y = x;
						if (_key_comp(key, x->key()))
							x = x->left_child;
						else
							x = x->right_child;
					}
					return Result(x, y);
				}

				pair<Node, Node>	_get_insert_hint_pos(const_iterator pos, const key_type& key)
				{
					typedef pair<Node, Node> Result;
					iterator	it_pos = pos._const_cast();

					if (it_pos.node == _end())
					{
						if (size() > 0 && _key_comp(_rightmost()->key(), key))
							return Result(NULL, _rightmost());
						else
							return _get_insert_unique_pos(key);
					}
					else if (_key_comp(key, it_pos.node->key()))
					{
						if (it_pos.node == _leftmost())	
							return Result(_leftmost(), _leftmost());

						iterator before = it_pos;
						--before;
						if (_key_comp(before.node->key(), key))
						{
							// if (before.node->right_child == NULL)
							if (before->right_child == NULL)
								return Result(NULL, before.node);
							else
								return Result(it_pos.node, it_pos.node);
						}
						else
							return _get_insert_unique_pos(key);
					}
					else if (_key_comp(it_pos.node->key(), key))
					{
						if (it_pos.node == _rightmost())
							return Result(NULL, _rightmost());

						iterator after = it_pos;
						++after;
						if (_key_comp(key, after.node->key()))
						{
							// if (it_pos.node->right_child == NULL)
							if (it_pos.node->right_child == NULL)
								return Result(NULL, it_pos.node);
							else
								return Result(after.node, after.node);
						}
						else
							return _get_insert_unique_pos(key);
					}
					else
						return Result(it_pos.node, NULL);
				}

				iterator	_insert(Node x, Node parent, const value_type& val)
				{
					Node	node = _create_node(val);

					node->parent = parent;
					node->left_child = NULL;
					node->right_child = NULL;
					node->height = 1;

					if (x != 0 || parent == _end() || _key_comp(val.first, parent->key)) // insert left
					{
						parent->left_child = node;
						if (parent == _end())
						{
							_header.parent = node;
							_header.right_child = node;
						}
						else if (parent == _begin())
							_begin() = node;
					}
					else // insert right
					{
						parent->right_child = node;
						if (parent == _end())
							_end() = node;
					}
					Avl_tree_rebalance_after_insert(node, parent, _root());
					++_node_count;
					return iterator(node);
				}

			public:
				pair<iterator, bool>	insert_unique(const value_type& val)
				{
					pair<Node, Node>	result = _get_insert_unique_pos(val.first);

					if (result.second)
						return pair<iterator, bool>(_insert(result.first, result.second, val), true);
					return pair<iterator, bool>(iterator(result.first), false);
				}

				iterator	insert_hint(const_iterator pos, const value_type& val)
				{
					pair<Node, Node>	res = _get_insert_hint_pos(pos, val.first);
					
					if (res.second)
						return _insert(res.first, res.second, val);
					return iterator(res.first);
				}

				template<typename InputIterator>
					void	insert_range(InputIterator first, InputIterator last)
					{
						for (; first != last; ++first)
							insert_hint(end(), *first);
					}

			private:
				void	erase_aux(const_iterator pos)
				{
					Node	node = static_cast<Node>(Avl_tree_rebalance_for_erase(const_cast<Node>(pos.node), _header));
					_destroy_node(node);
					--_node_count;
				}

				void	erase_aux(const_iterator first, const_iterator last)
				{
					if (first == begin() && last == end())
						clear();
					else
						while (first != last)
							erase_aux(first++);
				}

			public:
				void		erase(iterator pos)			{ erase_aux(pos); }
				void		erase(const_iterator pos)	{ erase_aux(pos); }

				size_type	erase(const key_type& x)
				{
					pair<iterator, iterator>	pos = equal_range(x);
					const size_type				old_size = size();
					erase_aux(pos.first, pos.second);
					return old_size - size();
				}

				void		erase(iterator first, iterator last)				{ erase_aux(first, last); }
				void		erase(const_iterator first, const_iterator last)	{ erase_aux(first, last); }

				void	swap(Avl_tree& src)
				{
					std::swap(_root(),src._root());
					std::swap(_leftmost(),src._leftmost());
					std::swap(_rightmost(),src._rightmost());
					std::swap(_node_count, src._node_count);
					std::swap(_key_comp, src._key_comp);
					std::swap(_allocator, src._allocator);
					std::swap(_node_allocator, src._node_allocator);
				}

				void	clear()
				{
					_delete(_root());
					_reset();
				}

	// Observers
	
				Compare	key_comp() const	{ return _key_comp; }

	// Operations
	
				iterator 		find(const key_type& key)
				{
					iterator	it = lower_bound(key);

					if (it == end() || key != it.node->key())
						return end();
					else
						return it;
				}

				const_iterator	find(const key_type& key) const
				{
					const_iterator	it = lower_bound(key);

					if (it == end() || key != it.node->key())
						return end();
					else
						return it;
				}

				size_type 		count(const key_type& key) const
				{
					if (find(key) == end())
						return 0;
					return 1;
				}

				iterator		lower_bound(const key_type& key)
				{
					Node current = root();
					Node result = end();

					while (current)
					{
						if (!_key_comp(current->key(), key))
						{
							result = current;
							current = current->left_child;
						}
						else
							current = current->right_child;
					}
					return iterator(result);
				}

				const_iterator	lower_bound(const key_type& key) const
				{
					Const_Node_type current = root();
					Const_Node_type result = end();

					while (current)
					{
						if (!_key_comp(current->key(), key))
						{
							result = current;
							current = current->left_child;
						}
						else
							current = current->right_child;
					}
					return const_iterator(result);
				}

				iterator		upper_bound(const key_type& key)
				{
					Node current = root();
					Node result = end();

					while (current)
					{
						if (_key_comp(key, current->key()))
						{
							result = current;
							current = current->left_child;
						}
						else
							current = current->right_child;
					}
					return iterator(result);
				}

				const_iterator	upper_bound(const key_type& key) const
				{
					Const_Node_type current = root();
					Const_Node_type result = end();

					while (current)
					{
						if (_key_comp(key, current->key()))
						{
							result = current;
							current = current->left_child;
						}
						else
							current = current->right_child;
					}
					return const_iterator(result);
				}

				pair<iterator, iterator>				equal_range(const key_type& key)
				{
					iterator	it = upper_bound(key);

					if (key == it.node->key())
						return make_pair(it, ++it);
					return make_pair(it, it);
				}

				pair<const_iterator, const_iterator>	equal_range(const key_type& key) const
				{
					const_iterator	it = upper_bound(key);

					if (key == it.node->key())
						return make_pair(it, ++it);
					return make_pair(it, it);
				}

	// Allocator
	
				allocator_type			get_allocator() const		{ return allocator_type(_allocator); }

	// Affichage arbre

		// public:
        //     struct Trunk
        //     {
        //         Trunk *prev;
        //         std::string str;
            
        //         Trunk(Trunk *prev, std::string str)
        //         {
        //             this->prev = prev;
        //             this->str = str;
        //         }
        //     };

        //     void showTrunks(Trunk *p)
        //     {
        //         if (p == nullptr)
        //             return;
        //         showTrunks(p->prev);
        //         std::cout << p->str;
        //     }

        //     void printTree(pointer root, Trunk *prev, bool isLeft)
        //     {
        //         if (root == nullptr)
        //             return;
        //         std::string prev_str = "    ";
        //         Trunk *trunk = new Trunk(prev, prev_str);
            
        //         printTree(static_cast<pointer>(root->right_child), trunk, true);
            
        //         if (!prev)
        //             trunk->str = "———";
        //         else if (isLeft)
        //         {
        //             trunk->str = "┌———";
        //             prev_str = "    |";
        //         }
        //         else {
        //             trunk->str = "└──";
        //             prev->str = prev_str;
        //         }
            
        //         showTrunks(trunk);
        //         if (root->is_black == false)
        //             std::cout << "\033[31m" << root->pair.first << "\033[0m" << std::endl;
        //         else
        //             std::cout << root->pair.first << std::endl;
                    
        //         if (prev) {
        //             prev->str = prev_str;
        //         }
        //         trunk->str = "    |";
            
        //         printTree(static_cast<pointer>(root->left_child), trunk, false);
        //     }

        //     void print()
        //     {
        //         printTree(static_cast<pointer>(_root), NULL, false);
        //     }
		};

	// Non member functions overload

		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator==(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator<(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)		{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator!=(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return !(x == y); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator>(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)		{ return y < x; }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator<=(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return !(y < x); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator>=(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return !(x < y); }
}

#endif
