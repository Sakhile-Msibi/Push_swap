/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 07:43:31 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/30 08:08:04 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_dup(t_lst *head)
{
	t_lst	*tmp1;
	t_lst	*tmp2;

	tmp1 = head;
	while (tmp1 != NULL && tmp1->next != head)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL && tmp2 != head)
		{
			if (tmp2->data == tmp1->data)
			{
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

static int	check_content(const char *str, t_stack *stacks)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]) &&
				(i == 0 || str[i - 1] == ' '))
			i++;
		else if (str[i] == '+' && ft_isdigit(str[i + 1]) &&
				(i == 0 || str[i - 1] == ' '))
			i++;
		else
			error_exit(stacks);
	}
	return (1);
}

static int	check_numlen(const char *str, t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '0')
			i++;
		if (str[i] && (str[i] == '-' || str[i] == '+') &&
				ft_isdigit(str[i + 1]) && (i == 0 || str[i - 1] == ' '))
			i++;
		else
			break ;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		j++;
		i++;
		if (j > 11)
			error_exit(stacks);
	}
	return (i);
}

void		fill_stack(const char *str, t_stack *stacks)
{
	long	tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		j = check_numlen(str + i, stacks);
		if (str[i] == '\0')
			break ;
		tmp = ft_atoi_l(str + i);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_exit(stacks);
		if (!stacks->a)
			stacks->a = create_clist(tmp, stacks);
		else
			add_to_tail(stacks->a, tmp, stacks);
		i += j;
	}
}

void		parser(char **argv, t_stack *stacks)
{
	int	i;

	stacks->a = NULL;
	stacks->flags = 0;
	i = 1;
	while (argv[i])
	{
		if (options(argv[i], stacks))
			i++;
		else
		{
			check_content(argv[i], stacks);
			fill_stack(argv[i], stacks);
			if (check_dup(stacks->a))
				error_exit(stacks);
			i++;
		}
	}
}
