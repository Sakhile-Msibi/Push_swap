/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:53:54 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 08:00:09 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "actions.h"

void        push_a(t_stacks *stacks)
{
    if (!(stacks->b))
        return ;
    if (stacks->a)
        add_to_top(&(stacks->a), stacks->b->data, stacks);
    else
        stacks->a = create_lst(stacks->b->data, stacks);
    remove_head(&(stacks->b));
    add_list(stacks, PA);
}

void        push_b(t_stacks *stacks)
{
    if (!(stacks->a))
        return ;
    if (stacks->b)
        add_to_top(&(stacks->b), stacks->a->data, stacks);
    else
        stacks->b = create_lst(stacks->a->data, stacks);
    remove_head(&(stacks->a));
    add_list(stacks, PB);
}
