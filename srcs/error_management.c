/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 08:24:53 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/05 13:04:49 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_actions(t_stack *stacks)
{
	t_actions	*temp;

	if (stacks->moves)
	{
		while (stacks->moves != stacks->moves->next)
		{
			temp = stacks->moves->next;
			delete_action(stacks, stacks->moves);
			stacks->moves = temp;
		}
		delete_action(stacks, stacks->moves);
	}
	stacks->moves = NULL;
}

void		free_stacks(t_stack *stacks)
{
	t_lst	*temp;

	if (stacks->a)
	{
		while (stacks->a != stacks->a->next)
		{
			temp = stacks->a->next;
			remove_head(&(stacks->a));
			stacks->a = temp;
		}
		remove_head(&(stacks->a));
		stacks->a = NULL;
	}
	if (stacks->b)
	{
		while (stacks->b != stacks->b->next)
		{
			temp = stacks->b->next;
			remove_head(&(stacks->b));
			stacks->b = temp;
		}
		remove_head(&(stacks->b));
		stacks->b = NULL;
	}
	free_actions(stacks);
}

void		error_exit(t_stack *stacks)
{
	free_stacks(stacks);
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

void		exit_push_swap(t_stack *stacks)
{
	free_stacks(stacks);
	free(stacks);
	exit(0);
}
