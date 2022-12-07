#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <map>
#include <list>

#ifdef STD
	namespace ft = std;
#else
	#include "map.hpp"
#endif

using std::cout;
using std::endl;

// class test_class
// {
// 	public:
// 		test_class() : x(42), y(69) {}
// 		int x;
// 		int y;
// };

// void	fill_c(ft::map<char, int>& c)
// {
// 	c.insert(ft::make_pair('a', 42));
// 	c.insert(ft::make_pair('b', 69));
// 	c.insert(ft::make_pair('c', 420));
// 	c.insert(ft::make_pair('d', 12));
// 	c.insert(ft::make_pair('e', 4));
// }

// void	fill_c(ft::map<int, std::string>& c)
// {
// 	c.insert(ft::make_pair(1, "I"));
// 	c.insert(ft::make_pair(2, "want"));
// 	c.insert(ft::make_pair(3, "to"));
// 	c.insert(ft::make_pair(4, "break"));
// 	c.insert(ft::make_pair(5, "free !"));
// }

// void	fill_c(std::list<std::string>& c)
// {
// 	c.push_back("I");
// 	c.push_back("want");
// 	c.push_back("to");
// 	c.push_back("break");
// 	c.push_back("free !");
// }

// template <typename T1, typename T2>
// 	void	print_c(ft::map<T1, T2>& c)
// 	{
// 		cout << "Container specs:" << endl;
// 		cout << "Size[" << c.size() << "]" << endl;
// 		cout << "Capacity[" << c.capacity() << "]" << endl;
// 		cout << "Elements [" << endl;
// 		for(typename ft::map<T1, T2>::iterator it = c.begin(); it != c.end(); it++)
// 			cout << *it << endl;
// 		cout << "]" << endl;
// 	}

