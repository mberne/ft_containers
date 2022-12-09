#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

#ifdef STD
	#include <stack>
	namespace ft = std;
#else
	#include "stack.hpp"
#endif

#include <vector>
#include <deque>
#include <list>

template<typename Container>
class MutantStack : public Container
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<Container>& src) : Container::c(src.c) {}
		~MutantStack() {}

		typedef typename Container::container_type::iterator iterator;

		MutantStack<Container>& operator=(const MutantStack<Container>& rhs) 
		{
			this->c = rhs.c;
			return *this;
		}

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
}; //~~ class MutantStack

template<typename Container>
	void	fill_c(ft::stack<int, Container>& c)
	{
		c.push(42);
		c.push(69);
		c.push(420);
		c.push(12);
		c.push(4);
	}

template<typename Container>
	void	fill_c(ft::stack<std::string, Container>& c)
	{
		c.push("I");
		c.push("want");
		c.push("to");
		c.push("break");
		c.push("free !");
	}

template<typename T, typename Container>
	void	do_tests(ft::stack<T, Container>& c)
	{
		try
		{
			std::cout << "Testing class methods" << std::endl;

			std::cout << c.empty() << std::endl;
			std::cout << c.size() << std::endl;

			fill_c(c);

			std::cout << c.empty() << std::endl;
			std::cout << c.size() << std::endl;
			std::cout << c.top() << std::endl;

			c.pop();
			c.pop();

			std::cout << c.empty() << std::endl;
			std::cout << c.size() << std::endl;
			std::cout << c.top() << std::endl;

			c.pop();
			c.pop();
			c.pop();

			std::cout << c.empty() << std::endl;
			std::cout << c.size() << std::endl;

			std::cout << "Testing class operators" << std::endl;

			fill_c(c);

			Container tmp;
			ft::stack<T, Container> c2(tmp);

			fill_c(c2);

			std::cout << (c == c2) << std::endl;
			std::cout << (c != c2) << std::endl;
			std::cout << (c < c2) << std::endl;
			std::cout << (c <= c2) << std::endl;
			std::cout << (c > c2) << std::endl;
			std::cout << (c >= c2) << std::endl;

			c2.pop();
			fill_c(c2);

			std::cout << (c == c2) << std::endl;
			std::cout << (c != c2) << std::endl;
			std::cout << (c < c2) << std::endl;
			std::cout << (c <= c2) << std::endl;
			std::cout << (c > c2) << std::endl;
			std::cout << (c >= c2) << std::endl;
		}
		catch(...)
		{
			std::cout << "An error occured." << std::endl;
		}
	} //~~ do_tests


void	test_stack()
{
	clock_t start_time = clock();

	std::cout << "----- TEST STACK -----" << std::endl << std::endl;
	{
		std::cout << "~~ Testing with vector<int> ~~" << std::endl;
		{
			std::vector<int>					tmp;
			ft::stack<int, std::vector<int> >	c(tmp);
			do_tests(c);
		}
		std::cout << "~~ Testing with vector<std::string> ~~" << std::endl;
		{
			std::vector<std::string>							tmp;
			ft::stack<std::string, std::vector<std::string> >	c(tmp);
			do_tests(c);
		}
		std::cout << "~~ Testing with deque<int> ~~" << std::endl;
		{
			std::deque<int>						tmp;
			ft::stack<int, std::deque<int> >	c(tmp);
			do_tests(c);
		}
		std::cout << "~~ Testing with deque<std::string> ~~" << std::endl;
		{
			std::deque<std::string>								tmp;
			ft::stack<std::string, std::deque<std::string> >	c(tmp);
			do_tests(c);
		}
		std::cout << "~~ Testing with list<int> ~~" << std::endl;
		{
			std::list<int>						tmp;
			ft::stack<int, std::list<int> >		c(tmp);
			do_tests(c);
		}
		std::cout << "~~ Testing with list<std::string> ~~" << std::endl;
		{
			std::list<std::string>								tmp;
			ft::stack<std::string, std::list<std::string> >		c(tmp);
			do_tests(c);
		}
		std::cout << "~~ Testing inheritance ~~" << std::endl;
		try
		{
			MutantStack<ft::stack<int, std::vector<int> > >	mut_c;

			mut_c.push(42);
			mut_c.push(69);
			mut_c.push(420);
			mut_c.push(12);
			mut_c.push(4);

			std::cout << *mut_c.begin() << std::endl;
			std::cout << *(mut_c.end() - 1) << std::endl;
			std::cout << mut_c.end() - mut_c.begin() << std::endl;
		}
		catch(...)
		{
			std::cout << "An error occured." << std::endl;
		}

		clock_t	test_time = clock() - start_time;
		std::cout << std::endl << "Time: " << ((float)test_time)/CLOCKS_PER_SEC << std::endl;
	}
}
