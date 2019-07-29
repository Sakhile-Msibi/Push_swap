/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:06:34 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/29 14:31:54 by smsibi           ###   ########.fr       */
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

typedef struct		s_clist
{
	int				data;
	struct s_clist	*next;
	struct s_clist	*prev;
}					t_clist;

typedef struct		s_moves
{
	int				move : 8;
	struct s_moves	*next;
	struct s_moves	*prev;
}					t_moves;

typedef struct		s_frame
{
	t_clist			*a;
	t_clist			*b;
	t_moves			*moves;
	short			flags;
	short			p;
}					t_frame;

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

t_clist				*normalize(t_frame *stacks, t_clist *new, int i, int j);
t_clist				*create_clist(int data, t_frame *stacks);
void				add_before(t_clist *element, int data, t_frame *stacks);
void				add_after(t_clist *element, int data, t_frame *stacks);
void				add_to_top(t_clist **head, int data, t_frame *stacks);
void				add_to_tail(t_clist *head, int data, t_frame *stacks);
void				remove_head(t_clist **head);
void				print_stacks(t_frame *stacks);
void				get_input(t_frame *stacks);
int					is_sorted(t_frame *stacks);
void				jt(uint8_t jump_index, t_frame *stacks);
int					count_list(t_clist *stack);

int					get_median(t_clist *stack, int len);
int					get_max(t_clist *stack);
int					get_min(t_clist *stack);
int					get_dist(t_clist *stack, int nb);
int					count_list(t_clist *stack);
void				sort_array(int *arr, int end);
t_rotate			*parse_info(t_clist *stack);

void				push_biggest(t_frame *stacks, t_rotate *info);
void				push_smallest(t_frame *stacks, t_rotate *info);
void				smart_rotate(t_frame *stacks);
void				sort_back_a(t_frame *stacks, int len);
int					sort_back(t_frame *stacks, int len);

char				*get_color(int m);
void				init_vis(t_frame *stacks, char *s, int i);

int					right_order(t_clist *stack);
int					solver(t_frame *stacks);
void				five(t_frame *stacks);
void				split_a(t_frame *stacks, int len, int i, int flag);
void				quicksort(t_frame *stacks, int len);

void				error_exit(t_frame *stacks);
void				exit_push_swap(t_frame *stacks);
void				free_stacks(t_frame *stacks);
void				remove_element(t_clist **head, t_clist *element);
void				remove_element(t_clist **head, t_clist *element);
void				remove_first_element(t_clist *head);
void				remove_last_element(t_clist *head);

void				create_moves(t_frame *stacks, int move);
void				add_list(t_frame *stacks, int moves);
void				delete_move(t_frame *stacks, t_moves *move);
int					optimizer(t_frame *stacks, t_moves *moves);

void				parser(char **av, t_frame *stacks);
int					options(char *s, t_frame *stacks);
int					check_duplicate(t_clist *head);

#endif
