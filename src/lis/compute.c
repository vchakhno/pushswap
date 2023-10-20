/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:47:04 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/20 07:35:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_elem_score(t_u32 pos, t_i32 *nums, t_u32 *scores)
{
	t_u32	i;

	i = pos;
	while (i > 0)
	{
		i--;
		if (nums[i] < nums[pos]
			&& scores[i] + 1 > scores[pos])
			scores[pos] = scores[i] + 1;
	}
}

// No optimizations yet
t_u32	lis_scores(t_array scores, t_array nums)
{
	t_i32 *const	_nums = nums.elems;
	t_u32 *const	_scores = scores.elems;
	t_u32			i;
	t_u32			last_index;

	last_index = 0;
	i = 0;
	while (i < nums.size)
	{
		lis_elem_score(i, _nums, _scores);
		if (_scores[i] > _scores[last_index])
			last_index = i;
		i++;
	}
	return (last_index);
}

void	lis_mask(t_lis_data data, t_array nums, t_u32 last_index)
{
	t_i32 *const	_nums = nums.elems;
	t_u32 *const	_scores = data.scores.elems;
	bool *const		_mask = data.mask.elems;
	t_u32			first_index;
	t_u32			i;

	first_index = last_index;
	_mask[last_index] = true;
	i = last_index;
	while (i > 0)
	{
		i--;
		if (_scores[i] == _scores[first_index] - 1
			&& _nums[i] < _nums[first_index])
		{
			_mask[i] = true;
			first_index = i;
		}
	}
}

void	lis_compute(t_lis_data data, t_array nums)
{
	t_u32	last_index;

	last_index = lis_scores(data.scores.array, nums);
	lis_mask(data, nums, last_index);
}
