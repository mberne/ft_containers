#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <functional>
# include "iterator.hpp"
# include "pair.hpp"

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
				class value_compare
		    	: public binary_function<value_type, value_type, bool>
		    	{
		    		friend class map<_Key,_Tp,_Compare,_Alloc>;
		    		protected:
		    			Compare comp;

		    			value_compare(Compare c) : comp(c) { }

		    		public:
		    			bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		       };
		 
// 		     private:
// 		       typedef _Rb_tree<key_type, value_type, _Select1st<value_type>, key_compare, _Alloc> _Rep_type;
// 		       _Rep_type _M_t;

			public:
				typedef typename allocator_type::pointer						pointer;
				typedef typename allocator_type::const_pointer					const_pointer;
				typedef typename allocator_type::reference						reference;
				typedef typename allocator_type::const_reference				const_reference;
				typedef typename bidirectional_iterator							iterator; //should be ft
				typedef typename bidirectional_iterator							const_iterator; //should be ft
				typedef typename reverse_iterator<iterator>						reverse_iterator; //should be ft
				typedef typename reverse_iterator<const_iterator>				const_reverse_iterator; //should be ft
				typedef typename iterator_traits<iterator>::difference_type		difference_type; //should be ft
				typedef typename iterator_traits<iterator>::size_type			size_type; //should be ft

	// Constructors

				map();
				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
				map(const map& x);
				template <class InputIterator>
					map(InputIterator first, InputIterator last);
				template <class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

	// Operator =

				map& operator=(const map& x);

	// Iterators

				iterator begin();
				const_iterator begin() const;
				iterator end();
				const_iterator end() const;
				reverse_iterator rbegin();
				const_reverse_iterator rbegin() const;
				reverse_iterator rend();
				const_reverse_iterator rend() const;

	// Capacity

				size_type size() const;
				size_type max_size() const;
				bool empty() const;

	// Element access

				mapped_type& operator[](const key_type& k);

	// Modifiers

				pair<iterator,bool> insert (const value_type& val);
				iterator insert (iterator position, const value_type& val);
				template <class InputIterator>
					void insert (InputIterator first, InputIterator last);
				void erase (iterator position);
				size_type erase (const key_type& k);
				void erase (iterator first, iterator last);
				void swap (map& x);
				void clear();

	// Observers

				key_compare key_comp() const;
				value_compare value_comp() const;

	// Operations

				iterator find (const key_type& k);
				const_iterator find (const key_type& k) const;
				size_type count (const key_type& k) const;
				iterator lower_bound (const key_type& k);
				const_iterator lower_bound (const key_type& k) const;
				iterator upper_bound (const key_type& k);
				const_iterator upper_bound (const key_type& k) const;
				pair<iterator,iterator>	equal_range (const key_type& k);
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

	// Allocator

				allocator_type get_allocator() const;

		};
}

#endif
