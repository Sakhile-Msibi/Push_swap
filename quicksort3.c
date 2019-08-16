/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:06:16 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 08:20:32 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void	smart_rotate(t_stacks *stacks)
{
	t_rotate	*info;

	if (!(stacks->a) || !(info = parse_info(stacks->b)))
		return ;
	if ((ABS(info->maxdist)) - 1 <= (ABS(info->mindist)) && \
			((ABS(info->maxdist)) - 1 <= (ABS(info->mindist2))))
		push_biggest(stacks, info);
	else if (stacks->p ^ 1 && (ABS(info->maxdist2)) - 1 <= (ABS(info->mindist))
			&& (ABS(info->maxdist2)) - 1 <= (ABS(info->mindist2)))
		push_biggest(stacks, info);
	else
		push_smallest(stacks, info);
	free(info);
}

void	sort_back_a(t_stacks *stacks, int len)
{
	int	median;
	int	i;

	i = 0;
	median = get_median(stacks->a, len);
	while (i++ < len)
	{
		if (stacks->a->data >= median)
			push_b(stacks);
		else
		{
			push_b(stacks);
			rotate_b(stacks);
		}
	}
}

int		sort_back(t_stacks *stacks, int len)
{
	int	median;
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	median = get_median(stacks->b, len);
	while (i++ < len)
	{
		if (stacks->b->data > median)
		{
			push_a(stacks);
			temp++;
		}
		else
		{
			rotate_b(stacks);
		}
	}
	return (temp);
}
