/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:50:32 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 05:01:10 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	solver_alloc(t_solver *solver, t_u32 size)
{
	if (!lis_alloc(&solver->lis, size))
		return (false);
	if (!rstack_alloc(&solver->a, size))
	{
		lis_free(solver->lis);
		return (false);
	}
	if (!rstack_alloc(&solver->b, size))
	{
		rstack_free(solver->a);
		lis_free(solver->lis);
		return (false);
	}
	return (true);
}

void	solver_init_stacks(t_solver *solver, t_array nums)
{
	solver->a.size = nums.size;
	solver->a.top = 0;
	solver->a.offset = 0;
	ft_mem_copy(solver->a.elems, nums.elems, nums.size * sizeof(t_u32));
	solver->b.size = 0;
	solver->b.top = 0;
	solver->b.offset = 0;
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
			ft_println("ra");
			rstack_rotate(&solver->a);
		}
		else
		{
			ft_println("pb");
			rstack_push(&solver->b, rstack_pop(&solver->a));
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

void	solver_run(t_solver solver, t_array nums)
{
	solver_init_stacks(&solver, nums);
	solver_push_b(&solver, nums);
	solver_push_a(&solver);
}

void	solver_free(t_solver solver)
{
	rstack_free(solver.b);
	rstack_free(solver.a);
	lis_free(solver.lis);
}
