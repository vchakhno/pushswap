/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:49:29 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:47:47 by vchakhno         ###   ########.fr       */
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
}

void	realign_a(t_solver *solver)
{
	t_u32	i;

	i = 0;
	if (solver->a.offset < solver->a.size / 2)
	{
		while (solver->a.offset)
		{
			rstack_ra(&solver->a);
			i++;
		}
	}
	else
	{
		while (solver->a.offset)
		{
			rstack_rra(&solver->a);
			i++;
		}
	}
}

void	solver_push_a(t_solver *solver)
{
	t_insertion		best;

	while (solver->b.size)
	{
		best = best_stack_insertion(solver->a, solver->b);
		do_transfer(&solver->a, &solver->b, best);
		rstack_pa(&solver->a, &solver->b);
	}
	realign_a(solver);
}
