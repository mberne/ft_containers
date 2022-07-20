#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <class T>
		struct is_integral : public integral_constant<T>
		{

		};
}

#endif
