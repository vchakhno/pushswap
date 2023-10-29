/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 11:38:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

bool	print_u32_elem(t_u32 *elem, t_output *output)
{
	return (ft_u32_oprint(*elem, output));
}

void	print_mask(bool *mask, t_u32 size)
{
	t_u32	i;

	ft_printf("Mask: [");
	i = 0;
	while (i < size)
	{
		if (mask[i])
			ft_printf("1");
		else
			ft_printf("_");
		if (i != size - 1)
			ft_printf(", ");
		i++;
	}
	ft_println("]");
}

void	display(t_vector packed, t_lis lis)
{
	ft_printf("Packed: ");
	ft_array_println(packed.array, print_u32_elem, NULL);
	lis_compute(lis, packed.array);
	ft_printf("Scores: ");
	ft_array_println((t_array){lis.scores, packed.size, sizeof(t_u32)},
		print_u32_elem, NULL);
	print_mask(lis.seq_mask, packed.size);
}

int	main(int argc, char **argv)
{
	t_vector	packed;
	t_lis		lis;

	if (!parse_nums_packed(argc - 1, argv + 1, &packed))
		return (1);
	if (!lis_alloc(&lis, packed.size))
	{
		ft_oprintln(ft_stderr(), "Internal error: Not enough memory");
		ft_vector_free(packed);
		return (1);
	}
	display(packed, lis);
	lis_free(lis);
	ft_vector_free(packed);
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
