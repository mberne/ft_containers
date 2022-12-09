#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

	template <class T, T v>
		struct integral_constant
		{
			const static T					value = v;
			typedef T						value_type;
			typedef integral_constant<T,v>	type;
			operator value_type() const		{ return value; }
			value_type operator()() const	{ return value; }
		};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class T>
		struct is_integral_check : public false_type {};
	template <>
		struct is_integral_check<bool> : public true_type {};
	template <>
		struct is_integral_check<char> : public true_type {};
	template <>
		struct is_integral_check<wchar_t> : public true_type {};
	template <>
		struct is_integral_check<signed char> : public true_type {};
	template <>
		struct is_integral_check<short int> : public true_type {};
	template <>
		struct is_integral_check<int> : public true_type {};
	template <>
		struct is_integral_check<long int> : public true_type {};
	template <>
		struct is_integral_check<long long int> : public true_type {};
	template <>
		struct is_integral_check<unsigned char> : public true_type {};
	template <>
		struct is_integral_check<unsigned short int> : public true_type {};
	template <>
		struct is_integral_check<unsigned int> : public true_type {};
	template <>
		struct is_integral_check<unsigned long int> : public true_type {};
	template <>
		struct is_integral_check<unsigned long long int> : public true_type {};

	template<class T>
		struct remove_cv { typedef T type; };
	template<class T>
		struct remove_cv<const T> { typedef T type; };
	template<class T>
		struct remove_cv<volatile T> { typedef T type; };
	template<class T>
		struct remove_cv<const volatile T> { typedef T type; };

	template <class T>
		struct is_integral : public is_integral_check<typename ft::remove_cv<T>::type >::type {};
}

#endif
