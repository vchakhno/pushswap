/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:23:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/20 07:07:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <libft/libft.h>

typedef struct s_lis_data
{
	t_vector	scores;
	t_vector	mask;
}	t_lis_data;

bool	parse_nums(t_u32 size, char **strs, t_vector *nums);

bool	lis_alloc(t_lis_data *data, t_u32 size);
void	lis_compute(t_lis_data data, t_array nums);
void	lis_free(t_lis_data data);

#endif