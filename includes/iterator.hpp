#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include  <cstddef>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template<typename T>
		class vector_iterator
		{
			protected:
				typedef	iterator_traits<T>	traits_type;
				T							current;

			public:
				typedef typename traits_type::difference_type	difference_type;
				typedef T										iterator_type;
				typedef typename traits_type::value_type		value_type;
				typedef typename traits_type::pointer			pointer;
				typedef typename traits_type::reference			reference;
				typedef typename traits_type::iterator_category	iterator_category;

			// Constructors

				vector_iterator() {}
				vector_iterator(const T &src) : current(src) {}
				template<typename T2>
    				vector_iterator(const vector_iterator<T2>& src) : current(src.base()) {}

			// Member functions

				reference 				operator*() const { return *current; }
				pointer					operator->() const { return current; }
				vector_iterator 		&operator++() {
					++current;
					return *this;
				}
				vector_iterator 		operator++(int) {
					return vector_iterator(current++);
				}
				vector_iterator 		&operator--() {
					--current;
					return *this;
				}
				vector_iterator 		operator--(int) {
					return vector_iterator(current--);
				}
				vector_iterator 		operator+(difference_type n) const { return vector_iterator(current + n); }
				vector_iterator 		operator-(difference_type n) const { return vector_iterator(current - n); }
				vector_iterator 		&operator+=(difference_type n) {
					current += n;
					return *this;
				}
				vector_iterator 		&operator-=(difference_type n) {
					current -= n;
					return *this;
				}
				reference 				operator[](difference_type n) const { return *(current + n); }
				const  iterator_type	&base() const { return current; }
		};

		template<typename ItL, typename ItR>
			inline bool		operator==(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() == rhs.base(); }
		template<typename Iterator>
			inline bool		operator==(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); }
		template<typename ItL, typename ItR>
			inline bool		operator!=(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() != rhs.base(); }
		template<typename Iterator>
			inline bool		operator!=(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }
		template<typename ItL, typename ItR>
			inline bool		operator<(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() < rhs.base(); }
		template<typename Iterator>
			inline bool		operator<(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() < rhs.base(); }
		template<typename ItL, typename ItR>
			inline bool		operator>(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() > rhs.base(); }
		template<typename Iterator>
			inline bool		operator>(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() > rhs.base(); }
		template<typename ItL, typename ItR>
			inline bool		operator<=(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() <= rhs.base(); }
		template<typename Iterator>
			inline bool		operator<=(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); }
		template<typename ItL, typename ItR>
			inline bool		operator>=(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() >= rhs.base(); }
		template<typename Iterator>
			inline bool		operator>=(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() >= rhs.base(); }
		template<typename Iterator>
			inline vector_iterator<Iterator>							operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& it) { return vector_iterator<Iterator>(it.base() + n); }
		template<typename ItL, typename ItR>
			inline typename vector_iterator<ItL>::difference_type		operator-(const vector_iterator<ItL>& lhs, const vector_iterator<ItR>& rhs) { return lhs.base() - rhs.base(); }
		template<typename Iterator>
			inline typename vector_iterator<Iterator>::difference_type	operator-(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) { return lhs.base() - rhs.base(); }
}

#endif
