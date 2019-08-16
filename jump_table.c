/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:31:04 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 07:32:13 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void	jt(uint8_t jump_index, t_stacks *stacks)
{
	static void	(*pf[])(t_stacks *stacks) = {rrr, rra, rrb, rr, ra, rb, ss, \
		sa, sb, pa, pb};

	if (jump_index < 12)
		pf[jump_index](stacks);
}
