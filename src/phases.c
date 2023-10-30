/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:49:29 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 11:01:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver_push_b(t_solver *solver, t_array nums)
{
	t_insertion	transfer;
	t_u32		i;

	lis_compute(solver->lis, nums);
	i = 0;
	while (cheapest_chunk_transfer(solver, &transfer))
	{
		do_insertion(&solver->a, &solver->b, transfer);
		rstack_push(&solver->b, rstack_pop(&solver->a));
		ft_println("pb");
		i++;
	}
	// while (i < nums.size)
	// {
	// 	if (solver->lis.seq_mask[solver->a.elems[solver->a.top]])
	// 	{
	// 		rstack_rotate(&solver->a);
	// 		ft_println("ra");
	// 	}
	// 	else
	// 	{
	// 		rstack_push(&solver->b, rstack_pop(&solver->a));
	// 		ft_println("pb");
	// 	}
	// 	i++;
	// }
	solver_print(*solver);
}

void	solver_push_a(t_solver *solver)
{
	t_insertion		best;
	t_u32			i;

	while (solver->b.size)
	{
		best = best_stack_insertion(solver->a, solver->b);
		do_insertion(&solver->a, &solver->b, best);
		rstack_push(&solver->a, rstack_pop(&solver->b));
		ft_println("pa");
	}
	solver_print(*solver);
	i = 0;
	if (solver->a.offset < solver->a.size / 2)
	{
		while (solver->a.offset)
		{
			ft_println("ra");
			rstack_rotate(&solver->a);
			i++;
		}
	}
	else
	{
		while (solver->a.offset)
		{
			ft_println("rra");
			rstack_rrotate(&solver->a);
			i++;
		}
	}
	solver_print(*solver);
}
