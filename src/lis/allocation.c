/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:25:08 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/20 07:55:24 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	lis_alloc(t_lis_data *data, t_u32 size)
{
	t_u32	i;

	if (!ft_vector_alloc(&data->scores, sizeof(t_i32), size))
		return (false);
	if (!ft_vector_alloc(&data->mask, sizeof(bool), size))
	{
		ft_vector_free(data->scores);
		return (false);
	}
	i = 0;
	while (i < size)
	{
		ft_vector_push(&data->scores, &(t_u32){1});
		ft_vector_push(&data->mask, &(bool){false});
		i++;
	}
	return (true);
}

void	lis_free(t_lis_data data)
{
	ft_vector_free(data.scores);
	ft_vector_free(data.mask);
}
