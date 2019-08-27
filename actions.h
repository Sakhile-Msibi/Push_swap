/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:20:55 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/24 08:32:49 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# define RRR 0
# define RRA 1
# define RRB 2
# define RR 3
# define RA 4
# define RB 5
# define SS 6
# define SA 7
# define SB 8
# define PA 9
# define PB 10

void	swap_a(t_stack *stacks);
void	swap_b(t_stack *stacks);
void	swap_ab(t_stack *stacks);
void	push_b(t_stack *stacks);
void	push_a(t_stack *stacks);
void	rotate_a(t_stack *stacks);
void	rotate_b(t_stack *stacks);
void	rotate_ab(t_stack *stacks);
void	reverse_rot_a(t_stack *stacks);
void	reverse_rot_b(t_stack *stacks);
void	reverse_rot_ab(t_stack *stacks);

#endif
