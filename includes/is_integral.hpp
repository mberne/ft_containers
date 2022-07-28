#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

	template <class T, T v>
		struct integral_constant
		{
			static constexpr T				value = v;
			typedef T						value_type;
			typedef integral_constant<T,v>	type;
			constexpr operator T()
			{
				return v;
			}
		};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class T>
		struct is_integral_check : public false_type {};
	template <bool T>
		struct is_integral_check : public true_type {};
	template <char T>
		struct is_integral_check : public true_type {};
	template <char16_t T>
		struct is_integral_check : public true_type {};
	template <char32_t T>
		struct is_integral_check : public true_type {};
	template <wchar_t T>
		struct is_integral_check : public true_type {};
	template <signed char T>
		struct is_integral_check : public true_type {};
	template <short int T>
		struct is_integral_check : public true_type {};
	template <int T>
		struct is_integral_check : public true_type {};
	template <long int T>
		struct is_integral_check : public true_type {};
	template <long long int T>
		struct is_integral_check : public true_type {};
	template <unsigned char T>
		struct is_integral_check : public true_type {};
	template <unsigned short int T>
		struct is_integral_check : public true_type {};
	template <unsigned int T>
		struct is_integral_check : public true_type {};
	template <unsigned long int T>
		struct is_integral_check : public true_type {};
	template <unsigned long long int T>
		struct is_integral_check : public true_type {};


	template<class T>
		struct remove_cv
		{
			typedef T type;
		};
	template<class T>
		struct remove_cv<const T>
		{
			typedef T type;
		};
	template<class T>
		struct remove_cv<volatile T>
		{
			typedef T type;
		};
	template<class T>
		struct remove_cv<const volatile T>
		{
			typedef T type;
		};

	template <T>
		struct is_integral : public is_integral_check< remove_cv<T> >::type
}

#endif
