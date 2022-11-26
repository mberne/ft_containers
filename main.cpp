// #include <iostream>
// #include <string>
// #include <deque>
// #include <stdlib.h>

// #if 0 //CREATE A REAL STL EXAMPLE
// 	// #include <map>
// 	// #include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	// #include <map.hpp>
// 	// #include <stack.hpp>
// 	#include <vector.hpp>
// #endif


// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

#include <iostream>
#include <string>
#include "vector.hpp"

int main()
{
	
	std::cout << std::endl << "----------Vector----------" << std::endl << std::endl;

	std::cout << "Create int vector and test resize." << std::endl;
	
	ft::vector<int> int_vector(10, 42);
	int_vector.push_back(21);
	int_vector.push_back(21);
	for(size_t i = 0; i < int_vector.size(); i++)
	{
		std::cout << "[] version : " << int_vector[i] << std::endl;
		std::cout << "at version : " << int_vector.at(i) << std::endl;
	}
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	int_vector.resize(10);
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	int_vector.resize(15, 21);
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	int_vector.resize(25);
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;

	std::cout << "Modify int vector and test reserve." << std::endl;

	for(size_t i = 0; i < 20; i++)
		int_vector.pop_back();
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	int_vector.reserve(100);
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	int_vector.reserve(30);
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;
	
	std::cout << "Test empty, front and back." << std::endl;

	if (int_vector.empty())
		std::cout << "int_vector is empty." << std::endl;
	else
		std::cout << "int_vector isn't empty." << std::endl;
	std::cout << int_vector.front() << std::endl;
	std::cout << int_vector.back() << std::endl;
	int_vector.push_back(21);
	std::cout << int_vector.front() << std::endl;
	std::cout << int_vector.back() << std::endl;
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;

	std::cout << "Test assign." << std::endl;

	int_vector.assign(2, 21);
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;

	std::cout << "Test clear." << std::endl;
	
	int_vector.clear();
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;
	std::cout << "int_vector size : " << int_vector.size() << std::endl;
	std::cout << "int_vector capacity : " << int_vector.capacity() << std::endl;
	if (int_vector.empty())
		std::cout << "int_vector is empty." << std::endl;
	else
		std::cout << "int_vector isn't empty." << std::endl;

	std::cout << "Modify int_vector and create another." << std::endl;

	int_vector.push_back(1);
	int_vector.push_back(2);
	int_vector.push_back(3);
	int_vector.push_back(4);
	int_vector.push_back(5);
	ft::vector<int> int_vector_compare(10, 42);
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;

	std::cout << "Test swap." << std::endl;

	int_vector.swap(int_vector_compare);
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;

	std::cout << "Test non member functions overload." << std::endl;

	if (int_vector == int_vector_compare)
		std::cout << "int_vector is equal to int_vector_compare." << std::endl;
	else
		std::cout << "int_vector isn't equal to int_vector_compare." << std::endl;
	if (int_vector != int_vector_compare)
		std::cout << "int_vector is different to int_vector_compare." << std::endl;
	else
		std::cout << "int_vector isn't different to int_vector_compare." << std::endl;
	if (int_vector < int_vector_compare)
		std::cout << "int_vector is less than int_vector_compare." << std::endl;
	else
		std::cout << "int_vector isn't less than int_vector_compare." << std::endl;
	if (int_vector <= int_vector_compare)
		std::cout << "int_vector is less or equal to int_vector_compare." << std::endl;
	else
		std::cout << "int_vector isn't less or equal to int_vector_compare." << std::endl;
	if (int_vector > int_vector_compare)
		std::cout << "int_vector is greater than int_vector_compare." << std::endl;
	else
		std::cout << "int_vector isn't greater than int_vector_compare." << std::endl;
	if (int_vector >= int_vector_compare)
		std::cout << "int_vector is greater or equal to int_vector_compare." << std::endl;
	else
		std::cout << "int_vector isn't greater or equal to int_vector_compare." << std::endl;
	swap(int_vector, int_vector_compare);
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;

	std::cout << "Insert multiple elements." << std::endl;

	int_vector.insert(int_vector.begin() + 3, 5, 0);
	for(size_t i = 0; i < int_vector.size(); i++)
		std::cout << int_vector[i] << std::endl;

	std::cout << "Create str vector." << std::endl;

	ft::vector<std::string>	str_vector;
	str_vector.push_back("Bonjour.");
	str_vector.push_back("Yo !");
	str_vector.push_back("Il marche bien ton vecteur ?");
	str_vector.push_back("Il est ni-quel.");
	ft::vector<std::string>::iterator it;
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Create a second str vector." << std::endl;

	ft::vector<std::string>	str_vector_2;
	str_vector_2.push_back("Ça va ?");
	str_vector_2.push_back("Oui et toi ?");
	str_vector_2.push_back("Bof...");
	str_vector_2.push_back("Qu'est-ce qu'il y a ?");
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Insert and erase with iterators." << std::endl;

	str_vector.insert(str_vector.begin() + 2, str_vector_2.begin(), str_vector_2.end());
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		std::cout << *it << std::endl;
	str_vector_2.erase(str_vector_2.begin() + 2, str_vector_2.end());
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		std::cout << *it << std::endl;
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Insert and erase." << std::endl;

	str_vector.erase(str_vector.begin() + 5);
	str_vector.insert(str_vector.begin() + 5, "Oui !");
	str_vector.erase(str_vector.begin() + 6);
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Operator=" << std::endl;

	str_vector_2 = str_vector;
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << "Create a third str vector." << std::endl;

	ft::vector<std::string>	str_vector_3;
	str_vector_3.push_back("Pouloulou");
	str_vector_3.push_back("Jfais repérage de femmes sur les réseaux.");
	for(it = str_vector_3.begin(); it < str_vector_3.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Assign with iterators" << std::endl;
	
	str_vector_2.assign(str_vector_3.begin(), str_vector_3.end());
	for(it = str_vector.begin(); it < str_vector.end(); ++it)
		std::cout << *it << std::endl;
	for(it = str_vector_2.begin(); it < str_vector_2.end(); ++it)
		std::cout << *it << std::endl;
	for(it = str_vector_3.begin(); it < str_vector_3.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Create a fourth str vector with iterators and a fifth with copy constructor." << std::endl;

	ft::vector<std::string> str_vector_4(str_vector.begin(), str_vector.end());
	for(it = str_vector_4.begin(); it < str_vector_4.end(); ++it)
		std::cout << *it << std::endl;
	ft::vector<std::string> str_vector_5(str_vector_3);
	for(it = str_vector_5.begin(); it < str_vector_5.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl << "----------Map----------" << std::endl << std::endl;

	std::cout << std::endl << "----------Stack----------" << std::endl << std::endl;

	return (0);
}
