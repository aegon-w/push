NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c ft_split.c utils_ps.c ft_lstadd_back_bonus.c rule_name.c sorting_algos.c main.c sorting_100_500.c instractions.c is_stack_sorted.c\
		ft_lstadd_front_bonus.c  ft_lstlast_bonus.c  ft_lstnew_bonus.c ft_lstsize_bonus.c re_index.c LIS.c rules.c
BONUS = checker.c ft_split.c utils_ps.c ft_lstadd_back_bonus.c rule_name_ch.c  is_stack_sorted.c\
		ft_lstadd_front_bonus.c  ft_lstlast_bonus.c  ft_lstnew_bonus.c ft_lstsize_bonus.c re_index.c  rules.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: all re clean fclean