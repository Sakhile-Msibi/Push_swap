/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:31:06 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 07:39:10 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stacks)
{
	t_lst	*temp;

	if (!stacks->a || (stacks->b))
		return (0);
	temp = stacks->a;
	while (temp != stacks->a->prev)
	{
		if (temp->data >= temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		right_order(t_lst *stack)
{
	int		num;
	t_lst	*temp;
	t_lst	*temp2;

	if (!stack)
		return (0);
	if (count_lst(stack) < 2)
		return (1);
	num = get_min(stack);
	temp = stack->next;
	while (num != temp->data)
		temp = temp->next;
	temp2 = temp->next;
	while (temp2 != temp)
	{
		if (num >= temp2->data)
			return (0);
		num = temp2->data;
		temp2 = temp2->next;
	}
	return (1);
}
