/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:00:54 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 10:43:35 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

bool	lis_alloc(t_lis *lis, t_u32 size)
{
	if (!ft_mem_malloc(&lis->scores, size * sizeof(t_u32)))
		return (false);
	if (!ft_mem_malloc(&lis->seq_mask, size * sizeof(bool)))
	{
		free(lis->scores);
		return (false);
	}
	return (true);
}

void	lis_free(t_lis lis)
{
	free(lis.seq_mask);
	free(lis.scores);
}
