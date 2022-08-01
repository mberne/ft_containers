#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"

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
				size_type		_capacity;

			public:

	// Constructors

				explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _begin(NULL), _end(NULL), _size(0), _capacity(0) {}
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(n), _capacity(n) {
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
					_capacity = x.capacity;
					_begin = _allocator.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i)
						_allocator.construct(_begin + i, x[i]);
					_end = _begin + _size;
				}

	// Destructor

				~vector() {
					for (size_type i = 0; i < _size; ++i)
						_allocator.destroy(_begin + i);
					_allocator.deallocate(_begin, _capacity);
				}

	// Operator =

				vector	&operator=(vector const &x) {
					for (size_type i = 0; i < _size; ++i)
						_allocator.destroy(_begin + i);
					_allocator.deallocate(_begin, _capacity);
					_size = x._size;
					_capacity = x._capacity;
					_begin = _allocator.allocate(_capacity);
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

				size_type size() const										{ return _size; }
				size_type max_size() const									{ return _allocator.max_size(); }
				void resize (size_type n, value_type val = value_type())	{
					value_type	value = 0;
					if (n < _size)
					{
						for (size_type i = 0; i < _size - n; ++i)
							_allocator.destroy(_begin + n + i);
						_allocator.deallocate(_begin + _size, _size - n);
						_size = n;
						_end = begin + _size;
					}
					else if (n > _size)
					{
						_begin = _allocator.allocate(n - _size, _begin);
						if (val)
							for (size_type i = 0; i < n - _size; ++i)
								_allocator.construct(_end + i, val);
						_size = n;
						_end = begin + _size;
					}
				}
				size_type capacity() const									{ return _capacity; }
				bool empty() const											{ return _size == 0; }
				void reserve (size_type n)									{
					if (n > _capacity)
						_begin = _allocator.allocate(n - _capacity, _begin);
				}

	// Element access

				reference operator[] (size_type n)				{ return _begin + n; }
				const_reference operator[] (size_type n) const	{ return _begin + n; }
				reference at (size_type n)						{
					if (n >= _size)
						throw std::out_of_range("vector");
					return _begin + n;
				}
				const_reference at (size_type n) const			{
					if (n >= _size)
						throw std::out_of_range("vector");
					return _begin + n;
				}
				reference front()								{ return *_begin; }
				const_reference front() const					{ return *_begin; }
				reference back()								{ return *_end; }
				const_reference back() const					{ return *_end; }

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
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }
	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(lhs == rhs); }
	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }
	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(rhs < lhs); }
	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return rhs < lhs; }
	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)	{ return !(lhs < rhs); }
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
