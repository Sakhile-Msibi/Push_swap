/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:54:06 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/16 11:02:57 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void	swap_a(t_stack *stacks)
{
	int	temp;

	if (stacks->a && stacks->a != stacks->a->next)
	{
		temp = stacks->a->data;
		stacks->a->data = stacks->a->next->data;
		stacks->a->next->data = temp;
		add_list(stacks, SA);
	}
}

void	swap_b(t_stack *stacks)
{
	int	temp;

	if (stacks->b && stacks->b != stacks->b->next)
	{
		temp = stacks->b->data;
		stacks->b->data = stacks->b->next->data;
		stacks->b->next->data = temp;
		add_list(stacks, SB);
	}
}

void	swap_ab(t_stack *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}
