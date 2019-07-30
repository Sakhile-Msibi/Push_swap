/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:33:16 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/30 09:33:49 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_numbers(t_line *x)
{
	t_line	*temp;

	if (x)
	{
		while (x != NULL)
		{
			temp = x->next;
			free(x->s);
			free(x);
			x = temp;
		}
	}
}

static t_line	*create_line_elem(t_lst *stack)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->s = ft_itoa_base_max((intmax_t)stack->data, 10)))
		return (NULL);
	new->next = NULL;
	return (new);
}

static t_line	*parse_stack(t_lst *stack)
{
	t_lst	*temp;
	t_line	*t;
	t_line	*head;

	if (!stack || (!(head = create_line_elem(stack))))
		return (NULL);
	temp = stack->next;
	if (temp == stack)
		return (head);
	t = head;
	while (temp && temp != stack)
	{
		if (!(t->next = create_line_elem(temp)))
		{
			free_numbers(head);
			return (NULL);
		}
		t = t->next;
		temp = temp->next;
	}
	return (head);
}

static void		print_vis(t_stack *stacks, char *action, int i)
{
	t_line	*a;
	t_line	*b;
	t_line	*temp;
	t_line	*temp2;

	a = parse_stack(stacks->a);
	b = parse_stack(stacks->b);
	if (!(a || b))
		return ;
	temp = a;
	temp2 = b;
	if (stacks->flags & COLORS)
		ft_printf("\tCurrent move:\t%s%s\n", get_color(i), action);
	else
		ft_printf("\tCurrent move:\t%s\n", action);
	ft_printf("%s", get_color(stacks->moves->move));
	ft_printf("\033[0m");
	while (a || b)
	{
		ft_printf("\t%7s | %s\n", a ? a->s : " ", b ? b->s : " ");
		a = (a) ? a->next : a;
		b = (b) ? b->next : b;
	}
	free_numbers(temp);
	free_numbers(temp2);
}

void			init_vis(t_stack *stacks, char *action, int i)
{
	usleep((stacks->flags & SLOW) ? 1000000 : 100000);
	ft_printf("\E[H\E[2J");
	ft_printf("\033[1m\033[34m");
	ft_printf("%15s   %-15s\x1b[0m", "Stack A", "Stack B");
	print_vis(stacks, action, i);
	ft_printf("\e[48;5;208m");
	ft_printf("\033[35m");
	ft_printf("\033[0m");
}
