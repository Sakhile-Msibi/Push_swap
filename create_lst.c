/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:08:10 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 10:25:48 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*create_lst(int data, t_stack *stacks)
{
	t_lst	*head;

	if (!(head = (t_lst *)malloc(sizeof(*head))))
		error_exit(stacks);
	if (head)
	{
		head->prev = head;
		head->next = head;
		head->data = data;
	}
	return (head);
}

void	add_to_top(t_lst **head, int data, t_stack *stacks)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(*new))))
		error_exit(stacks);
	new->data = data;
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
	*head = new;
}

void	add_to_tail(t_lst *head, int data, t_stack *stacks)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(*new))))
		error_exit(stacks);
	new->data = data;
	new->next = head;
	new->prev = (head->next == head) ? head : head->prev;
	head->prev = new;
	new->prev->next = new;
}
