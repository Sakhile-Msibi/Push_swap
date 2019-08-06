/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:15:20 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 08:27:06 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_lst(t_lst *stack)
{
	t_lst	*temp;
	int		elements;

	if (!stack)
		return (0);
	temp = stack;
	elements = 1;
	while (temp != stack->prev)
	{
		elements++;
		temp = temp->next;
	}
	return (elements);
}

void		sort_array(int *arr, int end)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return ;
	while (i < end - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			j = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = j;
			i = 0;
		}
		else
			i++;
	}
}

static int	*list_to_array(t_lst *stack)
{
	int		*arr;
	int		i;
	t_lst	*temp;

	if (!stack || !(arr = (int*)malloc(sizeof(*arr) * count_lst(stack))))
		return (NULL);
	temp = stack;
	i = 0;
	while (temp != stack->prev)
	{
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}
	arr[i] = temp->data;
	return (arr);
}

int			get_median(t_lst *stack, int len)
{
	int	*arr;
	int	ret;

	if (!(stack))
		return (-1);
	arr = list_to_array(stack);
	sort_array(arr, len);
	ret = arr[len / 2];
	free(arr);
	return (ret);
}

t_lst		*normalize(t_stack *stacks, t_lst *new, int i, int j)
{
	int	*arr;
	int	*unsorted;
	int	len;

	len = count_lst(stacks->a);
	if (!(arr = list_to_array(stacks->a)) || \
			(!(unsorted = list_to_array(stacks->a))))
		error_exit(stacks);
	sort_array(arr, len);
	i = len;
	while (i--)
	{
		j = 0;
		while (j < len)
		{
			if (unsorted[i] == arr[j] && (!new))
				new = create_lst(j + 1, stacks);
			else if (unsorted[i] == arr[j])
				add_to_top(&new, j + 1, stacks);
			j++;
		}
	}
	free(unsorted);
	free(arr);
	return (new);
}
