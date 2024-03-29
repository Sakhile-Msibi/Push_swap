/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:06:34 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/19 11:46:24 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdlib.h>

# define ABS(X) (X < 0) ? -X : X

# define VISUALIZER (1 << 0)
# define USAGE  (1 << 1)
# define MOVES  (1 << 2)
# define COLORS (1 << 3)
# define HIDE   (1 << 4)
# define SLOW   (1 << 5)

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_actions
{
	int					move;
	struct s_actions	*next;
	struct s_actions	*prev;
}					t_actions;

typedef struct		s_stack
{
	t_lst			*a;
	t_lst			*b;
	t_actions		*moves;
	short			flags;
	short			p;
}					t_stack;

typedef struct		s_line
{
	int				nb;
	char			*s;
	struct s_line	*next;
}					t_line;

typedef struct		s_rotate
{
	int				max;
	int				min;
	int				maxdist;
	int				mindist;
	int				maxdist2;
	int				mindist2;
	int				sorted[4];
	int				flag;
}					t_rotate;

/*
**	quicksort1.c
*/

t_lst				*normalize(t_stack *stacks, t_lst *new, int i, int j);
int					count_lst(t_lst *stack);
void				sort_array(int *arr, int end);
int					get_median(t_lst *stack, int len);

/*
**	create_lst.c
*/

t_lst				*create_lst(int data, t_stack *stacks);
void				add_to_top(t_lst **head, int data, t_stack *stacks);
void				add_to_tail(t_lst *head, int data, t_stack *stacks);

/*
**	remove_lst.c
*/

void				remove_head(t_lst **head);
void				remove_element(t_lst **head, t_lst *element);

/*
**	input_functions.c
*/

void				input(t_stack *stacks);

/*
**	is_sorted.c
*/

int					is_sorted(t_stack *stacks);
int					right_order(t_lst *stack);

/*
**	jump_table.c
*/

void				jt(uint8_t jump_index, t_stack *stacks);

/*
**	quicksort5.c
*/

int					get_max(t_lst *stack);
int					get_min(t_lst *stack);
int					get_dist(t_lst *stack, int nb);
t_rotate			*parse_info(t_lst *stack);

/*
**	quicksort4.c
*/

void				push_biggest(t_stack *stacks, t_rotate *info);
void				push_smallest(t_stack *stacks, t_rotate *info);

/*
**	quicksort3.c
*/

void				smart_rotate(t_stack *stacks);
void				sort_back_a(t_stack *stacks, int len);
int					sort_back(t_stack *stacks, int len);

/*
**	get_colour.c
*/

char				*get_colour(int m);

/*
**	visual_functions.c
*/

void				init_vis(t_stack *stacks, char *s, int i);

/*
** quicksort2.c
*/

void				split_a(t_stack *stacks, int len, int i, int flag);
int					solver(t_stack *stacks);

/*
**	error_management.c
*/

void				error_exit(t_stack *stacks);
void				exit_push_swap(t_stack *stacks);
void				free_stacks(t_stack *stacks);

/*
**	list_opp.c
*/

void				create_actions(t_stack *stacks, int move);
void				add_list(t_stack *stacks, int moves);
void				delete_action(t_stack *stacks, t_actions *move);

/*
**	action_optimiser.c
*/

int					optimiser(t_stack *stacks, t_actions *moes);

/*
**	input_parser.c
*/

void				input_parser(char **argv, t_stack *stacks);
int					check_dup(t_lst *head);

/*
**flag_options.c
*/

int					flag_options(char *s, t_stack *stacks);

#endif
