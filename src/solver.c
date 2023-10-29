/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:50:32 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 17:43:46 by vchakhno         ###   ########.fr       */
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
	t_u32	i;

	solver->a.vec.size = nums.size;
	solver->a.offset = 0;
	solver->b.vec.size = 0;
	solver->b.offset = 0;
	i = 0;
	while (i < nums.size)
	{
		(*(t_u32 **)&solver->a)[i] = \
			((t_u32 *)nums.elems)[nums.size - 1 - i];
		i++;
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
			ft_println("ra");
			rstack_rotate(&solver->a);
		}
		else
		{
			ft_println("pb");
			rstack_push(&solver->a, &solver->b);
		}
		i++;
	}
	solver_print(*solver);
}

void	solver_push_a(t_solver *solver)
{
	t_u32	tmp;
	t_u32	i;

	while (solver->b.vec.size)
	{
		ft_vector_pop(&solver->b.vec, &tmp);
		stack_insert(&solver->a, tmp);
	}
	solver_print(*solver);
	i = 0;
	if (solver->a.offset < solver->a.vec.size / 2)
	{
		while (i < solver->a.offset)
		{
			ft_println("ra");
			rstack_rotate(&solver->a);
			i++;
		}
	}
	else
	{
		while (i < solver->a.vec.size - solver->a.offset)
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
