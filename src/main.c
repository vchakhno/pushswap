/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/23 15:29:34 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

bool	print_u32_elem(t_u32 *elem, t_output *output)
{
	return (ft_u32_oprint(*elem, output));
}

bool	print_bool_elem(bool *elem, t_output *output)
{
	if (*elem)
		return (ft_str_oprint(ft_str("1"), output));
	else
		return (ft_str_oprint(ft_str("_"), output));
}

// void	display(t_vector nums, t_lis_data data)
// {
// 	ft_printf("Array: ");
// 	ft_array_println(nums.array, print_i32_elem, NULL);
// 	ft_printf("Scores: ");
// 	ft_array_println(data.scores.array, print_i32_elem, NULL);
// 	ft_printf("Mask: ");
// 	ft_array_println(data.mask.array, print_bool_elem, NULL);
// }

int	main(int argc, char **argv)
{
	t_vector	nums;
	t_vector	pos;
	t_vector	mask;

	if (!parse_nums(argc - 1, argv + 1, &nums))
		return (1);
	if (!nums_to_pos(nums, &pos))
		return (1);
	if (!create_mask(&mask, pos.array))
		return (1);
	ft_printf("Positions: ");
	ft_array_println(pos.array, print_u32_elem, NULL);
	ft_printf("Mask: ");
	ft_array_println(mask.array, print_bool_elem, NULL);
	ft_vector_free(mask);
	ft_vector_free(pos);
}

// LIS
// Return vector of bools
// Make every false go to B
// 
// Insert chunks A->B
// Insert sorted A<-B

// Multi-level opt insert

// Chunk insert index
//  Sort whole list
//  Check 
