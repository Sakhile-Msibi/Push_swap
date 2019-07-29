/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:20:55 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/29 14:29:17 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

void	swap_a(t_frame *stacks);
void	swap_b(t_frame *stacks);
void	swap_ab(t_frame *stacks);
void	push_b(t_frame *stacks);
void	push_a(t_frame *stacks);
void	rotate_a(t_frame *stacks);
void	rotate_b(t_frame *stacks);
void	rotate_ab(t_frame *stacks);
void	reverse_rot_a(t_frame *stacks);
void	reverse_rot_b(t_frame *stacks);
void	reverse_rot_ab(t_frame *stacks);

#endif
