#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <list>

#ifdef STD
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

using std::cout;
using std::endl;

class test_class
{
	public:
		test_class() : x(42), y(69) {}
		int x;
		int y;
};

void	fill_c(ft::vector<int>& c)
{
	c.push_back(42);
	c.push_back(69);
	c.push_back(420);
	c.push_back(12);
	c.push_back(4);
}

void	fill_c(ft::vector<std::string>& c)
{
	c.push_back("I");
	c.push_back("want");
	c.push_back("to");
	c.push_back("break");
	c.push_back("free !");
}

void	fill_c(std::list<int>& c)
{
	c.push_back(42);
	c.push_back(69);
	c.push_back(420);
	c.push_back(12);
	c.push_back(4);
}

void	fill_c(std::list<std::string>& c)
{
	c.push_back("I");
	c.push_back("want");
	c.push_back("to");
	c.push_back("break");
	c.push_back("free !");
}

template <typename T>
	void	print_c(ft::vector<T>& c)
	{
		cout << "Container specs:" << endl;
		cout << "Size[" << c.size() << "]" << endl;
		cout << "Capacity[" << c.capacity() << "]" << endl;
		cout << "Elements [" << endl;
		for(typename ft::vector<T>::iterator it = c.begin(); it != c.end(); it++)
			cout << *it << endl;
		cout << "]" << endl;
	}

