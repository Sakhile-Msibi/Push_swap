/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_opp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:20:48 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/19 11:51:10 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(t_stack *stacks, int move)
{
	t_actions	*new;

	if (!(new = (t_actions *)malloc(sizeof(*new))))
		error_exit(stacks);
	new->move = move;
	new->next = stacks->moves;
	new->prev = stacks->moves->prev;
	stacks->moves->prev->next = new;
	stacks->moves->prev = new;
}

void	create_actions(t_stack *stacks, int move)
{
	t_actions	*new;

	if (!(new = (t_actions *)malloc(sizeof(*new))))
		error_exit(stacks);
	new->move = move;
	new->next = new;
	new->prev = new;
	stacks->moves = new;
}

void	delete_action(t_stack *stacks, t_actions *move)
{
	if ((stacks->moves))
	{
		move->prev->next = move->next;
		move->next->prev = move->prev;
		free(move);
		move = NULL;
	}
}
