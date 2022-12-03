#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include <memory>
// # include "Avl_tree_utils.hpp"
// # include "iterator_base_types.hpp"
// # include "reverse_iterator.hpp"
// # include "Avl_tree_iterator.hpp"
// # include "pair.hpp"
// # include "algorithm.hpp"

namespace ft
{
	template<typename Key, typename Val>
		struct	Avl_tree_node
		{
			typedef Avl_tree_node<Val>* 		Node_type;
			typedef const Avl_tree_node<Val>*	Const_Node_type;
			typedef Val							value_type;

			Node_type	parent;
			Node_type	left_child;
			Node_type	right_child;
			value_type	value;
			int			balance;

			Key					key()			{ return value.first; }
			value_type*			valptr()		{ return &value; }
			const value_type*	valptr() const	{ return &value; }
		};

// 					  int, pair<int, char>,
	template<typename Key, typename Val, typename Compare, typename Alloc = std::allocator<Val> >
		class Avl_tree
		{
			protected:
				typedef Avl_tree_node<Val>* 											Node_type;
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

				Node_type	_create_node(const value_type& val)
				{
					Node_type	node = _node_allocator.allocate(1);

					try			{ _node_allocator.construct(node->valptr(), val); }
					catch(...)	{ _node_allocator.deallocate(node, 1); throw; }
					return node;
				}

				void	_destroy_node(Node_type node)
				{
					_node_allocator.destroy(node->valptr());
					_node_allocator.deallocate(node, 1);
				}

				Node_type	_clone_node(Const_Node_type src)
				{
					Node_type clone = _create_node(*src->valptr());

					clone->parent = NULL;
					clone->left_child = NULL;
					clone->right_child = NULL;
					clone->balance = 0;
					return clone;
				}

				Node_type&		_root()				{ return _header.parent; }
				Const_Node_type	_root() const		{ return _header.parent; }
				Node_type&		_leftmost()			{ return _header.left; }
				Const_Base_ptr	_leftmost() const	{ return _header.left; }
				Node_type&		_rightmost()		{ return _header.right; }
				Const_Base_ptr	_rightmost() const	{ return _header.right; }
				Node_type		_end()				{ return &_header; }
				Const_Base_ptr	_end() const		{ return &_header; }

				static Node_type		_minimum(Node_type node)		{ while (node->left_child != 0) node = node->left_child; return node; }
				static Const_Node_type	_minimum(Const_Node_type node)	{ while (node->left_child != 0) node = node->left_child; return node; }
				static Node_type		_maximum(Node_type node)		{  while (node->right_child != 0) node = node->right_child; return node; }
				static Const_Node_type	_maximum(Const_Node_type node)	{  while (node->right_child != 0) node = node->right_child; return node; }

			private:
				pair<Node_type, Node_type>	get_insert_unique_pos(const key_type& key)
				{
					typedef pair<Node_type, Node_type> Res;
					Node_type	x = _root();
					Node_type	y = _end();
					bool		comp = true;

					while (x != 0)
					{
						y = x;
						comp = _key_comp(key, x->key());
						x = comp ? x->left_child : x->right_child;
					}
					iterator	j = iterator(y);
					if (comp)
					{
						if (j == begin())
							return Res(x, y);
						else
							--j;
					}
					if (_key_comp(j.node->key(), key))
						return Res(x, y);
					return Res(j.node, 0);
				}

