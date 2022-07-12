#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {
	struct random_access_iterator_tag {};

	template<class _Iterator>
	class __normal_iterator {
		public:
			typedef iterator_traits<_Iterator>			__traits_type;
			typedef __traits_type::difference_type		difference_type;
			typedef __traits_type::value_type			value_type;
			typedef __traits_type::pointer				pointer;
			typedef __traits_type::reference			reference;
			typedef __traits_type::iterator_category	iterator_category;

		private:
			pointer	__ptr;

		public:

// Constructors

			__normal_iterator() {}
			__normal_iterator(pointer ptr) : __ptr(ptr) {}
			__normal_iterator(__normal_iterator const &src) {*this = src}

// Destructor

			~__normal_iterator() {}

// Operator =

			// __normal_iterator	&operator=(__normal_iterator const &rhs) {
			// 	if (this != &rhs)
			// 		this->__ptr = rhs.__ptr;
			// 	return *this;
			// }

// Member functions

			reference operator*() {
				return *__ptr;
			}

			__normal_iterator operator+(difference_type n) {
				return __normal_iterator(__ptr + n);
			}

			__normal_iterator operator-(difference_type n) {
				return __normal_iterator(__ptr - n);
			}

			__normal_iterator &operator++() {
				++__ptr;
				return *this;
			}

			__normal_iterator &operator--() {
				--__ptr;
				return *this;
			}

			bool operator<(__normal_iterator const &rhs) {
				return 
			}

			__normal_iterator &operator+=(difference_type n) {
				ptr += n;
				return *this;
			}

			__normal_iterator &operator-=(difference_type n) {
				ptr - = n;
				return *this;
			}

			// lot of operators here https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
	};
}

#endif
