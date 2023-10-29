/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:06:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 17:26:43 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	print_u32_elem(t_u32 *elem, t_output *output)
{
	return (ft_u32_oprint(*elem, output));
}

void	solver_print(t_solver solver)
{
	ft_oprintf(ft_stderr(), "Stack A (offset: {u32}): ", solver.a.offset);
	ft_array_oprintln(solver.a.vec.array, ft_stderr(), print_u32_elem, NULL);
	ft_oprintf(ft_stderr(), "Stack B (offset: {u32}): ", solver.b.offset);
	ft_array_oprintln(solver.b.vec.array, ft_stderr(), print_u32_elem, NULL);
}
