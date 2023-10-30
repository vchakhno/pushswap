/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:50:32 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:13:29 by vchakhno         ###   ########.fr       */
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

void	solver_run(t_solver solver, t_array nums)
{
	if (array_is_sorted(nums))
		return ;
	solver_init_stacks(&solver, nums);
	if (nums.size <= 5)
		small_sort(&solver.a, &solver.b);
	else
	{
		solver_push_b(&solver, nums);
		solver_push_a(&solver);
	}
}

void	solver_free(t_solver solver)
{
	rstack_free(solver.b);
	rstack_free(solver.a);
	lis_free(solver.lis);
}
