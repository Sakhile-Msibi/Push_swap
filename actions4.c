/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:03:32 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/16 11:09:32 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void	reverse_rot_a(t_stack *stacks)
{
	if (stacks->a && stacks->a->prev)
	{
		stacks->a = stacks->a->prev;
		add_list(stacks, RRA);
	}
}

void	reverse_rot_b(t_stack *stacks)
{
	if (stacks->b && stacks->b->prev)
	{
		stacks->b = stacks->b->prev;
		add_list(stacks, RRB);
	}
}

void	reverse_rot_ab(t_stack *stacks)
{
	reverse_rot_a(stacks);
	reverse_rot_b(stacks);
}
