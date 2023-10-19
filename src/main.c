/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/19 07:49:36 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

bool	print_i32_elem(t_i32 *elem, t_output *output)
{
	return (ft_i32_oprint(*elem, output));
}

bool	compare_i32_elem(t_i32 *left, t_i32 *right)
{
	return (*left > *right);
}

int	main(int argc, char **argv)
{
	t_vector	nums;

	if (!parse_nums(argc - 1, argv + 1, &nums))
	{
		ft_oprintln(ft_stderr(), "Wrong args");
		return (1);
	}
	ft_printf("Before: ");
	ft_array_println(nums.array, print_i32_elem, NULL);
	ft_array_sort(nums.array, compare_i32_elem);
	ft_printf("After: ");
	ft_array_println(nums.array, print_i32_elem, NULL);
	ft_vector_free(nums);
}

// LIS
// Insert chunks A->B
// Insert sorted A<-B

// Multi-level opt insert

// Chunk insert index
//  Sort whole list
//  Check 
