/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:04:51 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:09:42 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	rstack_min(t_rstack stack)
{
	t_u32	min;
	t_u32	i;

	min = rstack_get(stack, 0);
	i = 1;
	while (i < stack.size)
	{
		if (rstack_get(stack, i) < min)
			min = rstack_get(stack, i);
		i++;
	}
	return (min);
}

t_u32	rstack_max(t_rstack stack)
{
	t_u32	max;
	t_u32	i;

	max = rstack_get(stack, 0);
	i = 1;
	while (i < stack.size)
	{
		if (rstack_get(stack, i) > max)
			max = rstack_get(stack, i);
		i++;
	}
	return (max);
}