				pair<Node_type, Node_type>	get_insert_hint_pos(const_iterator pos, const key_type& key)
				{
					typedef pair<Node_type, Node_type> Res;
					iterator	it = pos._const_cast();

					if (it.node == _end())
					{
						if (size() > 0 && _key_comp(_rightmost()->key(), key))
							return Res(0, _rightmost());
						else
							return get_insert_unique_pos(key);
					}
					else if (_key_comp(key, it.node->key()))
					{
						iterator before = it;
						if (it.node == _leftmost())
							return Res(_leftmost(), _leftmost());
						else if (_key_comp((--before).node->key(), key))
						{
							if (before->right_childnode) == 0)
								return Res(0, before.node);
							else
								return Res(it.node, it.node);
						}
						else
							return get_insert_unique_pos(key);
					}
					else if (_key_comp(it.node->key(), key))
					{
						iterator after = it;
						if (it.node == _rightmost())
							return Res(0, _rightmost());
						else if (_key_comp(key, (++after).node->key()))
						{
							if (it->right_childnode) == 0)
								return Res(0, it.node);
							else
								return Res(after.node, after.node);
						}
						else
							return get_insert_unique_pos(key);
					}
					else
						return Res(it.node, 0);
				}

				iterator	insert(Node_type x, Node_type y, const value_type& val)
				{
					bool		insert_left = (x != 0 || y == _end() || _key_comp((val).first, y->key));
					Node_type	z = _create_node(val);

					Avl_tree_insert_and_rebalance(insert_left, z, y, _header);
					++_node_count;
					return iterator(z);
				}

				Node_type	_copy(Const_Node_type src, Node_type parent)
				{
					Node_type node = _clone_node(src);

					node->parent = parent;
					try
					{
						if (src->right_child)
							node->right_child = _copy(src->right_child, node);
						parent = node;
						src = src->left_child;
						while (src != 0)
						{
							Node_type left_node = _clone_node(src);
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

				Node_type	_copy(const Avl_tree& src)
				{
					Node_type root = _copy(src._root(), NULL);

					_leftmost() = _minimum(root);
					_rightmost() = _maximum(root);
					_node_count = src._node_count;
					return root;
				}

				void		_delete(Node_type node)
				{
					while (node != NULL)
					{
						_delete(node->right_child);
						Node_type tmp = node->left_child;
						_destroy_node(node);
						node = tmp;
					}
				}
// Retravailler _lower_bound() et _upper_bound()
				iterator		_lower_bound(Node_type x, Node_type y, const key_type& key)
				{
					while (x != 0)
					{
						if (!_key_comp(x->key(), key))
						{
							y = x;
							x = x->left_child;
						}
						else
							x = x->right_child;
					}
					return iterator(y);
				}

				const_iterator	_lower_bound(Const_Node_type x, Const_Node_type y, const key_type& key) const
				{
					while (x != 0)
					{
						if (!_key_comp(x->key(), key))
						{
							y = x;
							x = x->left_child;
						}
						else
							x = x->right_child;
					}
					return const_iterator(y);
				}

				iterator		_upper_bound(Node_type x, Node_type y, const key_type& key)
				{
					while (x != 0)
					{
						if (_key_comp(key, x->key()))
						{
							y = x;
							x = x->left_child;
						}
						else
							x = x->right_child;
					}
					return iterator(y);
				}

				const_iterator	_upper_bound(Const_Node_type x, Const_Node_type y, const key_type& key) const
				{
					while (x != 0)
					{
						if (_key_comp(key, x->key()))
						{
							y = x;
							x = x->left_child;
						}
						else
							x = x->right_child;
					}
					return const_iterator(y);
				}

				void	_reset()
				{		
					_header.parent = NULL;
					_header.left = &_header;
					_header.right = &_header;
					_node_count = 0;
				}

			public:
				Avl_tree(const Compare& comp, const allocator_type& alloc = allocator_type()) : _key_comp(comp), _allocator(alloc)
				{
					_resest();
				}

				Avl_tree(const Avl_tree& src) : _key_comp(src._key_comp), _allocator(src._allocator)
				{
					_resest();
					if (src._root() != 0)
						_root() = _copy(src);
				}

				~Avl_tree() { _delete(_root()); }

				Avl_tree&	operator=(const Avl_tree& src)
				{
					if (this != &src)
					{
						_reset();
						_key_comp = src._key_comp;
						if (src._root() != 0)
							_root() = _copy(src);
					}
					return *this;
				}

				//~~ Iterators
				iterator				begin()			{ return iterator(_leftmost()); }
				const_iterator			begin() const	{ return const_iterator(_leftmost()); }
				iterator				end()			{ return iterator(_end()); }
				const_iterator			end() const		{ return const_iterator(_end()); }
				reverse_iterator		rbegin()		{ return reverse_iterator(end()); }
				const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(end()); }
				reverse_iterator		rend()			{ return reverse_iterator(begin()); }
				const_reverse_iterator	rend() const	{ return const_reverse_iterator(begin()); }

				//~~ Capacity
				bool		empty() const		{ return _node_count == 0; }
				size_type	size() const		{ return _node_count; }
				size_type	max_size() const	{ return _node_allocator.max_size(); }

				//~~ Modifiers
				pair<iterator, bool>	insert_unique(const value_type& val)
				{
					pair<Node_type, Node_type>	res = get_insert_unique_pos((val).first);

					if (res.second)
						return pair<iterator, bool>(insert(res.first, res.second, val), true);
					return pair<iterator, bool>(iterator(res.first), false);
				}

				iterator	insert_hint(const_iterator pos, const value_type& val)
				{
					pair<Node_type, Node_type>	res = get_insert_hint_pos(pos, (val).first);
					
					if (res.second)
						return insert(res.first, res.second, val);
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
					Node_type	node = static_cast<Node_type>(Avl_tree_rebalance_for_erase(const_cast<Node_type>(pos.node), _header));
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

				//~~ Observers
				Compare	key_comp() const	{ return _key_comp; }

				//~~ Operations
				iterator 		find(const key_type& key)
				{
					iterator	it = _lower_bound(_root(), _end(), key);

					if (it == end() || _key_comp(key, it.node->key()))
						return end();
					else
						return it;
				}

				const_iterator	find(const key_type& key) const
				{
					const_iterator	it = _lower_bound(_root(), _end(), key);

					if (it == end() || _key_comp(key, it.node->key()))
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

				iterator		lower_bound(const key_type& key)		{ return _lower_bound(_root(), _end(), key); }
				const_iterator	lower_bound(const key_type& key) const	{ return _lower_bound(_root(), _end(), key); }
				iterator		upper_bound(const key_type& key)		{ return _upper_bound(_root(), _end(), key); }
				const_iterator	upper_bound(const key_type& key) const	{ return _upper_bound(_root(), _end(), key); }

				pair<iterator, iterator>				equal_range(const key_type& key)
				{
					iterator	it = _upper_bound(_root(), _end(), key);

					if (!_key_comp(key, it.node->key()))
						return make_pair(it, ++it);
					return make_pair(it, it);
				}

				pair<const_iterator, const_iterator>	equal_range(const key_type& key) const
				{
					const_iterator	it = _upper_bound(_root(), _end(), key);

					if (!_key_comp(key, it.node->key()))
						return make_pair(it, ++it);
					return make_pair(it, it);
				}

				//~~ Allocator
				allocator_type			get_allocator() const		{ return allocator_type(_allocator); }

		}; //~~ class Avl_tree

		//~~ Relational Operators
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator==(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator<(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator!=(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return !(x == y); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator>(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return y < x; }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator<=(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return !(y < x); }
		template<typename Key, typename Val, typename Compare, typename Alloc>
			bool	operator>=(const Avl_tree<Key, Val, Compare, Alloc>& x, const Avl_tree<Key, Val, Compare, Alloc>& y)	{ return !(x < y); }
} //~~ namespace ft

#endif
