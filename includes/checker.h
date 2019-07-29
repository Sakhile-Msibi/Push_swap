/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:04:39 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/29 09:30:49 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "action.h"

# define PUSH_A "pa"
# define PUSH_B "pb"
# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_AB "ss"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_AB "rr"
# define REVERSE_ROT_A "rra"
# define REVERSE_ROT_B "rrb"
# define REVERSE_ROT_AB "rrr"

typedef struct	s_action
{
	char	action_name[4];
	void	(*f)(t_stack *, t_stack *, int);
}				t_action;

#endif
