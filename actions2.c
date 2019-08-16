/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:28:55 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/16 11:03:45 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void	rotate_a(t_stack *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		stacks->a = stacks->a->next;
		add_list(stacks, RA);
	}
}

void	rotate_b(t_stack *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		stacks->b = stacks->b->next;
		add_list(stacks, RB);
	}
}

void	rotate_ab(t_stack *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
