#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
		class stack
		{
			protected:
				Container c;

			public:
				typedef typename Container::value_type	value_type;
				typedef typename Container::size_type	size_type;
				typedef Container						container_type;

				explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {};

				bool empty() const { return c.empty(); };

				size_type size() const { return c.size(); };

				value_type& top() { return c.back(); };

				const value_type& top() const { return c.back(); };

				void push (const value_type& val) { c.push_back(val); };

				void pop() { c.pop_back(); };

				private:
					template<typename T1, typename Container1>
						friend bool	operator==(const stack<T1, Container1>&, const stack<T1, Container1>&);
					template<typename T1, typename Container1>
						friend bool	operator<(const stack<T1, Container1>&, const stack<T1, Container1>&);
		};

	// Non member functions overload

	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c == rhs.c; };
	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(lhs == rhs); };
	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; };
	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(rhs < lhs); };
	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return rhs < lhs; };
	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(lhs < rhs); };
}

#endif
