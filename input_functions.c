/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 08:45:43 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/05 13:28:45 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_action(t_stack *s, char *line)
{
	int			i;
	static char	*actions[] = {"rrr", "rra", "rrb", "rr", "ra", "rb", "ss",
		"sa", "sb", "pa", "pb", NULL};

	i = 0;
	while (actions[i] != NULL)
	{
		if (ft_strcmp(line, actions[i]) == 0)
		{
			jt(i, s);
			(s->flags & VISUALIZER) ? init_vis(s, actions[i], i) : 0;
			break ;
		}
		i++;
	}
	free(line);
	if (actions[i] == NULL)
		error_exit(s);
}

void		input(t_stack *s)
{
	char	*line;

	line = NULL;
	(s->flags & VISUALIZER) ? init_vis(s, "\033[32;5mSTART\033[0m", 0) : 0;
	if (get_next_line(0, &line) == 0)
	{
		free(line);
		return ;
	}
	else
		execute_action(s, line);
	while (get_next_line(0, &line) != 0)
		execute_action(s, line);
	free(line);
}