void	test_vector()
{
	clock_t start_time = clock();
	
	cout << "----- TEST VECTOR -----" << endl;
	{
		//~~ Member types
		{
			cout << "~~ Member types ~~" << endl;
			if (typeid(ft::vector<int>::value_type)			!= typeid(std::vector<int>::value_type))
				cout << "Wrong type (value_type)" << endl;
			if (typeid(ft::vector<int>::allocator_type)		!= typeid(std::vector<int>::allocator_type))
				cout << "Wrong type (allocator_type)" << endl;
			if (typeid(ft::vector<int>::pointer)			!= typeid(std::vector<int>::pointer))
				cout << "Wrong type (pointer)" << endl;
			if (typeid(ft::vector<int>::const_pointer)		!= typeid(std::vector<int>::const_pointer))
				cout << "Wrong type (const_pointer)" << endl;
			if (typeid(ft::vector<int>::reference)			!= typeid(std::vector<int>::reference))
				cout << "Wrong type (reference)" << endl;
			if (typeid(ft::vector<int>::const_reference)	!= typeid(std::vector<int>::const_reference))
				cout << "Wrong type (const_reference)" << endl;
			if (typeid(ft::vector<int>::size_type)			!= typeid(std::vector<int>::size_type))
				cout << "Wrong type (size_type)" << endl;
			if (typeid(ft::vector<int>::difference_type)	!= typeid(std::vector<int>::difference_type))
				cout << "Wrong type (difference_type)" << endl;
		}		
		//~~ Constructors and operator=
		{
			cout << "~~ Default constructor ~~" << endl;
			ft::vector<int>			default_int;
			ft::vector<std::string>	default_str;
			fill_c(default_int);
			fill_c(default_str);
			print_c(default_int);
			print_c(default_str);

			cout << "~~ Fill constructor ~~" << endl;
			ft::vector<int>			fill_int(42, 42);
			ft::vector<std::string>	fill_str(42, "all work and no play makes Jack a dull boy");
			print_c(default_int);
			print_c(default_str);

			cout << "~~ Range constructor ~~" << endl;
			std::list<int>			lst_int;
			std::list<std::string>	lst_str;
			fill_c(lst_int);
			fill_c(lst_str);
			ft::vector<int>			range_int(lst_int.begin(), lst_int.end());
			ft::vector<std::string>	range_str(lst_str.begin(), lst_str.end());
			print_c(default_int);
			print_c(default_str);

			cout << "~~ Copy constructor ~~" << endl;
			ft::vector<int>			copy_int(default_int);
			ft::vector<std::string>	copy_str(default_str);
			print_c(default_int);
			print_c(default_str);

			cout << "~~ Operator= ~~" << endl;
			ft::vector<int>			operator_int;
			ft::vector<std::string>	operator_str;
			operator_int = default_int;
			operator_str = default_str;
			print_c(operator_int);
			print_c(operator_str);

			cout << "~~ Destructor ~~" << endl;
		}
		//~~ Iterators
		{
			cout << "~~ Iterator Member types ~~" << endl;
			if (typeid(ft::vector<int>::iterator::iterator_type)		!= typeid(std::vector<int>::iterator::iterator_type))
				cout << "Wrong type (iterator_type)" << endl;
			if (typeid(ft::vector<int>::iterator::iterator_category)	!= typeid(std::vector<int>::iterator::iterator_category))
				cout << "Wrong type (iterator_category)" << endl;
			if (typeid(ft::vector<int>::iterator::value_type)			!= typeid(std::vector<int>::iterator::value_type))
				cout << "Wrong type (value_type)" << endl;
			if (typeid(ft::vector<int>::iterator::difference_type)		!= typeid(std::vector<int>::iterator::difference_type))
				cout << "Wrong type (difference_type)" << endl;
			if (typeid(ft::vector<int>::iterator::reference)			!= typeid(std::vector<int>::iterator::reference))
				cout << "Wrong type (reference)" << endl;
			if (typeid(ft::vector<int>::iterator::pointer)				!= typeid(std::vector<int>::iterator::pointer))
				cout << "Wrong type (pointer)" << endl;
				
			cout << "~~ Const Iterator Member types ~~" << endl;
			if (typeid(ft::vector<int>::const_iterator::iterator_type)		!= typeid(std::vector<int>::const_iterator::iterator_type))
				cout << "Wrong type (iterator_type)" << endl;
			if (typeid(ft::vector<int>::const_iterator::iterator_category)	!= typeid(std::vector<int>::const_iterator::iterator_category))
				cout << "Wrong type (iterator_category)" << endl;
			if (typeid(ft::vector<int>::const_iterator::value_type)			!= typeid(std::vector<int>::const_iterator::value_type))
				cout << "Wrong type (value_type)" << endl;
			if (typeid(ft::vector<int>::const_iterator::difference_type)	!= typeid(std::vector<int>::const_iterator::difference_type))
				cout << "Wrong type (difference_type)" << endl;
			if (typeid(ft::vector<int>::const_iterator::reference)			!= typeid(std::vector<int>::const_iterator::reference))
				cout << "Wrong type (reference)" << endl;
			if (typeid(ft::vector<int>::const_iterator::pointer)			!= typeid(std::vector<int>::const_iterator::pointer))
				cout << "Wrong type (pointer)" << endl;

			cout << "~~ Iterator ~~" << endl;
			{
				ft::vector<int>			c_int;
				ft::vector<test_class>	c_class(5);
				fill_c(c_int);
				ft::vector<int>::iterator	it_int; 										// X a;
				it_int = c_int.begin();														// b = a;
				ft::vector<int>::iterator	it_int_copy(it_int);							// X a(b);
				cout << *it_int << endl;													// *a
				ft::vector<test_class>::iterator	it_class = c_class.begin();
				cout << it_class->x << "|" << it_class->y << endl;							// a->m
				cout << (*it_int = -42) << "|" << (it_int == it_int_copy) << endl;			// *a = t
				cout << (it_int == ++it_int) << endl;										// ++a
				cout << (it_int == it_int++) << endl;										// a++
				cout << (*it_int++) << endl;												// *a++
				cout << (it_int == --it_int) << endl;										// --a
				cout << (it_int == it_int--) << endl;										// a--
				cout << (*it_int--) << endl;												// *a--
				cout << *(it_int + 2) << endl;												// a + n
				cout << *(3 + it_int) << endl;												// n + a
				cout << *(c_int.end() - 2) << endl;											// a - n
				cout << it_int - it_int_copy << endl;										// a - b
				ft::vector<int>::const_iterator	it_int_end = (--(c_int.end()));
				it_int += 1;
				cout << (it_int == it_int_copy) << "|" << (it_int == it_int_end) << endl;	// a == b
				cout << (it_int != it_int_copy) << "|" << (it_int != it_int_end) << endl;	// a != b
				cout << (it_int < it_int_copy) << "|" << (it_int < it_int_end) << endl;		// a < b
				cout << (it_int > it_int_copy) << "|" << (it_int > it_int_end) << endl;		// a > b
				cout << (it_int <= it_int_copy) << "|" << (it_int <= it_int_end) << endl;	// a <= b
				cout << (it_int >= it_int_copy) << "|" << (it_int >= it_int_end) << endl;	// a >= b
				cout << *(it_int += 3) << endl;												// a += b
				cout << *(it_int -= 2) << endl;												// a -= b
				cout << it_int_copy[4] << endl;												// a[n]
				cout << *c_int.begin() << endl;
				cout << *(--(c_int.end())) << endl;
				cout << (*(c_int.begin()) - *(--(c_int.end()))) << endl;
				print_c(c_int);
			}

			cout << "~~ Reverse Iterator ~~" << endl;
			{
				ft::vector<int>			c_int;
				ft::vector<test_class>	c_class(5);
				fill_c(c_int);
				ft::vector<int>::reverse_iterator	it_int; 								// X a;
				it_int = c_int.rbegin();													// b = a;
				ft::vector<int>::reverse_iterator	it_int_copy(it_int);					// X a(b);
				cout << (*it_int) << endl;													// *a
				ft::vector<test_class>::reverse_iterator	it_class = c_class.rbegin();
				cout << it_class->x << "|" << it_class->y << endl;							// a->m
				cout << (*it_int = -42) << "|" << (it_int == it_int_copy) << endl;			// *a = t
				cout << (it_int == ++it_int) << endl;										// ++a
				cout << (it_int == it_int++) << endl;										// a++
				cout << (*it_int++) << endl;												// *a++
				cout << (it_int == --it_int) << endl;										// --a
				cout << (it_int == it_int--) << endl;										// a--
				cout << (*it_int--) << endl;												// *a--
				cout << *(it_int + 2) << endl;												// a + n
				cout << *(3 + it_int) << endl;												// n + a
				cout << *(c_int.rend() - 2) << endl;										// a - n
				cout << it_int - it_int_copy << endl;										// a - b
				ft::vector<int>::const_reverse_iterator	it_int_end = (--(c_int.rend()));
				it_int += 1;
				cout << (it_int == it_int_copy) << "|" << (it_int == it_int_end) << endl;	// a == b
				cout << (it_int != it_int_copy) << "|" << (it_int != it_int_end) << endl;	// a != b
				cout << (it_int < it_int_copy) << "|" << (it_int < it_int_end) << endl;		// a < b
				cout << (it_int > it_int_copy) << "|" << (it_int > it_int_end) << endl;		// a > b
				cout << (it_int <= it_int_copy) << "|" << (it_int <= it_int_end) << endl;	// a <= b
				cout << (it_int >= it_int_copy) << "|" << (it_int >= it_int_end) << endl;	// a >= b
				cout << *(it_int += 3) << endl;												// a += b
				cout << *(it_int -= 2) << endl;												// a -= b
				cout << it_int_copy[4] << endl;												// a[n]
				print_c(c_int);
				cout << *c_int.rbegin() << endl;
				cout << *(--(c_int.rend())) << endl;
				cout << ((*c_int.rbegin()) - *(--(c_int.rend()))) << endl;
			}
		}
		//~~ Capacity
		{
			cout << "~~ Capacity ~~" << endl;
			ft::vector<int>	c_int;
			cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
			c_int.reserve(40);
			cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
			fill_c(c_int);
			fill_c(c_int);
			cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
			c_int.resize(20);
			cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
			print_c(c_int);
			c_int.reserve(10);
			cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
			c_int.resize(5);
			cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
			print_c(c_int);
			try { c_int.reserve(static_cast<unsigned long long>(c_int.max_size()) + 10); }
			catch (std::length_error& e) { cout << "exception thrown" << endl; }
		}
		//~~ Element Access
		{
			ft::vector<int>			c_int;
			ft::vector<std::string>	c_str;
			fill_c(c_int);
			fill_c(c_str);
			const ft::vector<int>	c_int_const(c_int);

			cout << "~~ operator[] and at() ~~" << endl;
			for(int i = 0; i < 5; i++)
			{
				cout << c_int[i] << "|" << c_str[i] << "|" << c_int_const[i] << endl;
				cout << c_int.at(i) << "|" << c_str.at(i) << "|" << c_int_const.at(i) << endl;
			}
			try { cout << c_int.at(100); }
			catch(const std::out_of_range& e) { cout << "exception thrown" << endl; }

			cout << "~~ front() and back() ~~" << endl;
			cout << c_int.front() << "|" << c_str.front() << "|" << c_int_const.front() << endl;
			cout << c_int.back() << "|" << c_str.back() << "|" << c_int_const.back() << endl;
		}
		//~~ Modifiers
		{
			cout << "~~ assign() ~~" << endl;
			//~~ Range
			ft::vector<int>	c_int;
			std::list<int>	lst;
			fill_c(lst);
			c_int.assign(lst.begin(), lst.end());
			print_c(c_int);
			std::list<std::string> lst2;
			fill_c(lst2);
			fill_c(lst);
			c_int.assign(lst.begin(), lst.end());
			print_c(c_int);
			c_int.assign(lst.begin(), lst.begin());
			print_c(c_int);
			lst.clear();
			c_int.assign(lst.begin(), lst.end());
			print_c(c_int);
			//~~ Fill
			c_int.assign(20, 20);
			print_c(c_int);
			c_int.assign(10, 10);
			print_c(c_int);
			c_int.assign(30, 30);
			print_c(c_int);

			cout << "~~ push_back() and pop_back() ~~" << endl;
			while (c_int.size() != c_int.capacity())
				c_int.push_back(42);
			print_c(c_int);
			c_int.push_back(42);
			print_c(c_int);
			c_int.pop_back();
			c_int.pop_back();
			c_int.pop_back();
			c_int.pop_back();
			c_int.pop_back();
			c_int.pop_back();
			print_c(c_int);

			cout << "~~ insert() ~~" << endl;
			//~~ Single Element
			cout << *(c_int.insert(c_int.begin() + 15, 42)) << endl;
			print_c(c_int);
			cout << *(c_int.insert(c_int.end(), 42)) << endl;
			print_c(c_int);
			cout << *(c_int.insert(c_int.begin(), 42)) << endl;
			print_c(c_int);
			while (c_int.size() != c_int.capacity())
				c_int.push_back(42);
			cout << *(c_int.insert(c_int.begin() + 15, 42)) << endl;
			print_c(c_int);
			//~~ Fill
			c_int.insert(c_int.begin() + 15, 0, 42);
			print_c(c_int);
			c_int.insert(c_int.begin() + 15, 3, 42);
			print_c(c_int);
			c_int.insert(c_int.end(), 3, 42);
			print_c(c_int);
			c_int.insert(c_int.end() - 4, 3, 42);
			print_c(c_int);
			c_int.insert(c_int.begin(), 3, 42);
			print_c(c_int);
			c_int.insert(c_int.begin() + 15, 60, 10);
			print_c(c_int);
			try { c_int.insert(c_int.begin(), static_cast<unsigned long long>(c_int.max_size()) + 10, 42); }
			catch (std::length_error& e) { cout << "exception thrown" << endl; }
			//~~ Range
			fill_c(lst);
			c_int.insert(c_int.begin(), lst.begin(), lst.begin());
			print_c(c_int);
			c_int.insert(c_int.begin() + 15, lst.begin(), lst.end());
			print_c(c_int);
			c_int.insert(c_int.end(), lst.begin(), lst.end());
			print_c(c_int);
			c_int.insert(c_int.end() - 3, lst.begin(), lst.end());
			print_c(c_int);
			c_int.insert(c_int.begin(), lst.begin(), lst.end());
			print_c(c_int);
			c_int.insert(c_int.begin() + 30, c_int.begin(), c_int.end());
			print_c(c_int);	
			cout << "~~ erase() ~~" << endl;
			cout << *(c_int.erase(c_int.begin() + 20)) << endl;
			print_c(c_int);
			cout << *(c_int.erase(c_int.begin())) << endl;
			print_c(c_int);
			cout << *(c_int.erase(c_int.end() - 1)) << endl;
			print_c(c_int);
			cout << *(c_int.erase(c_int.end() - 5, c_int.end() - 3)) << endl;
			print_c(c_int);
			cout << *(c_int.erase(c_int.begin(), c_int.begin() + 5)) << endl;
			print_c(c_int);
			cout << *(c_int.erase(c_int.begin() + 5, c_int.begin() + 5)) << endl;
			print_c(c_int);
			cout << *(c_int.erase(c_int.begin(), c_int.end() - 1)) << endl;
			print_c(c_int);
			
			cout << "~~ clear() and swap() ~~" << endl;
			c_int.clear();
			fill_c(lst);
			ft::vector<int>	c_int2(lst.begin(), lst.end());
			print_c(c_int);
			print_c(c_int2);
			c_int.swap(c_int2);
			print_c(c_int);
			print_c(c_int2);
		}
		//~~ Allocator
		{
			cout << "~~ get_allocator() ~~" << endl;
			ft::vector<int>			c_int;
			ft::vector<std::string>	c_str;
			fill_c(c_int);
			fill_c(c_str);
			ft::vector<int>::allocator_type alloc_c_int = c_int.get_allocator();
			ft::vector<std::string>::allocator_type alloc_c_str = c_str.get_allocator();
			alloc_c_int = c_str.get_allocator();
			alloc_c_str = c_int.get_allocator();
			c_int.erase(c_int.begin());
			c_str.erase(c_str.begin());
			c_int.insert(c_int.begin() + 2, 12, 12);
			c_str.insert(c_str.begin() + 2, 12, "No you don't");
		}
		//~~ Relational Operators
		{
			cout << "~~ Relational Operators ~~" << endl;
			ft::vector<std::string>	c_str1;
			ft::vector<std::string>	c_str2;
			fill_c(c_str1);
			fill_c(c_str2);
			ft::vector<std::string> const	c_str_const(c_str1.begin(), c_str1.end() - 2);
			//~~ c_str1 = c_str2
			cout << (c_str1 == c_str2) << endl;
			cout << (c_str1 != c_str2) << endl;
			cout << (c_str1 < c_str2) << endl;
			cout << (c_str1 > c_str2) << endl;
			cout << (c_str1 <= c_str2) << endl;
			cout << (c_str1 >= c_str2) << endl;
			fill_c(c_str2);
			//~~ c_str1 < c_str2
			cout << (c_str1 == c_str2) << endl;
			cout << (c_str1 != c_str2) << endl;
			cout << (c_str1 < c_str2) << endl;
			cout << (c_str1 > c_str2) << endl;
			cout << (c_str1 <= c_str2) << endl;
			cout << (c_str1 >= c_str2) << endl;
			//~~ c_str2 < c_str1
			cout << (c_str2 == c_str1) << endl;
			cout << (c_str2 != c_str1) << endl;
			cout << (c_str2 < c_str1) << endl;
			cout << (c_str2 > c_str1) << endl;
			cout << (c_str2 <= c_str1) << endl;
			cout << (c_str2 >= c_str1) << endl;
			//~~ c_str1 > c_str_const
			cout << (c_str1 == c_str_const) << endl;
			cout << (c_str1 != c_str_const) << endl;
			cout << (c_str1 < c_str_const) << endl;
			cout << (c_str1 > c_str_const) << endl;
			cout << (c_str1 <= c_str_const) << endl;
			cout << (c_str1 >= c_str_const) << endl;
			print_c(c_str1);
			print_c(c_str2);
			swap(c_str1, c_str2);
			print_c(c_str1);
			print_c(c_str2);
		}
	}
	clock_t	test_time = clock() - start_time;
	cout << endl << "Time: " << ((float)test_time)/CLOCKS_PER_SEC << endl;
}
