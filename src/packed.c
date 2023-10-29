/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:45:16 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 11:36:13 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	packed_pos(t_vector nums, t_i32 elem)
{
	t_u32	pos;
	t_u32	i;

	pos = 0;
	i = 0;
	while (i < nums.size)
	{
		if (elem > ((t_i32 *)nums.elems)[i])
			pos++;
		i++;
	}
	return (pos);
}

bool	parse_nums_packed(t_u32 size, char **strs, t_vector *packed)
{
	t_vector	nums;
	t_u32		pos;
	t_u32		i;

	if (!parse_nums(size, strs, &nums))
		return (false);
	if (!ft_vector_alloc(packed, sizeof(t_u32), nums.size))
	{
		ft_vector_free(nums);
		ft_oprintln(ft_stderr(), "Internal error: Not enough memory");
		return (false);
	}
	i = 0;
	while (i < nums.size)
	{
		pos = packed_pos(nums, ((t_i32 *)nums.elems)[i]);
		ft_vector_push(packed, &pos);
		i++;
	}
	ft_vector_free(nums);
	return (true);
}
