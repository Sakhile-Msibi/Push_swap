/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 06:49:59 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/06 06:56:38 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_colour(int m)
{
	if (m == 1)
		return ("\e\033[0;36m");
	else if (m == 2)
		return ("\e\033[0;36m");
	else if (m == 3)
		return ("\e\033[0;34m");
	else if (m == 4)
		return ("\e\033[0;34m");
	else if (m == 5)
		return ("\e\033[0;32m");
	else if (m == 7)
		return ("\e\033[0;32m");
	else if (m == 8)
		return ("\e\033[0;32m");
	else if (m == 9)
		return ("\e\033[0;31m");
	else if (m == 10)
		return ("\e\033[0;31m");
	return ("");
}
