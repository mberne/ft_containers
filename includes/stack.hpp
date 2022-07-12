#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack : public std::vector<T>
	{
		private:
			typename T				value_type;
			typename Container		container_type;
			typename size_t			size_type;

		public:
			explicit stack (const container_type& ctnr = container_type());
			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			void pop();
	};

template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

}


#endif
