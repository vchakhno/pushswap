/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:34:26 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:05:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	array_is_sorted(t_array nums)
{
	t_u32	i;

	if (nums.size <= 1)
		return (true);
	i = 0;
	while (i < nums.size - 1)
	{
		if (((t_u32 *)nums.elems)[i] > ((t_u32 *)nums.elems)[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	array_has_dups(t_array nums, t_i32 *dup)
{
	t_u32	i;
	t_u32	j;

	i = 0;
	while (i < nums.size)
	{
		j = 0;
		while (j < i)
		{
			if (((t_i32 *)nums.elems)[j] == ((t_i32 *)nums.elems)[i])
			{
				*dup = ((t_i32 *)nums.elems)[j];
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
