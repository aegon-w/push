/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:08:17 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/01 17:28:45 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct comb
{
	int			a;
	int			b;
	int			c;
	int			d;
}				t_comb;

typedef struct pos
{
	int			up;
	int			up1;
	int			val;
	int			up_pos;
	int			upper;
}				t_pos;

typedef struct _int
{
	int			min;
	int			max;
}				t_int;

typedef struct lst
{
	int			data;
	int			index;
	int			min;
	int			max;
	struct lst	*next;
}				t_lst;

typedef struct updo
{
	int			up;
	int			down;
	int			up1;
	int			down1;
	t_lst		*tmp;
}				t_updo;

char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
void			ft_lstadd_front(t_lst **lst, t_lst *new);
t_lst			*ft_lstlast(t_lst *lst);
t_lst			*ft_lstnew(int content);
int				ft_lstsize(t_lst *lst);
void			re_index(t_lst *stack);
int				*stack_to_arr(t_lst *lst);
int				*lis(int *arr, int size);
void			swap_1_2(t_lst **lst);
void			push_top(t_lst **from, t_lst **to);
void			shift_up(t_lst **lst);
void			shift_down(t_lst **lst);
int				index_of(int *arr, int target, int size);
void			swap(t_lst **stack_a, t_lst **stack_b, char c);
void			push(t_lst **stack_a, t_lst **stack_b, char c);
void			rotate(t_lst **stack_a, t_lst **stack_b, char c);
void			rrotate(t_lst **stack_a, t_lst **stack_b, char c);
void			t_nb_algo(t_lst **stack_a);
void			f_nb_algo(t_lst **stack_a, t_lst **stack_b);
void			two_nb_algo(t_lst **stack_a);
int				_max(int a, int b);
int				ft_atoi(char *s);
void			check_args(t_lst *lst);
void			best_move(t_lst **stack_a, t_lst **stack_b);
int				is_stack_sorted(t_lst **stack_a);
void			sorting_100_500(t_lst **stack_a, t_lst **stack_b);
void			instraction(t_lst **stack_a, t_lst **stack_b, t_int sa,
					t_int sb);
void			swap_ch(t_lst **stack_a, t_lst **stack_b, char c);
void			push_ch(t_lst **stack_a, t_lst **stack_b, char c);
void			rotate_ch(t_lst **stack_a, t_lst **stack_b, char c);
void			rrotate_ch(t_lst **stack_a, t_lst **stack_b, char c);
char			**ft_free(char **strs, int j);

#endif
