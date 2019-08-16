/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:31:04 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/16 11:07:06 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void	jt(uint8_t jump_index, t_stack *stacks)
{
	static void	(*pf[])(t_stack *stacks) =
	{reverse_rot_ab, reverse_rot_a, reverse_rot_b, rotate_ab, \
		rotate_a, rotate_b, swap_ab, swap_a, swap_b, push_a, push_b};

	if (jump_index < 12)
		pf[jump_index](stacks);
}
