/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:05:50 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 07:25:17 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

static int	check_ra(t_stacks *stacks)
{
	t_actions	*temp;

	temp = stacks->moves;
	while (temp->next != stacks->moves)
	{
		if ((temp->move == RA && temp->next->move == RB) || \
				(temp->move == RB && temp->next->move == RA))
		{
			delete_action(stacks, temp->next);
			temp->move = RR;
			return (1);
		}
		else
			temp = temp->next;
	}
	return (0);
}

static int	check_pa(t_stacks *stacks)
{
	t_actions	*temp;

	temp = stacks->moves;
	while (temp->next != stacks->moves)
	{
		if ((temp->move == PA && temp->next->move == PB) || \
				(temp->move == PB && temp->next->move == PA))
		{
			delete_action(stacks, temp->next);
			delete_action(stacks, temp);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

static int	check_rra(t_stacks *stacks)
{
	t_actions	*temp;

	temp = stacks->moves;
	while (temp->next != stacks->moves)
	{
		if ((temp->move == RRA && temp->next->move == RA) || \
				(temp->move == RA && temp->next->move == RRA))
		{
			delete_action(stacks, temp->next);
			delete_action(stacks, temp);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

static int	check_rrb(t_stacks *stacks)
{
	t_actions	*temp;

	temp = stacks->moves;
	while (temp->next != stacks->moves)
	{
		if ((temp->move == RRB && temp->next->move == RB) || \
				(temp->move == RB && temp->next->move == RRB))
		{
			delete_action(stacks, temp->next);
			delete_action(stacks, temp);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int			optimiser(t_stacks *stacks, t_actions *moves)
{
	t_actions	*temp;

	if (check_ra(stacks))
		return (1);
	if (check_pa(stacks))
		return (1);
	if (check_rra(stacks))
		return (1);
	if (check_rrb(stacks))
		return (1);
	temp = moves;
	while (temp->next != stacks->moves)
	{
		if ((temp->move == SA && temp->next->move == SB) || \
				(temp->move == SB && temp->next->move == SA))
		{
			delete_action(stacks, temp->next);
			temp->move = SS;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
