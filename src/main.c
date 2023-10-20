/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/20 07:55:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

bool	print_i32_elem(t_i32 *elem, t_output *output)
{
	return (ft_i32_oprint(*elem, output));
}

bool	print_bool_elem(bool *elem, t_output *output)
{
	if (*elem)
		return (ft_str_oprint(ft_str("1"), output));
	else
		return (ft_str_oprint(ft_str("_"), output));
}

void	display(t_vector nums, t_lis_data data)
{
	ft_printf("Array: ");
	ft_array_println(nums.array, print_i32_elem, NULL);
	ft_printf("Scores: ");
	ft_array_println(data.scores.array, print_i32_elem, NULL);
	ft_printf("Mask: ");
	ft_array_println(data.mask.array, print_bool_elem, NULL);
}

int	main(int argc, char **argv)
{
	t_vector		nums;
	t_lis_data		data;

	if (!parse_nums(argc - 1, argv + 1, &nums))
		return (1);
	if (!lis_alloc(&data, nums.size))
	{
		ft_vector_free(nums);
		return (1);
	}
	lis_compute(data, nums.array);
	display(nums, data);
	lis_free(data);
	ft_vector_free(nums);
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
