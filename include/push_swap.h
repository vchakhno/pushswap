/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:23:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 11:28:28 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <libft/libft.h>

bool	parse_nums(t_u32 size, char **strs, t_vector *nums);
bool	parse_nums_packed(t_u32 size, char **strs, t_vector *packed);
bool	nums_to_pos(t_vector nums, t_vector *pos);

typedef struct s_lis
{
	t_u32	*scores;
	bool	*seq_mask;
}	t_lis;

bool	lis_alloc(t_lis *lis, t_u32 size);
void	lis_compute(t_lis lis, t_array nums);
void	lis_free(t_lis lis);

#endif