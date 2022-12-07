#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <functional>
# include "pair.hpp"
# include "avl_tree.hpp"
# include "avl_tree_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map
		{
			public:
				typedef Key														key_type;
				typedef T														mapped_type;
				typedef pair<const key_type, mapped_type>						value_type;
				typedef Compare													key_compare;
				typedef Alloc													allocator_type;
				class value_compare : public std::binary_function<value_type, value_type, bool>
		    	{
					private:
		    			friend class map<Key, T, Compare, Alloc>;

		    		protected:
		    			Compare comp;

		    			value_compare(Compare c) : comp(c) { }

		    		public:
		    			bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		       };
		 
			private:
				typedef ft::Avl_tree<key_type, value_type, key_compare, allocator_type> Tree_type;

				Tree_type tree;

			public:
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename Tree_type::iterator				iterator;
				typedef typename Tree_type::iterator				const_iterator;
				typedef typename Tree_type::reverse_iterator		reverse_iterator;
				typedef typename Tree_type::reverse_iterator		const_reverse_iterator;
				typedef typename Tree_type::difference_type			difference_type;
				typedef typename Tree_type::size_type				size_type;

	// Constructors

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(comp, alloc) {}
				map(const map& src) : tree(src) {}
				template <class InputIterator>
					map(InputIterator first, InputIterator last) { tree.insert_range(first, last); }
				template <class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(comp, alloc) { tree.insert_range(first, last); }

	// Operator =

				map& operator=(const map& src)
				{
					tree = src.tree;
					return *this;
				}

	// Iterators

				iterator begin()						{ return tree.begin(); }
				const_iterator begin() const			{ return tree.begin(); }
				iterator end()							{ return tree.end(); }
				const_iterator end() const				{ return tree.end(); }
				reverse_iterator rbegin()				{ return tree.rbegin(); }
				const_reverse_iterator rbegin() const	{ return tree.rbegin(); }
				reverse_iterator rend()					{ return tree.rend(); }
				const_reverse_iterator rend() const		{ return tree.rend(); }

	// Capacity

				bool empty() const			{ return tree.empty(); }
				size_type size() const 		{ return tree.size(); }
				size_type max_size() const	{ return tree.max_size(); }

	// Element access

				mapped_type& operator[](const key_type& k) {
					; // TODO
				};

	// Modifiers

				pair<iterator,bool> insert (const value_type& val)			{ return tree.insert_unique(val); }
				iterator insert (iterator position, const value_type& val)	{ return tree.insert_hint(position, val); }
				template <class InputIterator>
					void insert (InputIterator first, InputIterator last)	{ tree.insert_range(first, last); }
				void erase (iterator position)								{ tree.erase(position); }
				size_type erase (const key_type& k)							{ return tree.erase(k); }
				void erase (iterator first, iterator last)					{ tree.erase(first, last); }
				void swap (map& src)										{ tree.swap(src); }
				void clear()												{ tree.clear(); }

	// Observers

				key_compare key_comp() const		{ return tree.key_comp(); }
				value_compare value_comp() const	{ return value_compare(tree.key_comp()); }

	// Operations

				iterator find (const key_type& k)											{ return tree.find(k); }
				const_iterator find (const key_type& k) const								{ return tree.find(k); }
				size_type count (const key_type& k) const									{ return tree.count(k); }
				iterator lower_bound (const key_type& k)									{ return tree.lower_bound(k); }
				const_iterator lower_bound (const key_type& k) const						{ return tree.lower_bound(k); }
				iterator upper_bound (const key_type& k)									{ return tree.upper_bound(k); }
				const_iterator upper_bound (const key_type& k) const						{ return tree.upper_bound(k); }
				pair<iterator,iterator>	equal_range (const key_type& k)						{ return tree.equal_range(k); }
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const	{ return tree.equal_range(k); }

	// Allocator

				allocator_type get_allocator() const { return tree.get_allocator(); }
		};

	// Non member functions overload

	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline bool	operator==(const map<Key, Tp, Compare, Alloc> &lhs, const map<Key, Tp, Compare, Alloc> &rhs)	{ return lhs.tree == rhs.tree; }
	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline bool	operator<(const map<Key, Tp, Compare, Alloc> &lhs, const map<Key, Tp, Compare, Alloc> &rhs)		{ return lhs.tree < rhs.tree; }
	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline bool	operator!=(const map<Key, Tp, Compare, Alloc> &lhs, const map<Key, Tp, Compare, Alloc> &rhs)	{ return !(lhs == rhs); }
	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline bool	operator>(const map<Key, Tp, Compare, Alloc> &lhs, const map<Key, Tp, Compare, Alloc> &rhs)		{ return rhs < lhs; }
	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline bool	operator<=(const map<Key, Tp, Compare, Alloc> &lhs, const map<Key, Tp, Compare, Alloc> &rhs)	{ return !(rhs < lhs); }
	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline bool	operator>=(const map<Key, Tp, Compare, Alloc> &lhs, const map<Key, Tp, Compare, Alloc> &rhs)	{ return !(lhs < rhs); }
	template<typename Key, typename Tp, typename Compare, typename Alloc>
		inline void	swap(map<Key, Tp, Compare, Alloc>& x, map<Key, Tp, Compare, Alloc>& y)							{ x.swap(y); }
}

#endif
