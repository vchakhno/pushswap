/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:49:29 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 11:16:21 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_halfs(t_solver *solver, t_u32 half)
{
	t_u32	tmp;

	tmp = rstack_pop(&solver->a);
	rstack_push(&solver->b, tmp);
	ft_println("pb");
	if (tmp > half)
	{
		rstack_rotate(&solver->b);
		ft_println("rb");
	}
}

void	solver_push_b(t_solver *solver, t_array nums)
{
	t_u32	i;

	lis_compute(solver->lis, nums);
	i = 0;
	while (i < nums.size)
	{
		if (solver->lis.seq_mask[i])
		{
			rstack_rotate(&solver->a);
			ft_println("ra");
		}
		else
		{
			push_b_halfs(solver, nums.size / 2);
		}
		i++;
	}
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
