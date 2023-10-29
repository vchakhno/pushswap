/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:06:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 23:23:03 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rstack_print(t_rstack stack, char *name)
{
	t_u32	i;

	ft_oprintf(ft_stderr(), "Stack {c_str} (offset: {u32}) [",
		name, stack.offset);
	i = 0;
	while (i < stack.size)
	{
		ft_u32_oprint(stack.elems[(stack.top + i) % stack.capacity],
			ft_stderr());
		if (i != stack.size - 1)
			ft_oprintf(ft_stderr(), ", ");
		i++;
	}
	ft_oprintln(ft_stderr(), "]");
}

void	solver_print(t_solver solver)
{
	rstack_print(solver.a, "A");
	rstack_print(solver.b, "B");
}
