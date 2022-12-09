#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template<typename Iterator>
		class reverse_iterator
		{
			protected:
				typedef	iterator_traits<Iterator>	traits_type;
				Iterator							current;

			public:
				typedef typename traits_type::difference_type	difference_type;
				typedef typename traits_type::pointer			pointer;
				typedef typename traits_type::reference			reference;
				typedef Iterator								iterator_type;

	// Constructors

				reverse_iterator() {}
				explicit reverse_iterator (iterator_type it) : current(it) {}
				reverse_iterator (const reverse_iterator<Iterator>& rev_it) : current(rev_it.current) {}
				template<typename It>
					reverse_iterator(const reverse_iterator<It>& src) : current(src.base()) {}

	// Operator =

				reverse_iterator&	operator=(const reverse_iterator& rhs) {
					if (this != &rhs)
						current = rhs.base();
					return *this;
				}
			
	// Member functions

				const iterator_type	base() const { return current; }
				reference			operator*() const { iterator_type tmp = current; return *--tmp; }
				pointer				operator->() const { iterator_type tmp = current; --tmp; return tmp.operator->(); }
				reverse_iterator	&operator++() {
					--current;
					return *this;
				}
				reverse_iterator	operator++(int) {
					reverse_iterator	tmp = *this;
					--current;
					return tmp;
				}
				reverse_iterator	&operator--() {
					++current;
					return *this;
				}
				reverse_iterator	operator--(int) {
					reverse_iterator	tmp = *this;
					++current;
					return tmp;
				}
				reverse_iterator	operator+(difference_type n) const { return reverse_iterator(current - n); }
				reverse_iterator	operator-(difference_type n) const { return reverse_iterator(current + n); }
				reverse_iterator	&operator+=(difference_type n) {
					current -= n;
					return *this;
				}
				reverse_iterator	&operator-=(difference_type n) {
					current += n;
					return *this;
				}
				reference			operator[](difference_type n) const { return *(*this + n); }
		};

	// Non member functions overload

	template<typename Iterator>
		inline bool	operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return lhs.base() == rhs.base(); }
	template<typename ItL, typename ItR>
		inline bool	operator==(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return lhs.base() == rhs.base(); }
	template<typename Iterator>
		inline bool	operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return lhs.base() != rhs.base(); }
	template<typename ItL, typename ItR>
		inline bool	operator!=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return lhs.base() != rhs.base(); }
	template<typename Iterator>
		inline bool	operator< (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return lhs.base() > rhs.base(); }
	template<typename ItL, typename ItR>
		inline bool		operator<(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return lhs.base() > rhs.base(); }
	template<typename Iterator>
		inline bool	operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return lhs.base() >= rhs.base(); }
	template<typename ItL, typename ItR>
		inline bool		operator<=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return lhs.base() >= rhs.base(); }
	template<typename Iterator>
		inline bool	operator> (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return lhs.base() < rhs.base(); }
	template<typename ItL, typename ItR>
		inline bool		operator>(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return lhs.base() < rhs.base(); }
	template<typename Iterator>
		inline bool	operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return lhs.base() <= rhs.base(); }
	template<typename ItL, typename ItR>
		inline bool		operator>=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return lhs.base() <= rhs.base(); }
	template<typename Iterator>
  		inline reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) { return reverse_iterator<Iterator>(rev_it.base() - n); }
	template<typename Iterator>
		inline typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (rhs.base() - lhs.base()); }
	template<typename ItL, typename ItR>
		inline typename reverse_iterator<ItL>::difference_type		operator-(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs) { return rhs.base() - lhs.base(); }
}

#endif
