/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:06:34 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/29 14:51:10 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
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
	int					move : 8;
	struct s_actions	*next;
	struct s_actions	*prev;
}					t_actionss;

typedef struct		s_stack
{
	t_lst			*a;
	t_lst			*b;
	t_moves			*moves;
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

t_lst				*normalize(t_stack *stacks, t_lst *new, int i, int j);
t_lst				*create_clist(int data, t_stack *stacks);
void				add_before(t_lst *element, int data, t_stack *stacks);
void				add_after(t_lst *element, int data, t_stack *stacks);
void				add_to_top(t_lst **head, int data, t_stack *stacks);
void				add_to_tail(t_lst *head, int data, t_stack *stacks);
void				remove_head(t_lst **head);
void				print_stacks(t_stack *stacks);
void				get_input(t_stack *stacks);
int					is_sorted(t_stack *stacks);
void				jt(uint8_t jump_index, t_stack *stacks);
int					count_lst(t_lst *stack);

int					get_median(t_lst *stack, int len);
int					get_max(t_lst *stack);
int					get_min(t_lst *stack);
int					get_dist(t_lst *stack, int nb);
int					count_lst(t_lst *stack);
void				sort_array(int *arr, int end);
t_rotate			*parse_info(t_lst *stack);

void				push_biggest(t_stack *stacks, t_rotate *info);
void				push_smallest(t_stack *stacks, t_rotate *info);
void				smart_rotate(t_stack *stacks);
void				sort_back_a(t_stack *stacks, int len);
int					sort_back(t_stack *stacks, int len);

char				*get_color(int m);
void				init_vis(t_stack *stacks, char *s, int i);

int					right_order(t_lst *stack);
int					solver(t_stack *stacks);
void				five(t_stack *stacks);
void				split_a(t_stack *stacks, int len, int i, int flag);
void				quicksort(t_stack *stacks, int len);

void				error_exit(t_stack *stacks);
void				exit_push_swap(t_stack *stacks);
void				free_stacks(t_stack *stacks);
void				remove_element(t_lst **head, t_lst *element);
void				remove_element(t_lst **head, t_lst *element);
void				remove_first_element(t_lst *head);
void				remove_last_element(t_lst *head);

void				create_moves(t_stack *stacks, int move);
void				add_list(t_stack *stacks, int moves);
void				delete_move(t_stack *stacks, t_moves *move);
int					optimizer(t_stack *stacks, t_moves *moes);

void				parser(char **av, t_stack *stacks);
int					options(char *s, t_stack *stacks);
int					check_duplicate(t_lst *head);

#endif
