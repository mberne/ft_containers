#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <map>
#include <unordered_map>
#include <list>

#ifdef STD
	namespace ft = std;
#else
	#include "map.hpp"
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

void	fill_c(ft::map<char, int>& c)
{
	c.insert(ft::make_pair('a', 42));
	c.insert(ft::make_pair('b', 69));
	c.insert(ft::make_pair('c', 420));
	c.insert(ft::make_pair('d', 12));
	c.insert(ft::make_pair('e', 4));
}

void	fill_c(ft::map<int, std::string>& c)
{
	c.insert(ft::make_pair(1, "I"));
	c.insert(ft::make_pair(2, "want"));
	c.insert(ft::make_pair(3, "to"));
	c.insert(ft::make_pair(4, "break"));
	c.insert(ft::make_pair(5, "free !"));
}

void	fill_310(ft::map<int, char>& c)
{
	c.clear();
	int i = 10;
	while (i < 311)
	{
		c.insert(ft::make_pair(i, 'f'));
		i += 10;
	}
}

void	fill_105(ft::map<int, char>& c)
{
	c.clear();
	int i = 5;
	while (i < 106)
	{
		c.insert(ft::make_pair(i, 'f'));
		i += 5;
	}
}

template <typename T1, typename T2>
	void	print_c(ft::map<T1, T2>& c)
	{
		cout << "Container specs:" << endl;
		cout << "Size[" << c.size() << "]" << endl;
		cout << "Elements [" << endl;
		for(typename ft::map<T1, T2>::iterator it = c.begin(); it != c.end(); it++)
			cout << (*it).first << "|" << (*it).second << endl;
		cout << "]" << endl;
	}

template <typename T1, typename T2>
	void	print_c(const ft::map<T1, T2>& c)
	{
		cout << "Container specs:" << endl;
		cout << "Size[" << c.size() << "]" << endl;
		cout << "Elements [" << endl;
		for(typename ft::map<T1, T2>::const_iterator it = c.begin(); it != c.end(); it++)
			cout << (*it).first << "|" << (*it).second << endl;
		cout << "]" << endl;
	}

