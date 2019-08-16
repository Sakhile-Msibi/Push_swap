/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:41:23 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 08:55:08 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_shap_.h"
#include "actions.h"

void	do_rotate(int nb, t_stacks *stacks)
{
	while (nb != 0)
	{
		(nb < 0) ? jt(2, stacks) : jt(5, stacks);
		nb += (nb < 0) ? 1 : -1;
	}
}

void	do_rotate_a(int nb, t_stacks *stacks)
{
	while (nb != 0)
	{
		(nb < 0) ? jt(1, stacks) : jt(4, stacks);
		nb += (nb < 0) ? 1 : -1;
	}
}

void	go_shortest_b(t_stacks *stacks, int nb)
{
	int	distance;

	if (!stacks->b)
		return ;
	distance = get_dist(stacks->b, nb);
	do_rotate(distance, stacks);
}

void	push_biggest(t_stacks *stacks, t_rotate *info)
{
	if (stacks->p ^ 1 && \
			(ABS(get_dist(stacks->b, info->max - 1))) < (ABS(info->maxdist)))
	{
		go_shortest_b(stacks, info->max - 1);
		push_a(stacks);
		stacks->p ^= 1;
	}
	else
	{
		go_shortest_b(stacks, info->max);
		push_a(stacks);
		if (stacks->p & 1)
		{
			swap_a(stacks);
			stacks->p ^= 1;
		}
	}
}

void	push_smallest(t_stacks *stacks, t_rotate *info)
{
	if ((ABS(get_dist(stacks->b, info->min + 1))) < (ABS(info->mindist)))
	{
		go_shortest_b(stacks, info->min + 1);
		push_a(stacks);
		go_shortest_b(stacks, info->min);
		push_a(stacks);
		rotate_a(stacks);
		rotate_a(stacks);
	}
	else
	{
		go_shortest_b(stacks, info->min);
		push_a(stacks);
		rotate_a(stacks);
	}
}
