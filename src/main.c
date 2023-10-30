/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:07:45 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:55:16 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

int	main(int argc, char **argv)
{
	t_vector	packed;
	t_solver	solver;

	if (!parse_nums_packed(argc - 1, argv + 1, &packed))
	{
		ft_oprintln(ft_stderr(), "Error");
		return (1);
	}
	if (!solver_alloc(&solver, packed.size))
	{
		ft_oprintln(ft_stderr(), "Error");
		ft_vector_free(packed);
		return (1);
	}
	solver_run(solver, packed.array);
	solver_free(solver);
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