void	test_map()
{
	clock_t start_time = clock();
	
	cout << "----- TEST MAP -----" << endl;
	{
		//~~ Member types
		{
			cout << "~~ Member types ~~" << endl;
			if (typeid(ft::map<int, std::string>::key_type)			!= typeid(std::map<int, std::string>::key_type))
				cout << "Wrong type (key_type)" << endl;
			if (typeid(ft::map<int, std::string>::mapped_type)		!= typeid(std::map<int, std::string>::mapped_type))
				cout << "Wrong type (mapped_type)" << endl;
			if (typeid(ft::map<int, std::string>::key_compare)		!= typeid(std::map<int, std::string>::key_compare))
				cout << "Wrong type (key_compare)" << endl;
			if (typeid(ft::map<int, std::string>::size_type)		!= typeid(std::map<int, std::string>::size_type))
				cout << "Wrong type (size_type)" << endl;
			if (typeid(ft::map<int, std::string>::difference_type)	!= typeid(std::map<int, std::string>::difference_type))
				cout << "Wrong type (difference_type)" << endl;
		}		
//~~ Constructors and operator=
		{
			cout << "~~ Default constructor ~~" << endl;
			ft::map<char, int>			default_char_int;
			ft::map<int, std::string>	default_int_str;
			fill_c(default_char_int);
			fill_c(default_int_str);
			print_c(default_char_int);
			print_c(default_int_str);

			cout << "~~ Range constructor ~~" << endl;
			ft::map<char, int>			range_char_int(default_char_int.begin(), default_char_int.end());
			ft::map<int, std::string>	range_int_str(default_int_str.begin(), default_int_str.end());
			print_c(default_char_int);
			print_c(default_int_str);

			cout << "~~ Copy constructor ~~" << endl;
			ft::map<char, int>			copy_char_int(default_char_int);
			ft::map<int, std::string>	copy_int_str(default_int_str);
			print_c(default_char_int);
			print_c(default_int_str);

			cout << "~~ Operator= ~~" << endl;
			ft::map<char, int>			operator_char_int;
			ft::map<int, std::string>	operator_int_str;
			operator_char_int = default_char_int;
			operator_int_str = default_int_str;
			print_c(operator_char_int);
			print_c(operator_int_str);
			if (typeid(operator_char_int.key_comp())		!= typeid(operator_char_int.key_comp()))
				cout << "Wrong type (key_comp)" << endl;
			if (typeid(operator_int_str.key_comp())		!= typeid(operator_int_str.key_comp()))
				cout << "Wrong type (key_comp)" << endl;

			cout << "~~ Destructor ~~" << endl;
		}
		//~~ Iterators
		{
			cout << "~~ Iterator Member types ~~" << endl;
			if (typeid(ft::map<char, int>::iterator::iterator_category)		!= typeid(std::map<char, int>::iterator::iterator_category))
				cout << "Wrong type (iterator_category)" << endl;
			if (typeid(ft::map<char, int>::iterator::difference_type)		!= typeid(std::map<char, int>::iterator::difference_type))
				cout << "Wrong type (difference_type)" << endl;
				
			cout << "~~ Const Iterator Member types ~~" << endl;
			if (typeid(ft::map<char, int>::const_iterator::iterator_category)	!= typeid(std::map<char, int>::const_iterator::iterator_category))
				cout << "Wrong type (iterator_category)" << endl;
			if (typeid(ft::map<char, int>::const_iterator::difference_type)		!= typeid(std::map<char, int>::const_iterator::difference_type))
				cout << "Wrong type (difference_type)" << endl;

			cout << "~~ Iterator ~~" << endl;
			{
				ft::map<int, char>			c_int_char;
				for(ft::map<int, char>::iterator it = c_int_char.begin(); it != c_int_char.end(); it++)
					cout << it->first << endl;
				c_int_char.insert(ft::make_pair(42, 'f'));
				for(ft::map<int, char>::iterator it = c_int_char.begin(); it != c_int_char.end(); it++)
					cout << it->first << endl;
				ft::map<char, int>			c_char_int;
				fill_c(c_char_int);
				ft::map<char, int>::iterator	it_char_int; 										// X a;
				it_char_int = c_char_int.begin();													// b = a;
				ft::map<char, int>::iterator	it_char_int_copy(it_char_int);						// X a(b);
				(void)it_char_int_copy;
				cout << (*it_char_int).first << "|" << (*it_char_int).second << endl;				// *a
				cout << it_char_int->first << "|" << it_char_int->second << endl;					// a->m
				cout << (it_char_int == ++it_char_int) << endl;										// ++a
				cout << (it_char_int == it_char_int++) << endl;										// a++
				cout << (*it_char_int++).first << endl;												// *a++
				cout << (it_char_int == --it_char_int) << endl;										// --a
				cout << (it_char_int == it_char_int--) << endl;										// a--
				cout << (*it_char_int--).second << endl;											// *a--
				print_c(c_char_int);
			}

			cout << "~~ Reverse Iterator ~~" << endl;
			{
				ft::map<int, char>			c_int_char;
				for(ft::map<int, char>::const_iterator it = c_int_char.begin(); it != c_int_char.end(); it++)
					cout << it->first << endl;
				c_int_char.insert(ft::make_pair(42, 'f'));
				for(ft::map<int, char>::const_iterator it = c_int_char.begin(); it != c_int_char.end(); it++)
					cout << it->first << endl;
				ft::map<char, int>			c_char_int;
				fill_c(c_char_int);
				ft::map<char, int>::reverse_iterator	it_char_int; 								// X a;
				it_char_int = c_char_int.rbegin();													// b = a;
				ft::map<char, int>::reverse_iterator	it_char_int_copy(it_char_int);				// X a(b);
				(void)it_char_int_copy;
				cout << (*it_char_int).first << "|" << (*it_char_int).second << endl;				// *a
				cout << it_char_int->first << "|" << it_char_int->second << endl;					// a->m
				cout << (it_char_int == ++it_char_int) << endl;										// ++a
				cout << (it_char_int == it_char_int++) << endl;										// a++
				cout << (*it_char_int++).first << endl;												// *a++
				cout << (it_char_int == --it_char_int) << endl;										// --a
				cout << (it_char_int == it_char_int--) << endl;										// a--
				cout << (*it_char_int--).second << endl;											// *a--
				print_c(c_char_int);
			}
		}
		//~~ Capacity
		{
			cout << "~~ Capacity ~~" << endl;
			ft::map<char, int>	c_char_int;
			print_c(c_char_int);
			cout << c_char_int.size() << "|" << c_char_int.max_size() << "|" << c_char_int.empty() << endl;
			fill_c(c_char_int);
			print_c(c_char_int);
			cout << c_char_int.size() << "|" << c_char_int.max_size() << "|" << c_char_int.empty() << endl;
		}
		//~~ Element Access
		{
			ft::map<char, int>			c_char_int;
			ft::map<int, std::string>	c_int_str;
			fill_c(c_char_int);
			fill_c(c_int_str);
			const ft::map<char, int>	c_char_int_const(c_char_int);\
			print_c(c_char_int_const);

			cout << "~~ operator[] and at() ~~" << endl;
			for(char c = 'a'; c < 'f'; c++)
				cout << c_char_int[c] << endl;
			for(int i = 0; i < 5; i++)
				cout << c_int_str[i] << endl;
			cout << c_int_str[100] << endl;
			cout << c_char_int['e'] << endl;
		}
		//~~ Modifiers
		{
			cout << "~~ insert() ~~" << endl;
			// 165 167 162 195 215 45 55 65 75 42 320-640 0 161
			//~~ Single Element
			char				s = 's';
			ft::map<int, char>	c_single;
			fill_310(c_single);
			print_c(c_single);
			c_single.insert(ft::make_pair(165, s));	print_c(c_single);
			c_single.insert(ft::make_pair(167, s));	print_c(c_single);
			c_single.insert(ft::make_pair(162, s));	print_c(c_single);
			c_single.insert(ft::make_pair(195, s));	print_c(c_single);
			c_single.insert(ft::make_pair(215, s));	print_c(c_single);
			c_single.insert(ft::make_pair(45, s));	print_c(c_single);
			c_single.insert(ft::make_pair(55, s));	print_c(c_single);
			c_single.insert(ft::make_pair(65, s));	print_c(c_single);
			c_single.insert(ft::make_pair(75, s));	print_c(c_single);
			c_single.insert(ft::make_pair(42, s));	print_c(c_single);

			for(int i = 320; i < 641; i += 10)
				c_single.insert(ft::make_pair(i, s));
			c_single.insert(ft::make_pair(0, s));	print_c(c_single);
			c_single.insert(ft::make_pair(161, s));	print_c(c_single);
			//~~ With Hint
			ft::map<int, char>	c_hint;
			fill_310(c_hint);
			print_c(c_hint);
			c_hint.insert(c_hint.upper_bound(165), ft::make_pair(165, s));	print_c(c_hint);
			c_hint.insert(c_hint.upper_bound(167), ft::make_pair(167, s));	print_c(c_hint);
			c_hint.insert(c_hint.upper_bound(162), ft::make_pair(162, s));	print_c(c_hint);
			c_hint.insert(c_hint.upper_bound(195), ft::make_pair(195, s));	print_c(c_hint);
			c_hint.insert(c_hint.upper_bound(215), ft::make_pair(215, s));	print_c(c_hint);
			c_hint.insert(c_hint.begin(), ft::make_pair(45, s));			print_c(c_hint);
			c_hint.insert(c_hint.begin(), ft::make_pair(55, s));			print_c(c_hint);
			c_hint.insert(c_hint.upper_bound(215), ft::make_pair(65, s));	print_c(c_hint);
			c_hint.insert(c_hint.end(), ft::make_pair(75, s));				print_c(c_hint);
			c_hint.insert(c_hint.end(), ft::make_pair(42, s));				print_c(c_hint);
			for(int i = 320; i < 641; i += 10)
				c_hint.insert(c_hint.end(), ft::make_pair(i, s));
			c_hint.insert(c_hint.end(), ft::make_pair(0, s));		print_c(c_hint);
			c_hint.insert(c_hint.begin(), ft::make_pair(161, s));	print_c(c_hint);
			//~~ Range Insert
			ft::map<int, char>	c_range(c_single);
			ft::map<int, char>	c_other;
			fill_105(c_other);
			print_c(c_range);
			c_single.insert(c_other.begin(), c_other.end());
			print_c(c_range);
			// 400 510 55 170 . 250 270 290 310 161 162 167 195 . 140 150 70 60 75 . 320 0 640
			cout << "~~ erase() ~~" << endl;
			c_single.erase(400);	print_c(c_single);
			c_single.erase(510);	print_c(c_single);
			c_single.erase(55);		print_c(c_single);
			c_single.erase(170);	print_c(c_single);
			c_single.erase(250);	print_c(c_single);
			c_single.erase(270);	print_c(c_single);
			c_single.erase(c_single.find(290));	print_c(c_single);
			c_single.erase(c_single.find(310));	print_c(c_single);
			c_single.erase(c_single.find(161));	print_c(c_single);
			c_single.erase(c_single.find(162));	print_c(c_single);
			c_single.erase(167);	print_c(c_single);
			c_single.erase(195);	print_c(c_single);
			c_single.erase(140);	print_c(c_single);
			c_single.erase(150);	print_c(c_single);
			c_single.erase(c_single.find(70));		print_c(c_single);
			c_single.erase(c_single.find(60));		print_c(c_single);
			c_single.erase(c_single.find(75));		print_c(c_single);
			c_single.erase(c_single.find(320));		print_c(c_single);
			c_single.erase(0);		print_c(c_single);
			c_single.erase(640);	print_c(c_single);
			c_single.erase(c_single.find(180), c_single.find(480));	print_c(c_single);

		//~~ Operations
			cout << "~~ find() and count() ~~" << endl;
			cout << (c_single.find(10) != c_single.end()) << "|" << (*c_single.find(10)).first << "|" << (*c_single.find(10)).second << "|" << c_single.count(10) << endl;
			cout << (c_single.find(165) != c_single.end()) << "|" << (*c_single.find(165)).first << "|" << (*c_single.find(165)).second << "|" << c_single.count(165) << endl;
			cout << (c_single.find(630) != c_single.end()) << "|" << (*c_single.find(630)).first << "|" << (*c_single.find(630)).second << "|" << c_single.count(630) << endl;
			cout << (c_single.find(100) != c_single.end()) << "|" << (*c_single.find(100)).first << "|" << (*c_single.find(100)).second << "|" << c_single.count(100) << endl;
			cout << (c_single.find(200) != c_single.end()) << "|" << c_single.count(200) << endl;
			cout << (c_single.find(300) != c_single.end()) << "|" << c_single.count(300) << endl;
			cout << (c_single.find(520) != c_single.end()) << "|" << (*c_single.find(520)).first << "|" << (*c_single.find(520)).second << "|" << c_single.count(520) << endl;
			cout << (c_single.find(0) != c_single.end())<< "|" << c_single.count(0) << endl;
			cout << (c_single.find(640) != c_single.end())<< "|" << c_single.count(640) << endl;

			cout << "~~ lower_bound() ~~" << endl;
			cout << (c_single.lower_bound(10) != c_single.end()) << "|" << (*c_single.lower_bound(10)).first << "|" << (*c_single.lower_bound(10)).second << endl;
			cout << (c_single.lower_bound(165) != c_single.end()) << "|" << (*c_single.lower_bound(165)).first << "|" << (*c_single.lower_bound(165)).second << endl;
			cout << (c_single.lower_bound(630) != c_single.end()) << "|" << (*c_single.lower_bound(630)).first << "|" << (*c_single.lower_bound(630)).second << endl;
			cout << (c_single.lower_bound(100) != c_single.end()) << "|" << (*c_single.lower_bound(100)).first << "|" << (*c_single.lower_bound(100)).second << endl;
			cout << (c_single.lower_bound(200) != c_single.end()) << "|" << (*c_single.lower_bound(200)).first << "|" << (*c_single.lower_bound(200)).second << endl;
			cout << (c_single.lower_bound(300) != c_single.end()) << "|" << (*c_single.lower_bound(300)).first << "|" << (*c_single.lower_bound(300)).second << endl;
			cout << (c_single.lower_bound(520) != c_single.end()) << "|" << (*c_single.lower_bound(520)).first << "|" << (*c_single.lower_bound(520)).second << endl;
			cout << (c_single.lower_bound(0) != c_single.end()) << "|" << endl;
			cout << (c_single.lower_bound(640) != c_single.end()) << "|" << endl;

			cout << "~~ upper_bound() ~~" << endl;
			cout << (c_single.upper_bound(10) != c_single.end()) << "|" << (*c_single.upper_bound(10)).first << "|" << (*c_single.upper_bound(10)).second << endl;
			cout << (c_single.upper_bound(165) != c_single.end()) << "|" << (*c_single.upper_bound(165)).first << "|" << (*c_single.upper_bound(165)).second << endl;
			cout << (c_single.upper_bound(630) != c_single.end()) << endl;
			cout << (c_single.upper_bound(100) != c_single.end()) << "|" << (*c_single.upper_bound(100)).first << "|" << (*c_single.upper_bound(100)).second << endl;
			cout << (c_single.upper_bound(200) != c_single.end()) << "|" << (*c_single.upper_bound(200)).first << "|" << (*c_single.upper_bound(200)).second << endl;
			cout << (c_single.upper_bound(300) != c_single.end()) << "|" << (*c_single.upper_bound(300)).first << "|" << (*c_single.upper_bound(300)).second << endl;
			cout << (c_single.upper_bound(520) != c_single.end()) << "|" << (*c_single.upper_bound(520)).first << "|" << (*c_single.upper_bound(520)).second << endl;
			cout << (c_single.upper_bound(0) != c_single.end()) << "|" << endl;
			cout << (c_single.upper_bound(640) != c_single.end()) << "|" << endl;

			cout << "~~ equal_range() ~~" << endl;
			cout << (c_single.equal_range(10).first != c_single.equal_range(10).second) << "|" << (*c_single.equal_range(10).first).first << "|" << (*c_single.equal_range(10).first).second << endl;
			cout << (c_single.equal_range(165).first != c_single.equal_range(165).second) << "|" << (*c_single.equal_range(165).first).first << "|" << (*c_single.equal_range(165).first).second << endl;
			cout << (c_single.equal_range(630).first != c_single.equal_range(630).second) << "|" << (*c_single.equal_range(630).first).first << "|" << (*c_single.equal_range(630).first).second << endl;
			cout << (c_single.equal_range(100).first != c_single.equal_range(100).second) << "|" << (*c_single.equal_range(100).first).first << "|" << (*c_single.equal_range(100).first).second << endl;
			cout << (c_single.equal_range(200).first != c_single.equal_range(200).second) << "|" << (*c_single.equal_range(200).first).first << "|" << (*c_single.equal_range(200).first).second << endl;
			cout << (c_single.equal_range(300).first != c_single.equal_range(300).second) << "|" << (*c_single.equal_range(300).first).first << "|" << (*c_single.equal_range(300).first).second << endl;
			cout << (c_single.equal_range(520).first != c_single.equal_range(520).second) << "|" << (*c_single.equal_range(520).first).first << "|" << (*c_single.equal_range(520).first).second << endl;
			cout << (c_single.equal_range(0).first != c_single.equal_range(0).second) << "|" << (c_single.end() != c_single.equal_range(0).second) << endl;
			cout << (c_single.equal_range(640).first != c_single.equal_range(630).second) << "|" << (c_single.end() != c_single.equal_range(630).second) << endl;

		//~~ Modifiers
			cout << "~~ clear() and swap() ~~" << endl;
			ft::map<int, char>	c2(c_single);
			c_single.clear();
			print_c(c_single);
			print_c(c2);
			c_single.swap(c2);
			print_c(c_single);
			print_c(c2);
		}
		//~~ Observers
		{
			cout << "~~ key_comp() && value_comp() ~~" << endl;
			ft::map<char, int>					c_char_int;
			ft::map<char, int>::key_compare		kc = c_char_int.key_comp();
			ft::map<char, int>::value_compare	vc = c_char_int.value_comp();
			(void)kc;
			(void)vc;
		}
		//~~ Allocator
		{
			cout << "~~ get_allocator() ~~" << endl;
			ft::map<char, int>			c_char_int;
			ft::map<int, std::string>	c_int_str;
			fill_c(c_char_int);
			fill_c(c_int_str);
			ft::map<char, int>::allocator_type alloc_c_char_int = c_char_int.get_allocator();
			ft::map<int, std::string>::allocator_type alloc_c_int_str = c_int_str.get_allocator();
			alloc_c_char_int = c_int_str.get_allocator();
			alloc_c_int_str = c_char_int.get_allocator();
			c_char_int.clear();
			c_int_str.clear();
		}
		//~~ Relational Operators
		{
			cout << "~~ Relational Operators ~~" << endl;
			ft::map<int, std::string>	c_int_str1;
			ft::map<int, std::string>	c_int_str2;
			fill_c(c_int_str1);
			fill_c(c_int_str2);
			ft::map<int, std::string> const	c_int_str_const(c_int_str1.begin(), --(--c_int_str1.end()));
			//~~ c_int_str1 = c_int_str2
			cout << (c_int_str1 == c_int_str2) << endl;
			cout << (c_int_str1 != c_int_str2) << endl;
			cout << (c_int_str1 < c_int_str2) << endl;
			cout << (c_int_str1 > c_int_str2) << endl;
			cout << (c_int_str1 <= c_int_str2) << endl;
			cout << (c_int_str1 >= c_int_str2) << endl;
			fill_c(c_int_str2);
			//~~ c_int_str1 < c_int_str2
			cout << (c_int_str1 == c_int_str2) << endl;
			cout << (c_int_str1 != c_int_str2) << endl;
			cout << (c_int_str1 < c_int_str2) << endl;
			cout << (c_int_str1 > c_int_str2) << endl;
			cout << (c_int_str1 <= c_int_str2) << endl;
			cout << (c_int_str1 >= c_int_str2) << endl;
			//~~ c_int_str2 < c_int_str1
			cout << (c_int_str2 == c_int_str1) << endl;
			cout << (c_int_str2 != c_int_str1) << endl;
			cout << (c_int_str2 < c_int_str1) << endl;
			cout << (c_int_str2 > c_int_str1) << endl;
			cout << (c_int_str2 <= c_int_str1) << endl;
			cout << (c_int_str2 >= c_int_str1) << endl;
			//~~ c_int_str1 > c_int_str_const
			cout << (c_int_str1 == c_int_str_const) << endl;
			cout << (c_int_str1 != c_int_str_const) << endl;
			cout << (c_int_str1 < c_int_str_const) << endl;
			cout << (c_int_str1 > c_int_str_const) << endl;
			cout << (c_int_str1 <= c_int_str_const) << endl;
			cout << (c_int_str1 >= c_int_str_const) << endl;
			print_c(c_int_str1);
			print_c(c_int_str2);
			swap(c_int_str1, c_int_str2);
			print_c(c_int_str1);
			print_c(c_int_str2);
		}
	}
	clock_t	test_time = clock() - start_time;
	cout << endl << "Time: " << ((float)test_time)/CLOCKS_PER_SEC << endl;
}
