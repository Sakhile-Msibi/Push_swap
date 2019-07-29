/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:08:33 by smsibi            #+#    #+#             */
/*   Updated: 2019/07/29 09:30:13 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

void	push_a(t_stack *a, t_stack *b, int status);
void	push_b(t_stack *a, t_stack *b, int status);
void	swap_a(t_stack *a, t_stack *b, int status);
void	swap_b(t_stack *a, t_stack *b, int status);
void	swap_ab(t_stack *a, t_stack *b, int status);
void	rotate_a(t_stack *a, t_stack *b, int status);
void	rotate_b(t_stack *a, t_stack *b, int status);
void	rotate_ab(t_stack *a, t_stack *b, int status);
void	reverse_rot_a(t_stack *a, t_stack *b, int status);
void	reverse_rot_b(t_stack *a, t_stack *b, int status);
void	reverse_rot_ab(t_stack *a, t_stack *b, int status);

#endif
