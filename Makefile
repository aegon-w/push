NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror rules.c

SRCS = push_swap.c func1.c func2.c ft_lstadd_back_bonus.c rule_name.c sorting_algos.c main.c get_next_line.c get_next_line_utils.c\
		ft_lstadd_front_bonus.c  ft_lstlast_bonus.c  ft_lstnew_bonus.c ft_lstsize_bonus.c re_index.c LIS.c rules.c

INCLUDES = push_swap.h

all: $(NAME)

$(NAME): $(INCLUDES) $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

clean :
	rm -f $(NAME)

fclean :	clean

re : fclean all

.PHONY: re all fclean clean bonus