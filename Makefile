#========================================#
#=============== VARIABLES ==============#
#========================================#

#~~~~ Output ~~~~#

STD_OUT		=		std_tests.out
FT_OUT		=		ft_tests.out

#~~~~ Paths ~~~~#

PATH_SRC	=		srcs/
PATH_INC	=		includes/
PATH_OUT	=		test_outputs/

#~~~~ Sources ~~~~#
 
SRCS		=		$(addprefix $(PATH_SRC), main.cpp)

#~~~~ Includes ~~~~#

INCS		=		$(addprefix $(PATH_INC), iterator.hpp iterator_traits.hpp reverse_iterator.hpp enable_if.hpp is_integral.hpp equal.hpp lexicographical_compare.hpp vector.hpp stack.hpp pair.hpp avl_tree_iterator.hpp avl_tree_rebalance.hpp avl_tree.hpp map.hpp)

#~~~~ Macros ~~~~#

CC			=		c++
CFLAGS		=		-Wall -Wextra -Werror -std=c++98
RM			=		rm -rf

#========================================#
#=============== TARGETS ================#
#========================================#

#~~~~ Main Rules ~~~~#

all :			$(STD_OUT) $(FT_OUT)

$(STD_OUT) :	$(SRCS) $(INCS)
				@mkdir -p $(PATH_OUT)
				$(CC) $(CFLAGS) $(SRCS) -D STD -o $(STD_OUT) -I$(PATH_INC)

$(FT_OUT) :		$(SRCS) $(INCS)
				@mkdir -p $(PATH_OUT)
				$(CC) $(CFLAGS) $(SRCS) -o $(FT_OUT) -I$(PATH_INC)

diff :			all
				./$(STD_OUT) > $(PATH_OUT)std_out.txt | ./$(FT_OUT) > $(PATH_OUT)ft_out.txt
				diff $(PATH_OUT)std_out.txt $(PATH_OUT)ft_out.txt

re :			fclean all

#~~~~ Cleaning Rules ~~~~#

fclean :
					$(RM) $(STD_OUT) $(FT_OUT) $(PATH_OUT)

.PHONY:				all fclean re
