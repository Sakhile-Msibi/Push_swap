/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:51:08 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 09:52:07 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

static void	print_actions(t_stack *stacks)
{
	int			act;
	static char *m[12] = {"rrr", "rra", "rrb", "rr", "ra", "rb",
		"ss", "sa", "sb", "pa", "pb", "start"};

	if (stacks->flags & HIDE)
		return ;
	stacks->moves = stacks->moves->next;
	while (stacks->moves->move != 11)
	{
		act = stacks->moves->move;
		if (stacks->flags & COLORS)
			ft_printf("%s%s\033[0m\n", get_colour(act), m[act]);
		else
			ft_printf("%s\n", m[act]);
		stacks->moves = stacks->moves->next;
	}
}

static void	print_actions_count(t_stack *stacks)
{
	t_actions	*temp;
	int			i;

	i = 0;
	temp = stacks->moves;
	while (temp != stacks->moves->prev)
	{
		temp = temp->next;
		i++;
	}
	ft_printf("--> %d moves for %d numbers.\n", i, count_list(stacks->a));
}

static void	print_usage(void)
{
	ft_printf("Usage:\n\t./push_swap \"50 40 60\" OR ./push_swap 50 40 60\n");
	ft_printf("Options:\n\t[-c (colored moves)]\n");
	ft_printf("\t[-m (count # of moves)]\n\t[-n (hide moves)]\n");
	ft_printf("\t[-u (usage)]\n");
	ft_printf("Combined use:\n\t/push_swap \"50 40 60\" | ");
	ft_printf("./checker \"50 40 60\"\n");
}

static void	special_handler(t_stack *s)
{
	t_lst	*new;

	new = NULL;
	new = normalize(s, new, 0, 0);
	free_stacks(s);
	s->a = new;
	create_actions(s, 11);
	if (is_sorted(s) && (s->flags & MOVES))
		print_actions_count(s);
	if (is_sorted(s))
		exit_push_swap(s);
	if (s->a->data == 1 && s->a->next->data == 3 && s->a->next->next->data == 2)
		jt(SA, s);
	if (s->a->data == 3 && s->a->next->data == 2 && s->a->next->next->data == 1)
		jt(SA, s);
	if (s->a->data == 2 && s->a->next->data == 3 && s->a->next->next->data == 1)
		jt(RRA, s);
	if (s->a->data == 2 && s->a->next->data == 1 && s->a->next->next->data == 3)
		jt(SA, s);
	if (s->a->data == 3 && s->a->next->data == 1 && s->a->next->next->data == 2)
		jt(RA, s);
}

int			main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (0);
	if (!(stacks = (t_stack *)malloc(sizeof(*stacks))))
		return (0);
	stacks->b = NULL;
	stacks->moves = NULL;
	parser(argv, stacks);
	if (stacks->a && (stacks->flags & USAGE))
		print_usage();
	if (!(stacks->a) || stacks->flags & USAGE)
		exit_push_swap(stacks);
	(is_sorted(stacks) || count_list(stacks->a) == 3) ?
		special_handler(stacks) : solver(stacks);
	while (optimiser(stacks, stacks->moves) == 1)
		argc++;
	(stacks->flags & MOVES) ?
		print_actions_count(stacks) : print_actions(stacks);
	free_stacks(stacks);
	free(stacks);
	return (0);
}
