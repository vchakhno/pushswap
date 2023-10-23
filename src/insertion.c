/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/23 10:04:56 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	insertion_index(t_array array, t_i32 value)
{
	t_u32	i;

	i = 0;
	while (i < array.size)
	{
		if (value < ((t_i32 *)array.elems)[i])
			return (i);
	}
	return (0);
}

void	insert_phase1()
{
	t_u32	i;

	i = 0;
	while (i < nums.size)
	{
		if (!((bool *)data.mask.elems)[i])
		{
			push_b();
		}
		i++;
	}
}

void	insert_phase2()
{
	
}
