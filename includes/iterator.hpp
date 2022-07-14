#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	struct random_access_iterator_tag {};

	template<typename T>
	class vector_iterator
	{
		protected:
			typedef	iterator_traits<T>	traits_type;
			T							current;

		public:
			typedef typename traits_type::difference_type	difference_type;
			typedef typename traits_type::value_type		value_type;
			typedef typename traits_type::pointer			pointer;
			typedef typename traits_type::reference			reference;
			typedef typename traits_type::iterator_category	iterator_category;

		// Constructors

			vector_iterator() {}
			vector_iterator(vector_iterator const &src) : current(src.current) {}

		// Destructor

			~vector_iterator() {}

		// Operator =

			vector_iterator	&operator=(vector_iterator const &rhs) {
				if (this != &rhs)
					this->current = rhs.current;
				return *this;
			}

		// Member functions

			reference operator*() {
				return *current;
			}

			vector_iterator operator+(difference_type n) {
				return vector_iterator(current + n);
			}

			vector_iterator operator-(difference_type n) {
				return vector_iterator(current - n);
			}

			vector_iterator &operator++() {
				++current;
				return *this;
			}

			// vector_iterator &operator++(int) {
			// 	++current;
			// 	return *this;
			// }

			vector_iterator &operator--() {
				--current;
				return *this;
			}

			// bool operator<(vector_iterator const &rhs) {
			// 	return ;
			// }

			vector_iterator &operator+=(difference_type n) {
				current += n;
				return *this;
			}

			vector_iterator &operator-=(difference_type n) {
				current -= n;
				return *this;
			}
	};

// template<?>
// class map_iterator<?>
// {
// 	typedef bidirectional_iterator_tag 
// }

}

#endif
