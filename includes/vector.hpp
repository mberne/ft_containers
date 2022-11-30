#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
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
				pointer			_end_of_storage;

			public:

	// Constructors

				explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _begin(NULL), _end(NULL), _end_of_storage(NULL) {}
				
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc) {
					_begin = _allocator.allocate(n);
					_fill_vector(_begin, n, val);
					_end = _begin + n;
					_end_of_storage = _end;
				}

				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _allocator(alloc) {
						InputIterator tmp = first;
						size_type i = 0;

						while (tmp != last)
						{
							++tmp;
							++i;
						}
						_begin = _allocator.allocate(i);
						_end = _construct_with_copy(first, last, begin());
						_end_of_storage = _begin + i;
					}

				vector(const vector &x) : _allocator(x.get_allocator()) {
					_begin = _allocator.allocate(x.size());
					_end = _construct_with_copy(x.begin(), x.end(), begin());
					_end_of_storage = _end;
				}

	// Destructor

				~vector() {
					_destroy(begin(), end());
					_allocator.deallocate(_begin, capacity());
				}

	// Operator=

				vector	&operator=(vector const &x) {
					if (&x != this)
					{
						if (x.size() > capacity())
						{
							pointer new_begin = _allocator.allocate(x.size());
							_construct_with_copy(x.begin(), x.end(), new_begin);
							_destroy(begin(), end());
							_allocator.deallocate(_begin, capacity());
							_begin = new_begin;
							_end = _begin + x.size();
							_end_of_storage = _end;
						}
						else if (x.size() < size())
						{
							_destroy(_copy(x.begin(), x.end(), begin()), end());
							_end = _begin + x.size();
						}
						else
							_copy(x.begin(), x.end(), begin());
					}
					return *this;
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

				size_type size() const										{ return _end - _begin; }

				size_type max_size() const									{ return _allocator.max_size(); }

				void resize(size_type n, value_type val = value_type())	{
					if (n < size())
					{
						_destroy(begin() + n, end());
						_end = _begin + n;
					}
					else if (n > size())
					{
						if (n > capacity())
							_reallocate_with_save(n - size(), begin(), end());
						_fill_vector(_end, n - size(), val);
						_end = _end + n - size();
					}
				}

				size_type capacity() const									{ return _end_of_storage - _begin; }

				bool empty() const											{ return size() == 0; }

				void reserve(size_type n)									{
					if (n > capacity())
					{
						if (n > max_size())
							throw std::length_error("you tried to exceed maximum supported size");
						else
							_reallocate_with_save(n - size(), begin(), end());
					}
				}

	// Element access

				reference operator[] (size_type n)				{ return *(_begin + n); }

				const_reference operator[] (size_type n) const	{ return *(_begin + n); }

				reference at (size_type n)						{
					if (n >= size())
						throw std::out_of_range("you tried to exceed memory not allocated");
					return *(_begin + n);
				}

				const_reference at (size_type n) const			{
					if (n >= size())
						throw std::out_of_range("you tried to exceed memory not allocated");
					return *(_begin + n);
				}

				reference front()								{ return *begin(); }

				const_reference front() const					{ return *begin(); }

				reference back()								{ return *(end() - 1); }

				const_reference back() const					{ return *(end() - 1); }

	// Modifiers

				template <class InputIterator>
					void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
						InputIterator tmp = first;
						size_type i = 0;

						clear();
						for (; tmp != last; ++tmp)
							i++;
						if (i > capacity())
							_reallocate(i);
						_end = _construct_with_copy(first, last, begin());
					}

				void assign (size_type n, const value_type& val) {
					clear();
					if (n > capacity())
						_reallocate(n);
					_fill_vector(_begin, n, val);
					_end = _begin + n;
				}

				void push_back (const value_type& val) {
					if (size() == capacity())
						_reallocate_insert(begin() , end());
					_allocator.construct(_end, val);
					++_end;
				}

				void pop_back() {
					_allocator.destroy(_end - 1);
					--_end;
				}

				iterator insert (iterator position, const value_type& val) {
					const size_type	n = position - begin();
					// if (_end == _end_of_storage)
					// 	_reallocate_insert(begin(), end());
					// {
					// 	if (position == end())
					// 	{
					// 		_allocator.construct(_end, val);
					// 		++_end;
					// 	}
					// 	else
					// 	{
					// 		_allocator.construct(_end, *(_end - 1));
					// 		++_end;
					// 		_copy_backward(position, end() - 2, end() - 1);
					// 		*position = val;
					// 	}
					// }
					// return begin() + n;

					if (_end == _end_of_storage)
						_reallocate_insert(begin(), end());
					else if (position == end())
					{
						_allocator.construct(_end, val);
						++_end;
						return begin() + n;
					}
					iterator	new_position = _begin + n;
					_allocator.construct(_end, *(_end - 1));
					++_end;
					_copy_backward(new_position, end() - 2, end() - 1);
					*new_position = val;
					return new_position;
				};

				void insert (iterator position, size_type n, const value_type& val) {
					if (n != 0)
					{
						if (static_cast<size_type>(_end_of_storage - _end) >= n)
						{
							pointer			old_end = _end;
							const size_type	elems_after = end() - position;
							try
							{
								if (elems_after > n)
								{
									_end = _construct_with_copy(end() - n, end(), _end);
									_copy_backward(position, old_end - n, old_end);
									_fill(position, position + n, val);
								}
								else
								{
									size_type tmp = n - elems_after;
									_fill_vector(_end, tmp, val);
									_end += (tmp);
									_copy(position, iterator(old_end), end());
									_end += elems_after;
									_fill(position, old_end, val);
								}
							}
							catch(...)
							{
								_destroy(end(), end() + n);
								throw;
							}
						}
						else
						{
							const size_type len = check_len(n, "vector::insert");
							const size_type elems_before = position - begin();
							pointer new_begin = _allocator.allocate(len);
							pointer new_end = new_begin;
							try
							{
								_fill_vector(new_begin + elems_before, n, val);
								new_end = _construct_with_copy(_begin, position.base(), new_begin);
								new_end += n;
								new_end = _construct_with_copy (position.base(), _end, new_end);
							}
							catch(...)
							{
								_destroy(new_begin, new_end);
								throw;
							}
							_destroy(begin(), end());
							_allocator.deallocate(_begin, capacity());
							_begin = new_begin;
							_end = new_end;
							_end_of_storage = new_begin + len;
						}
					}
				};

				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
						if (position == end())
						{
							for (; first != last; ++first)
								insert(end(), *first);
						}
						else if (first != last)
						{
							vector tmp(first, last);
							_insert_range(position, tmp.begin(), tmp.end());
						}
					};

			private:

				void _insert_range (iterator position, iterator first, iterator last) {
					const size_type	n = last - first;

					if (static_cast<size_type>(_end_of_storage - _end) >= n)
					{
						const size_type	elems_after = end() - position;
						pointer			old_end = _end;
						if (elems_after > n)
						{
							_end = _construct_with_copy(_end - n, _end, _end);
							_copy_backward(position.base(), old_end - n, old_end);
							_copy(first, last, position);
						}
						else
						{
							iterator mid = first;
							mid += elems_after;
							_end = _construct_with_copy(mid, last, _end);
							_end = _construct_with_copy(position.base(), old_end, _end);
							_copy(first, mid, position);
						}
					}
					else
					{
						const size_type len = check_len(n, "vector::_insert_range");
						pointer	new_begin = _allocator.allocate(len);
						pointer	new_end = new_begin;
						try
						{
							new_end = _construct_with_copy(_begin, position.base(), new_begin);
							new_end = _construct_with_copy(first, last, new_end);
							new_end = _construct_with_copy(position.base(), _end, new_end);
						}
						catch(...)
						{
							_destroy(new_begin, new_end);
							_allocator.deallocate(new_begin, len);
							throw;
						}
						_destroy(_begin, _end);
						_allocator.deallocate(_begin, capacity());
						_begin = new_begin;
						_end = new_end;
						_end_of_storage = new_begin + len;
					}
				};

			public:

				iterator erase (iterator position) {
					if (position + 1 != end())
						_copy(position + 1, end(), position);
					--_end;
					_allocator.destroy(_end);
					return position;
				};

				iterator erase (iterator first, iterator last) {
					if (first != last)
					{
						iterator new_end = _copy(last, end(), first);
						_destroy(new_end, end());
						_end = new_end.base();
					}
					return first;
				};

				void swap (vector& x) {
					std::swap(_allocator, x._allocator);
					std::swap(_begin, x._begin);
					std::swap(_end, x._end);
					std::swap(_end_of_storage, x._end_of_storage);
				}

				void clear() {
					_destroy(begin(), end());
					_end = _begin;
				}

	// Allocator

				allocator_type	get_allocator() const { return allocator_type(_allocator); }

	// Utils

			protected :

				void	_fill_vector(pointer current, size_type n, const value_type& val)
				{
					pointer tmp = current;

					try
					{
						for (; n > 0; --n, ++current)
                		_allocator.construct(current, val);
					}
					catch(...)
					{
						_destroy(tmp, current);
						throw;
					}
				}

				void	_reallocate(size_type n) {
					_allocator.deallocate(_begin, capacity());
					const size_type len = check_len(n, "vector::_reallocate");
					_begin = _allocator.allocate(len);
					_end = _begin;
					_end_of_storage = _begin + len;
				}

				template <class InputIterator>
					void	_reallocate_with_save(size_type n, InputIterator first, InputIterator last) {
						const size_type len = check_len(n, "vector::_reallocate_with_save");
						pointer new_begin = _allocator.allocate(len);
						pointer new_end = new_begin + size();

						try
						{
							_construct_with_copy(first, last, new_begin);
							clear();
							_allocator.deallocate(_begin, capacity());
							_begin = new_begin;
							_end = new_end;
							_end_of_storage = new_begin + len;
						}
						catch(...)
						{
							_allocator.deallocate(new_begin, size());
							throw;
						}
						
					}

				template <class InputIterator>
					void	_reallocate_insert(InputIterator first, InputIterator last) {
						const size_type len = check_len(1, "vector::_reallocate_insert");
						pointer new_begin = _allocator.allocate(len);
						pointer new_end = new_begin + size();
						try
						{
							_construct_with_copy(first, last, new_begin);
							clear();
							_allocator.deallocate(_begin, capacity());
							_begin = new_begin;
							_end = new_end;
							_end_of_storage = new_begin + len;
						}
						catch(...)
						{
							_allocator.deallocate(new_begin, size());
							throw;
						}
					}

				template <class InputIterator>
					pointer	_construct_with_copy(InputIterator first, InputIterator last, iterator current)
					{
						iterator tmp = current;

						try
						{
							for (; first != last; ++first, ++current)
							{
								_allocator.construct(_allocator.address(*current), *first);
							}
							return _allocator.address(*current);
						}
						catch(...)
						{
							_destroy(tmp, current);
							throw;
						}
					}

				template <class InputIterator>
					iterator	_copy(InputIterator first, InputIterator last, iterator current)
					{
						for (; first != last; ++first, ++current)
							*current = *first;
						return current;
					}

				template <class InputIterator>
					void	_destroy(InputIterator first, InputIterator last)
					{
						for (; first != last; ++first)
							_allocator.destroy(_allocator.address(*first));
					}

				void _copy_backward(iterator first, iterator last, iterator current)
				{
					while (first != last)
						 *--current = *--last;
				}

				void _fill(iterator first, iterator last, const value_type& val)
				{
					for (; first != last; ++first)
						*first = val;
				}

				size_type	check_len(size_type n, const char* str) const
				{
					if (max_size() - size() < n)
						throw std::length_error(str);
					const size_type len = size() + (std::max)(size(), n);
					if (len < size() || len > max_size())
						return max_size();
					return len;
				}
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
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)							{ x.swap(y); }
}

#endif
