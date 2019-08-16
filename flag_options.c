/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:43:09 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/05 13:26:09 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		flag_options(char *s, t_stack *stacks)
{
	int	i;

	if (s[0] != '-')
		return (0);
	i = 1;
	while (s[i] != '\0')
	{
		if (!ft_isalpha(s[(i)]))
			return (0);
		if (s[i] == 'v')
			stacks->flags |= VISUALIZER;
		if (s[i] == 'h' || s[i] == 'u')
			stacks->flags |= USAGE;
		if (s[i] == 'n')
			stacks->flags |= HIDE;
		if (s[i] == 's')
			stacks->flags |= SLOW;
		if (s[i] == 'm')
			stacks->flags |= MOVES;
		if (s[i] == 'c')
			stacks->flags |= COLORS;
		i++;
	}
	return (1);
}
