#include <iostream>
#include <string>
#include <deque>

#ifdef STD
	#include <vector>
	#include <stack>
	#include <map>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"
#endif

using std::cout;
using std::endl;

// void	test_vector();
// void	test_stack();
// void	test_map();

int main()
{
	cout << endl << "----------Vector----------" << endl << endl;

	cout << "Create int vector and test resize." << endl;

	ft::vector<int> int_vector(10, 42);
	int_vector.push_back(21);
	int_vector.push_back(21);
	for(size_t i = 0; i < int_vector.size(); i++)
	{
		cout << "[] version : " << int_vector[i] << endl;
		cout << "at version : " << int_vector.at(i) << endl;
	}
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	int_vector.resize(10);
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	int_vector.resize(15, 21);
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	int_vector.resize(25);
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;

	cout << "Modify int vector and test reserve." << endl;

	for(size_t i = 0; i < 20; i++)
		int_vector.pop_back();
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	int_vector.reserve(100);
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	int_vector.reserve(30);
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;
	
	cout << "Test empty, front and back." << endl;

	if (int_vector.empty())
		cout << "int_vector is empty." << endl;
	else
		cout << "int_vector isn't empty." << endl;
	cout << int_vector.front() << endl;
	cout << int_vector.back() << endl;
	int_vector.push_back(21);
	cout << int_vector.front() << endl;
	cout << int_vector.back() << endl;
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;

	cout << "Test assign." << endl;

	int_vector.assign(2, 21);
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;

	cout << "Test clear." << endl;
	
	int_vector.clear();
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;
	cout << "int_vector size : " << int_vector.size() << endl;
	cout << "int_vector capacity : " << int_vector.capacity() << endl;
	if (int_vector.empty())
		cout << "int_vector is empty." << endl;
	else
		cout << "int_vector isn't empty." << endl;

	cout << "Modify int_vector and create another." << endl;

	int_vector.push_back(1);
	int_vector.push_back(2);
	int_vector.push_back(3);
	int_vector.push_back(4);
	int_vector.push_back(5);
	ft::vector<int> int_vector_compare(10, 42);
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;

	cout << "Test swap." << endl;

	int_vector.swap(int_vector_compare);
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;

	cout << "Test non member functions overload." << endl;

	if (int_vector == int_vector_compare)
		cout << "int_vector is equal to int_vector_compare." << endl;
	else
		cout << "int_vector isn't equal to int_vector_compare." << endl;
	if (int_vector != int_vector_compare)
		cout << "int_vector is different to int_vector_compare." << endl;
	else
		cout << "int_vector isn't different to int_vector_compare." << endl;
	if (int_vector < int_vector_compare)
		cout << "int_vector is less than int_vector_compare." << endl;
	else
		cout << "int_vector isn't less than int_vector_compare." << endl;
	if (int_vector <= int_vector_compare)
		cout << "int_vector is less or equal to int_vector_compare." << endl;
	else
		cout << "int_vector isn't less or equal to int_vector_compare." << endl;
	if (int_vector > int_vector_compare)
		cout << "int_vector is greater than int_vector_compare." << endl;
	else
		cout << "int_vector isn't greater than int_vector_compare." << endl;
	if (int_vector >= int_vector_compare)
		cout << "int_vector is greater or equal to int_vector_compare." << endl;
	else
		cout << "int_vector isn't greater or equal to int_vector_compare." << endl;
	swap(int_vector, int_vector_compare);
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;

	cout << "Insert multiple elements." << endl;

	int_vector.insert(int_vector.begin() + 3, 5, 0);
	for(size_t i = 0; i < int_vector.size(); i++)
		cout << int_vector[i] << endl;

	cout << "Create str vector." << endl;

	ft::vector<std::string>	str_vector;
	str_vector.push_back("Bonjour.");
	str_vector.push_back("Yo !");
	str_vector.push_back("Il marche bien ton vecteur ?");
	str_vector.push_back("Il est ni-quel.");
	ft::vector<std::string>::iterator it;
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		cout << *it << endl;

	cout << "Create a second str vector." << endl;

	ft::vector<std::string>	str_vector_2;
	str_vector_2.push_back("Ça va ?");
	str_vector_2.push_back("Oui et toi ?");
	str_vector_2.push_back("Bof...");
	str_vector_2.push_back("Qu'est-ce qu'il y a ?");
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		cout << *it << endl;

	cout << "Insert and erase with iterators." << endl;

	str_vector.insert(str_vector.begin() + 2, str_vector_2.begin(), str_vector_2.end());
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		cout << *it << endl;
	str_vector_2.erase(str_vector_2.begin() + 2, str_vector_2.end());
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		cout << *it << endl;
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		cout << *it << endl;

	cout << "Insert and erase." << endl;

	str_vector.erase(str_vector.begin() + 2);
	str_vector.insert(str_vector.begin() + 2, "Oui !");
	str_vector.erase(str_vector.begin() + 3);
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		cout << *it << endl;

	cout << "Operator=" << endl;

	str_vector_2 = str_vector;
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		cout << *it << endl;
	
	cout << "Create a third str vector." << endl;

	ft::vector<std::string>	str_vector_3;
	str_vector_3.push_back("Pouloulou");
	str_vector_3.push_back("Jfais repérage de femmes sur les réseaux.");
	for(it = str_vector_3.begin(); it < str_vector_3.end(); ++it)
		cout << *it << endl;

	cout << "Assign with iterators" << endl;
	str_vector_2.assign(str_vector_3.begin(), str_vector_3.end());
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		cout << *it << endl;
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		cout << *it << endl;
	for(it = str_vector_3.begin(); it < str_vector_3.end(); ++it)
		cout << *it << endl;

	cout << "Create a fourth str vector with iterators and a fifth with copy constructor." << endl;

	ft::vector<std::string> str_vector_4(str_vector.begin(), str_vector.end());
	for(it = str_vector_4.begin(); it < str_vector_4.end(); ++it)
		cout << *it << endl;
	ft::vector<std::string> str_vector_5(str_vector_3);
	for(it = str_vector_5.begin(); it < str_vector_5.end(); ++it)
		cout << *it << endl;

	// cout << endl << "----------Tester----------" << endl << endl;

	// test_vector();

	cout << endl << "----------Stack----------" << endl << endl;

	cout << "Create 3 differents stacks and test their size." << endl;

	ft::vector<int> myvector(2, 42);
  	ft::stack<int> mystack;
  	ft::stack<int,ft::vector<int> > empty_stack;
  	ft::stack<int,ft::vector<int> > vector_stack(myvector);

  	cout << "mystack size : " << mystack.size() << endl;
	if (mystack.empty())
  		cout << "mystack is empty" << endl;
	else
		cout << "mystack isn't empty" << endl;
  	cout << "empty_stack size : " << empty_stack.size() << endl;
	if (empty_stack.empty())
  		cout << "empty_stack is empty" << endl;
	else
		cout << "empty_stack isn't empty" << endl;
  	cout << "vector_stack size : " << vector_stack.size() << endl;
	if (vector_stack.empty())
  		cout << "vector_stack is empty" << endl;
	else
		cout << "vector_stack isn't empty" << endl;

	cout << "Modify with push and pop." << endl;

	cout << vector_stack.top() << endl;
	vector_stack.push(21);
	cout << vector_stack.top() << endl;
	vector_stack.pop();
	cout << vector_stack.top() << endl;
	empty_stack.push(1);
	empty_stack.push(2);
	empty_stack.push(3);
	empty_stack.push(4);
	empty_stack.push(5);

	cout << "Test non-member overloads." << endl;

	if (vector_stack == empty_stack)
		cout << "vector_stack is equal to empty_stack." << endl;
	else
		cout << "vector_stack isn't equal to empty_stack." << endl;
	if (vector_stack != empty_stack)
		cout << "vector_stack is different to empty_stack." << endl;
	else
		cout << "vector_stack isn't different to empty_stack." << endl;
	if (vector_stack < empty_stack)
		cout << "vector_stack is less than empty_stack." << endl;
	else
		cout << "vector_stack isn't less than empty_stack." << endl;
	if (vector_stack <= empty_stack)
		cout << "vector_stack is less or equal to empty_stack." << endl;
	else
		cout << "vector_stack isn't less or equal to empty_stack." << endl;
	if (vector_stack > empty_stack)
		cout << "vector_stack is greater than empty_stack." << endl;
	else
		cout << "vector_stack isn't greater than empty_stack." << endl;
	if (vector_stack >= empty_stack)
		cout << "vector_stack is greater or equal to empty_stack." << endl;
	else
		cout << "vector_stack isn't greater or equal to empty_stack." << endl;

	cout << "Aaaaand it works with everything." << endl;

	std::deque<int> mydeque(5, 42);
	ft::stack<int,std::deque<int> > deque_stack(mydeque);

	cout << "deque_stack size : " << deque_stack.size() << endl;
	if (deque_stack.empty())
  		cout << "deque_stack is empty" << endl;
	else
		cout << "deque_stack isn't empty" << endl;
	cout << deque_stack.top() << endl;
	deque_stack.push(21);
	cout << deque_stack.top() << endl;
	deque_stack.pop();
	cout << deque_stack.top() << endl;

	// cout << endl << "----------Tester----------" << endl << endl;

	// test_stack();

	cout << endl << "----------Map----------" << endl << endl;

	cout << "Create int map and test size, empty and max_size." << endl;

	ft::map<int, char> map_int_char;
	if (map_int_char.empty())
		cout << "map_int_char is empty." << endl;
	else
		cout << "map_int_char isn't empty." << endl;
	map_int_char.insert(ft::make_pair<int, char>(100, 'a'));
	map_int_char.insert(ft::make_pair<int, char>(10, 'b'));
	map_int_char.insert(ft::make_pair<int, char>(30, 'c'));
	map_int_char.insert(ft::make_pair<int, char>(20, 'd'));
	map_int_char.insert(ft::make_pair<int, char>(80, 'e'));
	cout << "map_int_char max_size : " << map_int_char.max_size() << endl;
	cout << "map_int_char size : " << map_int_char.size() << endl;
	if (map_int_char.empty())
		cout << "map_int_char is empty." << endl;
	else
		cout << "map_int_char isn't empty." << endl;
	map_int_char.insert(ft::make_pair<int, char>(90, 'f'));
	map_int_char.insert(ft::make_pair<int, char>(40, 'g'));
	map_int_char.insert(ft::make_pair<int, char>(70, 'h'));
	map_int_char.insert(ft::make_pair<int, char>(60, 'i'));
	map_int_char.insert(ft::make_pair<int, char>(50, 'j'));
	cout << "map_int_char size : " << map_int_char.size() << endl;
	cout << "map_int_char max_size : " << map_int_char.max_size() << endl;

	for(ft::map<int, char>::iterator it = map_int_char.begin(); it != map_int_char.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Test clear." << endl;
	
	map_int_char.clear();
	for(ft::map<int, char>::iterator it = map_int_char.begin(); it != map_int_char.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;
	cout << "map_int_char size : " << map_int_char.size() << endl;
	if (map_int_char.empty())
		cout << "map_int_char is empty." << endl;
	else
		cout << "map_int_char isn't empty." << endl;

	cout << "Insert again." << endl;

	map_int_char.insert(ft::make_pair<int, char>(30, 'c'));
	map_int_char.insert(ft::make_pair<int, char>(60, 'i'));
	map_int_char.insert(ft::make_pair<int, char>(80, 'e'));
	map_int_char.insert(ft::make_pair<int, char>(100, 'a'));
	map_int_char.insert(ft::make_pair<int, char>(90, 'f'));
	map_int_char.insert(ft::make_pair<int, char>(40, 'g'));
	map_int_char.insert(ft::make_pair<int, char>(20, 'd'));
	map_int_char.insert(ft::make_pair<int, char>(70, 'h'));
	map_int_char.insert(ft::make_pair<int, char>(10, 'b'));
	map_int_char.insert(ft::make_pair<int, char>(50, 'j'));
	for(ft::map<int, char>::iterator it = map_int_char.begin(); it != map_int_char.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Construct a map with copy and insert." << endl;
	
	ft::map<int, char> map_int_char_compare(map_int_char);
	map_int_char_compare.insert(ft::make_pair<int, char>(25, 'k'));
	map_int_char_compare.insert(ft::make_pair<int, char>(5, 'l'));
	map_int_char_compare.insert(ft::make_pair<int, char>(85, 'm'));
	map_int_char_compare.insert(ft::make_pair<int, char>(95, 'n'));
	map_int_char_compare.insert(ft::make_pair<int, char>(15, 'o'));
	for(ft::map<int, char>::iterator it = map_int_char_compare.begin(); it != map_int_char_compare.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Test non member functions overload." << endl;

	if (map_int_char == map_int_char_compare)
		cout << "map_int_char is equal to map_int_char_compare." << endl;
	else
		cout << "map_int_char isn't equal to map_int_char_compare." << endl;
	if (map_int_char != map_int_char_compare)
		cout << "map_int_char is different to map_int_char_compare." << endl;
	else
		cout << "map_int_char isn't different to map_int_char_compare." << endl;
	if (map_int_char < map_int_char_compare)
		cout << "map_int_char is less than map_int_char_compare." << endl;
	else
		cout << "map_int_char isn't less than map_int_char_compare." << endl;
	if (map_int_char <= map_int_char_compare)
		cout << "map_int_char is less or equal to map_int_char_compare." << endl;
	else
		cout << "map_int_char isn't less or equal to map_int_char_compare." << endl;
	if (map_int_char > map_int_char_compare)
		cout << "map_int_char is greater than map_int_char_compare." << endl;
	else
		cout << "map_int_char isn't greater than map_int_char_compare." << endl;
	if (map_int_char >= map_int_char_compare)
		cout << "map_int_char is greater or equal to map_int_char_compare." << endl;
	else
		cout << "map_int_char isn't greater or equal to map_int_char_compare." << endl;
	
	cout << "Test swap." << endl;

	map_int_char.swap(map_int_char_compare);
	for(ft::map<int, char>::iterator it = map_int_char_compare.begin(); it != map_int_char_compare.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Insert with iterators." << endl;

	map_int_char_compare.insert(map_int_char.begin(), map_int_char.end());
	for(ft::map<int, char>::iterator it = map_int_char_compare.begin(); it != map_int_char_compare.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Operator= with new map." << endl;

	ft::map<int, char> map_int_char_2;
	map_int_char_2 = map_int_char;
	for(ft::map<int, char>::iterator it = map_int_char_2.begin(); it != map_int_char_2.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Erase with find." << endl;

	map_int_char_2.erase(map_int_char_2.find(15));
	map_int_char_2.erase(map_int_char_2.find(95));
	map_int_char_2.erase(map_int_char_2.find(5));
	map_int_char_2.erase(map_int_char_2.find(25));
	map_int_char_2.erase(map_int_char_2.find(85));
	for(ft::map<int, char>::iterator it = map_int_char_2.begin(); it != map_int_char_2.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Erase with iterators." << endl;

	map_int_char_compare.erase(map_int_char_compare.begin(), map_int_char_compare.find(60));
	for(ft::map<int, char>::iterator it = map_int_char_compare.begin(); it != map_int_char_compare.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	cout << "Count." << endl;

	cout << "5 is in the map : " << map_int_char.count(5) << endl;
	cout << "9 is in the map : " << map_int_char.count(9) << endl;
	cout << "1 is in the map : " << map_int_char.count(1) << endl;
	cout << "101 is in the map : " << map_int_char.count(101) << endl;

	cout << "Upper_bound and lower_bound." << endl;
	
	cout << "2 lower_bound same as begin : " << (map_int_char_compare.lower_bound(2) == map_int_char_compare.begin()) << endl;
	cout << "2 upper_bound same as begin : " << (map_int_char_compare.upper_bound(2) == map_int_char_compare.begin()) << endl;
	cout << "103 lower_bound same as end : " << (map_int_char_compare.lower_bound(103) == map_int_char_compare.end()) << endl;
	cout << "103 upper_bound same as end : " << (map_int_char_compare.upper_bound(103) == map_int_char_compare.end()) << endl;
	cout << "24 lower_bound : " << map_int_char_compare.lower_bound(24)->first << endl;
	cout << "24 upper_bound : " << map_int_char_compare.upper_bound(24)->first << endl;
	cout << "25 lower_bound : " << map_int_char_compare.lower_bound(25)->first << endl;
	cout << "25 upper_bound : " << map_int_char_compare.upper_bound(25)->first << endl;
	cout << "26 lower_bound : " << map_int_char_compare.lower_bound(26)->first << endl;
	cout << "26 upper_bound : " << map_int_char_compare.upper_bound(26)->first << endl;

	cout << "Equal range." << endl;

	cout << "2 same as begin : " << (map_int_char_compare.equal_range(2).first == map_int_char_compare.begin()) << endl;
	cout << "2 same as begin : " << (map_int_char_compare.equal_range(2).second == map_int_char_compare.begin()) << endl;
	cout << "103 same as end : " << (map_int_char_compare.equal_range(103).first == map_int_char_compare.end()) << endl;
	cout << "103 same as end : " << (map_int_char_compare.equal_range(103).second == map_int_char_compare.end()) << endl;
	cout << "24 : " << map_int_char_compare.equal_range(24).first->first << endl;
	cout << "24 : " << map_int_char_compare.equal_range(24).second->first << endl;
	cout << "25 : " << map_int_char_compare.equal_range(25).first->first << endl;
	cout << "25 : " << map_int_char_compare.equal_range(25).second->first << endl;
	cout << "26 : " << map_int_char_compare.equal_range(26).first->first << endl;
	cout << "26 : " << map_int_char_compare.equal_range(26).second->first << endl;

	cout << "Constructor with iterators." << endl;

	ft::map<int, char> map_int_char_again(map_int_char_compare.begin(), map_int_char_compare.find(50));
	for(ft::map<int, char>::iterator it = map_int_char_again.begin(); it != map_int_char_again.end(); ++it)
		cout << "Key : " << it->first << " | Value : " << it->second << endl;

	// cout << endl << "----------Tester----------" << endl << endl;

	// test_map();

	return (0);
}
