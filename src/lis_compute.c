/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:00:54 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 11:09:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	lis_pos_score(t_u32 *scores, t_u32 *nums, t_u32 pos)
{
	t_u32	max;
	t_u32	i;

	i = pos;
	max = 1;
	while (i > 0)
	{
		i--;
		if (nums[i] < nums[pos] && scores[i] + 1 > max)
			max = scores[i] + 1;
	}
	return (max);
}

t_u32	lis_compute_scores(t_u32 *scores, t_array nums)
{
	t_u32	seq_last;
	t_u32	i;

	seq_last = 0;
	i = 0;
	while (i < nums.size)
	{
		scores[i] = lis_pos_score(scores, nums.elems, i);
		if (scores[i] >= scores[seq_last])
			seq_last = i;
		i++;
	}
	return (seq_last);
}

void	lis_compute_mask(t_lis lis, t_array nums, t_u32 seq_last)
{
	t_u32	seq_first;
	t_u32	i;

	i = 0;
	while (i < nums.size)
	{
		lis.seq_mask[i] = false;
		i++;
	}
	seq_first = seq_last;
	i = seq_last;
	lis.seq_mask[i] = true;
	while (i > 0)
	{
		i--;
		if (lis.scores[i] == lis.scores[seq_first] - 1
			&& ((t_u32 *)nums.elems)[i] < ((t_u32 *)nums.elems)[seq_first])
		{
			lis.seq_mask[i] = true;
			seq_first = i;
		}
	}
}

void	lis_compute(t_lis lis, t_array nums)
{
	t_u32	seq_last;

	seq_last = lis_compute_scores(lis.scores, nums);
	lis_compute_mask(lis, nums, seq_last);
}