void	test_map()
{
	clock_t start_time = clock();
	
	cout << "----- TEST MAP -----" << endl;
	{
	// 	//~~ Member types
	// 	{
	// 		cout << "~~ Member types ~~" << endl;
	// 		if (typeid(ft::map<int, std::string>::key_type)			!= typeid(std::map<int, std::string>::key_type))
	// 			cout << "Wrong type (key_type)" << endl;
	// 		if (typeid(ft::map<int, std::string>::mapped_type)		!= typeid(std::map<int, std::string>::mapped_type))
	// 			cout << "Wrong type (mapped_type)" << endl;
	// 		if (typeid(ft::map<int, std::string>::value_type)		!= typeid(std::map<int, std::string>::value_type))
	// 			cout << "Wrong type (value_type)" << endl;
	// 		if (typeid(ft::map<int, std::string>::key_compare)		!= typeid(std::map<int, std::string>::key_compare))
	// 			cout << "Wrong type (key_compare)" << endl;
	// 		if (typeid(ft::map<int, std::string>::allocator_type)	!= typeid(std::map<int, std::string>::allocator_type))
	// 			cout << "Wrong type (allocator_type)" << endl;
	// 		if (typeid(ft::map<int, std::string>::pointer)			!= typeid(std::map<int, std::string>::pointer))
	// 			cout << "Wrong type (pointer)" << endl;
	// 		if (typeid(ft::map<int, std::string>::const_pointer)	!= typeid(std::map<int, std::string>::const_pointer))
	// 			cout << "Wrong type (const_pointer)" << endl;
	// 		if (typeid(ft::map<int, std::string>::reference)		!= typeid(std::map<int, std::string>::reference))
	// 			cout << "Wrong type (reference)" << endl;
	// 		if (typeid(ft::map<int, std::string>::const_reference)	!= typeid(std::map<int, std::string>::const_reference))
	// 			cout << "Wrong type (const_reference)" << endl;
	// 		if (typeid(ft::map<int, std::string>::size_type)		!= typeid(std::map<int, std::string>::size_type))
	// 			cout << "Wrong type (size_type)" << endl;
	// 		if (typeid(ft::map<int, std::string>::difference_type)	!= typeid(std::map<int, std::string>::difference_type))
	// 			cout << "Wrong type (difference_type)" << endl;
	// 	}		
	// 	//~~ Constructors and operator=
	// 	{
	// 		cout << "~~ Default constructor ~~" << endl;
	// 		ft::map<char, int>			default_int;
	// 		ft::map<int, std::string>	default_str;
	// 		fill_c(default_int);
	// 		fill_c(default_str);
	// 		print_c(default_int);
	// 		print_c(default_str);

	// 		cout << "~~ Fill constructor ~~" << endl;
	// 		ft::map<char, int>			fill_int(42, 42);
	// 		ft::map<int, std::string>	fill_str(42, "all work and no play makes Jack a dull boy");
	// 		print_c(default_int);
	// 		print_c(default_str);

	// 		cout << "~~ Range constructor ~~" << endl;
	// 		std::list<int>			lst_int;
	// 		std::list<std::string>	lst_str;
	// 		fill_c(lst_int);
	// 		fill_c(lst_str);
	// 		ft::map<char, int>			range_int(lst_int.begin(), lst_int.end());
	// 		ft::map<int, std::string>	range_str(lst_str.begin(), lst_str.end());
	// 		print_c(default_int);
	// 		print_c(default_str);

	// 		cout << "~~ Operator= ~~" << endl;
	// 		ft::map<char, int>			operator_int;
	// 		ft::map<int, std::string>	operator_str;
	// 		operator_int = default_int;
	// 		operator_str = default_str;
	// 		print_c(operator_int);
	// 		print_c(operator_str);

	// 		cout << "~~ Destructor ~~" << endl;
	// 	}
	// 	//~~ Iterators
	// 	{
	// 		cout << "~~ Iterator Member types ~~" << endl;
	// 		if (typeid(ft::map<char, int>::iterator::iterator_type)		!= typeid(std::vector<int>::iterator::iterator_type))
	// 			cout << "Wrong type (iterator_type)" << endl;
	// 		if (typeid(ft::map<char, int>::iterator::iterator_category)	!= typeid(std::vector<int>::iterator::iterator_category))
	// 			cout << "Wrong type (iterator_category)" << endl;
	// 		if (typeid(ft::map<char, int>::iterator::value_type)			!= typeid(std::vector<int>::iterator::value_type))
	// 			cout << "Wrong type (value_type)" << endl;
	// 		if (typeid(ft::map<char, int>::iterator::difference_type)		!= typeid(std::vector<int>::iterator::difference_type))
	// 			cout << "Wrong type (difference_type)" << endl;
	// 		if (typeid(ft::map<char, int>::iterator::reference)			!= typeid(std::vector<int>::iterator::reference))
	// 			cout << "Wrong type (reference)" << endl;
	// 		if (typeid(ft::map<char, int>::iterator::pointer)				!= typeid(std::vector<int>::iterator::pointer))
	// 			cout << "Wrong type (pointer)" << endl;
				
	// 		cout << "~~ Const Iterator Member types ~~" << endl;
	// 		if (typeid(ft::map<char, int>::const_iterator::iterator_type)		!= typeid(std::vector<int>::const_iterator::iterator_type))
	// 			cout << "Wrong type (iterator_type)" << endl;
	// 		if (typeid(ft::map<char, int>::const_iterator::iterator_category)	!= typeid(std::vector<int>::const_iterator::iterator_category))
	// 			cout << "Wrong type (iterator_category)" << endl;
	// 		if (typeid(ft::map<char, int>::const_iterator::value_type)			!= typeid(std::vector<int>::const_iterator::value_type))
	// 			cout << "Wrong type (value_type)" << endl;
	// 		if (typeid(ft::map<char, int>::const_iterator::difference_type)	!= typeid(std::vector<int>::const_iterator::difference_type))
	// 			cout << "Wrong type (difference_type)" << endl;
	// 		if (typeid(ft::map<char, int>::const_iterator::reference)			!= typeid(std::vector<int>::const_iterator::reference))
	// 			cout << "Wrong type (reference)" << endl;
	// 		if (typeid(ft::map<char, int>::const_iterator::pointer)			!= typeid(std::vector<int>::const_iterator::pointer))
	// 			cout << "Wrong type (pointer)" << endl;

	// 		cout << "~~ Iterator ~~" << endl;
	// 		{
	// 			ft::map<char, int>			c_int;
	// 			ft::map<test_class>	c_class(5);
	// 			fill_c(c_int);
	// 			ft::map<char, int>::iterator	it_int; 										// X a;
	// 			it_int = c_int.begin();														// b = a;
	// 			ft::map<char, int>::iterator	it_int_copy(it_int);							// X a(b);
	// 			cout << *it_int << endl;													// *a
	// 			ft::map<test_class>::iterator	it_class = c_class.begin();
	// 			cout << it_class->x << "|" << it_class->y << endl;							// a->m
	// 			cout << (*it_int = -42) << "|" << (it_int == it_int_copy) << endl;			// *a = t
	// 			cout << (it_int == ++it_int) << endl;										// ++a
	// 			cout << (it_int == it_int++) << endl;										// a++
	// 			cout << (*it_int++) << endl;												// *a++
	// 			cout << (it_int == --it_int) << endl;										// --a
	// 			cout << (it_int == it_int--) << endl;										// a--
	// 			cout << (*it_int--) << endl;												// *a--
	// 			cout << *(it_int + 2) << endl;												// a + n
	// 			cout << *(3 + it_int) << endl;												// n + a
	// 			cout << *(c_int.end() - 2) << endl;											// a - n
	// 			cout << it_int - it_int_copy << endl;										// a - b
	// 			ft::map<char, int>::const_iterator	it_int_end = (--(c_int.end()));
	// 			it_int += 1;
	// 			cout << (it_int == it_int_copy) << "|" << (it_int == it_int_end) << endl;	// a == b
	// 			cout << (it_int != it_int_copy) << "|" << (it_int != it_int_end) << endl;	// a != b
	// 			cout << (it_int < it_int_copy) << "|" << (it_int < it_int_end) << endl;		// a < b
	// 			cout << (it_int > it_int_copy) << "|" << (it_int > it_int_end) << endl;		// a > b
	// 			cout << (it_int <= it_int_copy) << "|" << (it_int <= it_int_end) << endl;	// a <= b
	// 			cout << (it_int >= it_int_copy) << "|" << (it_int >= it_int_end) << endl;	// a >= b
	// 			cout << *(it_int += 3) << endl;											// a += b
	// 			cout << *(it_int -= 2) << endl;												// a -= b
	// 			cout << it_int_copy[4] << endl;													// a[n]
	// 			cout << *c_int.begin() << endl;
	// 			cout << *(--(c_int.end())) << endl;
	// 			cout << (*(c_int.begin()) - *(--(c_int.end()))) << endl;
	// 			print_c(c_int);
	// 		}

	// 		cout << "~~ Reverse Iterator ~~" << endl;
	// 		{
	// 			ft::map<char, int>			c_int;
	// 			ft::map<test_class>	c_class(5);
	// 			fill_c(c_int);
	// 			ft::map<char, int>::reverse_iterator	it_int; 								// X a;
	// 			it_int = c_int.rbegin();													// b = a;
	// 			ft::map<char, int>::reverse_iterator	it_int_copy(it_int);					// X a(b);
	// 			cout << (*it_int) << endl;													// *a
	// 			ft::map<test_class>::reverse_iterator	it_class = c_class.rbegin();
	// 			cout << it_class->x << "|" << it_class->y << endl;							// a->m
	// 			cout << (*it_int = -42) << "|" << (it_int == it_int_copy) << endl;			// *a = t
	// 			cout << (it_int == ++it_int) << endl;										// ++a
	// 			cout << (it_int == it_int++) << endl;										// a++
	// 			cout << (*it_int++) << endl;												// *a++
	// 			cout << (it_int == --it_int) << endl;										// --a
	// 			cout << (it_int == it_int--) << endl;										// a--
	// 			cout << (*it_int--) << endl;												// *a--
	// 			cout << *(it_int + 2) << endl;												// a + n
	// 			cout << *(3 + it_int) << endl;												// n + a
	// 			cout << *(c_int.rend() - 2) << endl;												// a - n
	// 			cout << it_int - it_int_copy << endl;										// a - b
	// 			ft::map<char, int>::const_reverse_iterator	it_int_end = (--(c_int.rend()));
	// 			it_int += 1;
	// 			cout << (it_int == it_int_copy) << "|" << (it_int == it_int_end) << endl;	// a == b
	// 			cout << (it_int != it_int_copy) << "|" << (it_int != it_int_end) << endl;	// a != b
	// 			cout << (it_int < it_int_copy) << "|" << (it_int < it_int_end) << endl;		// a < b
	// 			cout << (it_int > it_int_copy) << "|" << (it_int > it_int_end) << endl;		// a > b
	// 			cout << (it_int <= it_int_copy) << "|" << (it_int <= it_int_end) << endl;	// a <= b
	// 			cout << (it_int >= it_int_copy) << "|" << (it_int >= it_int_end) << endl;	// a >= b
	// 			cout << *(it_int += 3) << endl;											// a += b
	// 			cout << *(it_int -= 2) << endl;												// a -= b
	// 			cout << it_int_copy[4] << endl;													// a[n]
	// 			print_c(c_int);
	// 			cout << *c_int.rbegin() << endl;
	// 			cout << *(--(c_int.rend())) << endl;
	// 			cout << ((*c_int.rbegin()) - *(--(c_int.rend()))) << endl;
	// 		}
	// 	}
	// 	//~~ Capacity
	// 	{
	// 		cout << "~~ Capacity ~~" << endl;
	// 		ft::map<char, int>	c_int;
	// 		cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
	// 		c_int.reserve(40);
	// 		cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
	// 		fill_c(c_int);
	// 		fill_c(c_int);
	// 		cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
	// 		c_int.resize(20);
	// 		cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
	// 		print_c(c_int);
	// 		c_int.reserve(10);
	// 		cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
	// 		c_int.resize(5);
	// 		cout << c_int.size() << "|" << c_int.max_size() << "|" << c_int.capacity() << "|" << c_int.empty() << endl;
	// 		print_c(c_int);
	// 		try { c_int.reserve(static_cast<unsigned long long>(c_int.max_size()) + 10); }
	// 		catch (std::length_error& e) { cout << e.what() << endl; }
	// 	}
	// 	//~~ Element Access
	// 	{
	// 		ft::map<char, int>			c_int;
	// 		ft::map<int, std::string>	c_str;
	// 		fill_c(c_int);
	// 		fill_c(c_str);
	// 		const ft::map<char, int>	c_int_const(c_int);

	// 		cout << "~~ operator[] and at() ~~" << endl;
	// 		for(int i = 0; i < 5; i++)
	// 		{
	// 			cout << c_int[i] << "|" << c_str[i] << "|" << c_int_const[i] << endl;
	// 			cout << c_int.at(i) << "|" << c_str.at(i) << "|" << c_int_const.at(i) << endl;
	// 		}

	// 		cout << "~~ front() and back() ~~" << endl;
	// 		cout << c_int.front() << "|" << c_str.front() << "|" << c_int_const.front() << endl;
	// 		cout << c_int.back() << "|" << c_str.back() << "|" << c_int_const.back() << endl;
	// 		try { cout << c_int.at(100); }
	// 		catch(const std::out_of_range& e) { cout << e.what() << '\n'; }
	// 	}
	// 	//~~ Modifiers
	// 	{
	// 		cout << "~~ assign() ~~" << endl;
	// 		ft::map<char, int>	c_int;
	// 		std::list<int>	lst;
	// 		fill_c(lst);
	// 		c_int.assign(lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		fill_c(lst);
	// 		c_int.assign(lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		lst.clear();
	// 		c_int.assign(lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		c_int.assign(20, 20);
	// 		print_c(c_int);
	// 		c_int.assign(10, 10);
	// 		print_c(c_int);
	// 		c_int.assign(30, 30);
	// 		print_c(c_int);
	// 		cout << "~~ insert() ~~" << endl;
	// 		cout << *(c_int.insert(c_int.begin() + 15, 42)) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.insert(c_int.end(), 42)) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.insert(c_int.begin(), 42)) << endl;
	// 		print_c(c_int);
	// 		c_int.insert(c_int.begin() + 15, 3, 42);
	// 		print_c(c_int);
	// 		c_int.insert(c_int.end(), 3, 42);
	// 		print_c(c_int);
	// 		c_int.insert(c_int.begin(), 3, 42);
	// 		print_c(c_int);
	// 		c_int.insert(c_int.begin() + 15, 42);
	// 		print_c(c_int);
	// 		c_int.insert(c_int.end(), 42);
	// 		print_c(c_int);
	// 		c_int.insert(c_int.begin(), 42);
	// 		print_c(c_int);
	// 		c_int.insert(c_int.begin() + 15, lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		c_int.insert(c_int.end(), lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		c_int.insert(c_int.begin(), lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		cout << "~~ erase() ~~" << endl;
	// 		cout << *(c_int.erase(c_int.begin() + 20)) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.erase(c_int.begin())) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.erase(c_int.end() - 1)) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.erase(c_int.end() - 5, c_int.end() - 3)) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.erase(c_int.begin(), c_int.begin() + 5)) << endl;
	// 		print_c(c_int);
	// 		cout << *(c_int.erase(c_int.begin(), c_int.end() - 1)) << endl;
	// 		print_c(c_int);
	// 		cout << "~~ clear() and swap() ~~" << endl;
	// 		c_int.clear();
	// 		ft::map<char, int>	c_int2(lst.begin(), lst.end());
	// 		print_c(c_int);
	// 		print_c(c_int2);
	// 		c_int.swap(c_int2);
	// 		print_c(c_int);
	// 		print_c(c_int2);
	// 	}
	// 	//~~ Allocator
	// 	{
	// 		cout << "~~ get_allocator() ~~" << endl;
	// 		ft::map<char, int>			c_int;
	// 		ft::map<int, std::string>	c_str;
	// 		fill_c(c_int);
	// 		fill_c(c_str);
	// 		ft::map<char, int>::allocator_type alloc_c_int = c_int.get_allocator();
	// 		ft::map<int, std::string>::allocator_type alloc_c_str = c_str.get_allocator();
	// 		alloc_c_int = c_str.get_allocator();
	// 		alloc_c_str = c_int.get_allocator();
	// 		c_int.erase(c_int.begin());
	// 		c_str.erase(c_str.begin());
	// 		c_int.insert(c_int.begin() + 2, 12, 12);
	// 		c_str.insert(c_str.begin() + 2, 12, "No you don't");
	// 	}
	// 	//~~ Relational Operators
	// 	{
	// 		cout << "~~ Relational Operators ~~" << endl;
	// 		ft::map<int, std::string>	c_str1;
	// 		ft::map<int, std::string>	c_str2;
	// 		fill_c(c_str1);
	// 		fill_c(c_str2);
	// 		//~~ c_str1 = c_str2
	// 		cout << (c_str1 == c_str2) << endl;
	// 		cout << (c_str1 != c_str2) << endl;
	// 		cout << (c_str1 < c_str2) << endl;
	// 		cout << (c_str1 > c_str2) << endl;
	// 		cout << (c_str1 <= c_str2) << endl;
	// 		cout << (c_str1 >= c_str2) << endl;
	// 		fill_c(c_str2);
	// 		//~~ c_str1 < c_str2
	// 		cout << (c_str1 == c_str2) << endl;
	// 		cout << (c_str1 != c_str2) << endl;
	// 		cout << (c_str1 < c_str2) << endl;
	// 		cout << (c_str1 > c_str2) << endl;
	// 		cout << (c_str1 <= c_str2) << endl;
	// 		cout << (c_str1 >= c_str2) << endl;
	// 		//~~ c_str2 < c_str1
	// 		cout << (c_str2 == c_str1) << endl;
	// 		cout << (c_str2 != c_str1) << endl;
	// 		cout << (c_str2 < c_str1) << endl;
	// 		cout << (c_str2 > c_str1) << endl;
	// 		cout << (c_str2 <= c_str1) << endl;
	// 		cout << (c_str2 >= c_str1) << endl;
	// 		print_c(c_str1);
	// 		print_c(c_str2);
	// 		swap(c_str1, c_str2);
	// 		print_c(c_str1);
	// 		print_c(c_str2);
	// 	}
	}
	clock_t	test_time = clock() - start_time;
	cout << endl << "Time: " << ((float)test_time)/CLOCKS_PER_SEC << endl;
}
