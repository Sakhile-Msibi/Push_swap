/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:17:09 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 07:36:49 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

int			greater_median(t_stack *stacks, int median, int flag)
{
	if (stacks->a->data >= (median / 4))
	{
		if (flag > 0 && flag--)
			rotate_ab(stacks);
		else
			rotate_a(stacks);
	}
	else
		rotate_a(stacks);
	return (flag);
}

int			finish(t_stack *stacks)
{
	(stacks->a->data > stacks->a->next->data) ? sa(stacks) : 0;
	while ((stacks->b))
		smart_rotate(stacks);
	return (1);
}

static void	resplit(t_stack *stacks, int min, int counter)
{
	int	pushed;

	pushed = sort_back(stacks, min);
	sort_back_a(stacks, sort_back(stacks, counter - min));
	sort_back_a(stacks, pushed);
}

void		split_a(t_stack *stacks, int len, int i, int flag)
{
	int	median;
	int	counter;
	int	min;

	if ((len == 2 || len == 1) && finish(stacks))
		return ;
	counter = 0;
	median = get_median(stacks->a, len);
	min = 0;
	while (i++ < len)
	{
		if (stacks->a->data <= median)
		{
			while (flag > 0 && flag--)
				rotate_b(stacks);
			if (stacks->a->data < (median / 2) && flag++ >= 0)
				min++;
			push_b(stacks);
			counter++;
		}
		else
			flag = greater_median(stacks, median, flag);
	}
	(counter > 20) ? resplit(stacks, min, counter) : 0;
	split_a(stacks, len - counter, 0, 0);
}

int			solver(t_stack *stacks)
{
	int		len;
	t_lst	*temp;
	t_lst	*new;
	int		i;

	new = NULL;
	new = normalize(stacks, new, 0, 0);
	free_stacks(stacks);
	stacks->a = new;
	stacks->b = NULL;
	stacks->moves = NULL;
	stacks->p = 0;
	create_moves(stacks, 11);
	len = count_lst(stacks->a);
	split_a(stacks, len, 0, 0);
	temp = stacks->a;
	if (right_order(stacks->a))
	{
		i = 0;
		while (i++ < (len / 2) && temp->data != 1)
			temp = temp->next;
		while (!is_sorted(stacks))
			jt((i < (len / 2)) ? 4 : 1, stacks);
	}
	return (1);
}
