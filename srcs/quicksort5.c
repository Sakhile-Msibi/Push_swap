/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:39:37 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 09:50:57 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_min(t_lst *stack)
{
	int		ret;
	t_lst	*temp;

	ret = stack->data;
	temp = stack->next;
	while (temp != stack)
	{
		if (ret > temp->data)
			ret = temp->data;
		temp = temp->next;
	}
	return (ret);
}

int			get_max(t_lst *stack)
{
	int		ret;
	t_lst	*temp;

	ret = stack->data;
	temp = stack->next;
	while (temp != stack)
	{
		if (ret < temp->data)
			ret = temp->data;
		temp = temp->next;
	}
	return (ret);
}

int			get_dist(t_lst *stack, int nb)
{
	int		i;
	t_lst	*temp;
	t_lst	*temp2;

	i = 0;
	temp = stack;
	temp2 = stack;
	while (temp != stack->prev)
	{
		if (temp->data == nb)
			return (i);
		else if (temp2->data == nb)
			return ((-i));
		i++;
		temp = temp->next;
		temp2 = temp2->prev;
	}
	return (-1);
}

t_rotate	*parse_info(t_lst *stack)
{
	t_rotate	*info;
	int			counter;

	if (!stack || !(info = (t_rotate *)malloc(sizeof(*info))))
		return (NULL);
	counter = 0;
	info->min = get_min(stack);
	info->max = get_max(stack);
	info->mindist = get_dist(stack, info->min);
	info->maxdist = get_dist(stack, info->max);
	info->mindist2 = get_dist(stack, info->min + 1);
	info->maxdist2 = get_dist(stack, info->max - 1);
	return (info);
}
