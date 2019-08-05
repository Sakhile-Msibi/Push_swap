/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:14:35 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/05 13:18:36 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_element(t_lst **head, t_lst *element)
{
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		element->prev->next = element->next;
		element->next->prev = element->prev;
		free(element);
	}
}

void	remove_head(t_lst **head)
{
	t_lst *temp;

	if (!(*head))
		return ;
	temp = (*head)->next;
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		free(*head);
		*head = temp;
	}
}
