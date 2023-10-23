/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:45:16 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/23 12:02:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	elem_pos(t_vector nums, t_i32 elem)
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

// /!\ Consumes nums
bool	nums_to_pos(t_vector nums, t_vector *pos)
{
	t_u32	i;

	if (!ft_vector_alloc(pos, sizeof(t_u32), nums.size))
	{
		ft_vector_free(nums);
		return (false);
	}
	i = 0;
	while (i < nums.size)
	{
		ft_vector_push(pos, &(t_u32){
			elem_pos(nums, ((t_i32 *)nums.elems)[i])});
		i++;
	}
	ft_vector_free(nums);
	return (true);
}
