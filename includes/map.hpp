#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <functional>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		private:
			typename Key											key_type;
			typename T												mapped_type;
			typename pair<const key_type, mapped_type>				value_type;
			typename Compare										key_compare;
			//														value_compare;
			typename Alloc											allocator_type;
			typename allocator_type::reference						reference;
			typename allocator_type::const_reference				const_reference;
			typename allocator_type::pointer						pointer;
			typename allocator_type::const_pointer					const_pointer;
			typename bidirectional_iterator							iterator;
			typename bidirectional_iterator							const_iterator;
			typename reverse_iterator<iterator>						reverse_iterator; //should be ft
			typename reverse_iterator<const_iterator>				const_reverse_iterator; //should be ft
			typename iterator_traits<iterator>::difference_type		difference_type; //should be ft
			typename iterator_traits<iterator>::size_type			size_type; //should be ft

		public:

// Constructors

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
				map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map (const map& x);

// Destructor

			~map();

// Operator =

			map& operator= (const map& x);

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

			mapped_type& operator[] (const key_type& k);

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
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>	equal_range (const key_type& k);

// Allocator

			allocator_type get_allocator() const;

	};
}

#endif
