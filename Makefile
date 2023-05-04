NAME = push_swap
NAME_BONUS = checker

SRCS =	./instructions/instructions_1.c \
		./instructions/instructions_2.c \
		./instructions/instructions_3.c \
		./parse_and_lists/ft_split.c \
		./parse_and_lists/list_functions_2.c \
		./parse_and_lists/list_functions.c \
		./parse_and_lists/parsing_string.c \
		./parse_and_lists/parsing_string_2.c \
		./parse_and_lists/utils.c \
		./algorithm_of_sort/algorithm.c \
		./algorithm_of_sort/small_sorting.c	\
		./algorithm_of_sort/small_sorting_2.c \
		./algorithm_of_sort/algorithm_utils.c \
		./algorithm_of_sort/full_sorting.c \
		./algorithm_of_sort/algorithm_2.c

SRCS_MAIN =	./algorithm_of_sort/push_swap.c

SRCS_BONUS =	./checker_bonus/checker.c \
				./checker_bonus/get_next_line/get_next_line.c \
				./checker_bonus/get_next_line/get_next_line_utils.c


HEADER = ./include

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_MAIN = $(SRCS_MAIN:.c=.o)


CFLAGS = -Werror -Wextra -Wall -I

all: $(NAME)

CC = cc

%.o : %.c 
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME) : $(OBJS) $(OBJS_MAIN)
	$(CC) $(OBJS) $(OBJS_MAIN) -o $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	$(CC) $(OBJS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS) $(OBJS_MAIN)

fclean:
	rm -rf $(OBJS) $(NAME) $(OBJS_BONUS) $(NAME_BONUS) $(OBJS_MAIN)

re:	fclean all

.PHONY:	all clean fclean re
