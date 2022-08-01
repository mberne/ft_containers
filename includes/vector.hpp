#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector {
			public:
				typedef T																value_type;
				typedef Alloc															allocator_type;
				typedef typename allocator_type::reference								reference;
				typedef typename allocator_type::const_reference						const_reference;
				typedef typename allocator_type::pointer								pointer;
				typedef typename allocator_type::const_pointer							const_pointer;
				typedef typename ft::vector_iterator<pointer>							iterator;
				typedef typename ft::vector_iterator<const_pointer>						const_iterator;
				typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
				typedef ptrdiff_t														difference_type;
				typedef size_t															size_type;

			protected:

				allocator_type	_allocator;
				pointer			_begin;
				pointer			_end;
				size_type		_size;

			public:

	// Constructors

				explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _begin(NULL), _end(NULL), _size(0) {}
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(n) {
					_begin = _allocator.allocate(n);
					for (size_type i = 0; i < n; ++i)
						_allocator.construct(_begin + i, val);
					_end = _begin + n;
				}
				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc) {} // ?
				vector(const vector &x) {
					_allocator = x._allocator;
					_size = x._size;
					_begin = _allocator.allocate(_size);
					for (size_type i = 0; i < _size; ++i)
						_allocator.construct(_begin + i, x[i]);
					_end = _begin + _size;
				}

	// Destructor

				~vector() {
					for (size_type i = 0; i < _size; ++i)
						_allocator.destroy(_begin + i);
					_allocator.deallocate(_begin, _size);
				}

	// Operator =

				vector	&operator=(vector const &x) {
					for (size_type i = 0; i < _size; ++i)
						_allocator.destroy(_begin + i);
					_allocator.deallocate(_begin, _size);
					_size = x._size();
					_begin = _allocator.allocate(_size);
					for (size_type i = 0; i < _size; ++i)
						_allocator.construct(_begin + i, x[i]);
				}

	// Iterators

				iterator begin()						{ return iterator(_begin); }
				const_iterator begin() const			{ return const_iterator(_begin); }
				iterator end()							{ return iterator(_end); }
				const_iterator end() const				{ return const_iterator(_end); }
				reverse_iterator rbegin()				{ return reverse_iterator(iterator(_end)); }
				const_reverse_iterator rbegin() const	{ return const_reverse_iterator(const_iterator(_end)); }
				reverse_iterator rend()					{ return reverse_iterator(iterator(_begin)); }
				const_reverse_iterator rend() const		{ return const_reverse_iterator(const_iterator(_begin)); }

	// Capacity

				size_type size() const { return static_cast<size_type>(end - begin); };
				size_type max_size() const;
				void resize (size_type n, value_type val = value_type());
				size_type capacity() const;
				bool empty() const;
				void reserve (size_type n);

	// Element access

				reference operator[] (size_type n);
				const_reference operator[] (size_type n) const;
				reference at (size_type n);
				const_reference at (size_type n) const;
				reference front();
				const_reference front() const;
				reference back();
				const_reference back() const;

	// Modifiers

				template <class InputIterator>
					void assign (InputIterator first, InputIterator last);
				void assign (size_type n, const value_type& val);
				void push_back (const value_type& val);
				void pop_back();
				iterator insert (iterator position, const value_type& val);	
				void insert (iterator position, size_type n, const value_type& val);
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last);
				iterator erase (iterator position);
				iterator erase (iterator first, iterator last);
				void swap (vector& x);
				void clear();

	// Allocator

				allocator_type get_allocator() const;
		};

	// Non member functions overload

	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
