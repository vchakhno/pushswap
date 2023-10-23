/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:56:12 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/23 15:30:08 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_score(t_u32 pos, t_i32 *nums, t_u32 *scores)
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

void	compute_scores(t_array scores, t_u32 *score_peak, t_array pos)
{
	t_u32	i;

	*score_peak = 0;
	i = 0;
	while (i < pos.size)
	{
		pos_score(i, pos.elems, scores.elems);
		if (((t_u32 *)scores.elems)[i] >= ((t_u32 *)scores.elems)[*score_peak])
			*score_peak = i;
		i++;
	}
}

void	compute_mask(
	t_array mask, t_array scores, t_u32 score_peak, t_array pos
) {
	t_u32	i;
	t_u32	seq_first;

	seq_first = score_peak;
	i = score_peak;
	while (i > 0)
	{
		i--;
		if (((t_u32 *)scores.elems)[i] == ((t_u32 *)scores.elems)[seq_first] - 1
			&& ((t_u32 *)pos.elems)[i] < ((t_u32 *)pos.elems)[seq_first])
		{
			((bool *)mask.elems)[i] = true;
			seq_first = i;
		}
		else
			((bool *)mask.elems)[i] = false;
	}
}

bool	create_mask(t_vector *mask, t_array pos)
{
	t_vector	scores;
	t_u32		score_peak;

	if (!ft_vector_alloc(&scores, sizeof(t_u32), pos.size))
		return (false);
	if (!ft_vector_alloc(mask, sizeof(bool), pos.size))
	{
		ft_vector_free(scores);
		return (false);
	}
	scores.size = pos.size;
	mask->size = pos.size;
	compute_scores(scores.array, &score_peak, pos);
	compute_mask(mask->array, scores.array, score_peak, pos);
	return (true);
}
