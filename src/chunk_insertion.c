/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_insertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 06:43:59 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 11:03:01 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	same_chunk(t_u32 chunk_size, t_u32 a, t_u32 b)
{
	return (a / chunk_size == b / chunk_size);
}

t_chunk_entry	find_chunk_entry(t_rstack stack, t_u32 value)
{
	t_chunk_entry	entry;
	t_u32			i;

	if (stack.size == 0 || same_chunk(128, stack.elems[stack.top], value))
		return ((t_chunk_entry){0, 0});
	i = 0;
	while (i < stack.size
		&& !same_chunk(128, rstack_get_cyclic(stack, i), value))
		i++;
	entry.high = i;
	while (i < stack.size
		&& same_chunk(128, rstack_get_cyclic(stack, i), value))
		i++;
	entry.low = i;
	return (entry);
}

t_insertion	optimal_chunk_transfer(
	t_u32 a_size, t_u32 a_index, t_u32 b_size, t_chunk_entry b_entry
) {
	t_insertion	best;
	t_u32		new_cost;

	best = (t_insertion){INSERT_RR,
		a_index, b_entry.high, ft_u32_max(a_index, b_entry.high)};
	new_cost = a_size - a_index + b_entry.high;
	if (new_cost < best.cost)
		best = (t_insertion){INSERT_RRA_RB,
			a_size - a_index, b_entry.high, new_cost};
	new_cost = b_size - b_entry.low + a_index;
	if (new_cost < best.cost)
		best = (t_insertion){INSERT_RA_RRB,
			a_index, b_size - b_entry.low, new_cost};
	new_cost = ft_u32_max(a_size - a_index, b_size - b_entry.low);
	if (new_cost < best.cost)
		best = (t_insertion){INSERT_RRR,
			a_size - a_index, b_size - b_entry.low, new_cost};
	return (best);
}

bool	in_lis(t_rstack a, t_lis lis, t_u32 i)
{
	return (lis.seq_mask[a.elems[(a.top + i) % a.capacity]]);
}

bool	cheapest_chunk_transfer(t_solver *solver, t_insertion *cheapest)
{
	t_insertion		new;
	t_u32			i;

	i = 0;
	while (i < solver->a.size && in_lis(solver->a, solver->lis, i))
		i++;
	if (i == solver->a.size)
		return (false);
	*cheapest = optimal_chunk_transfer(solver->a.size, i, solver->b.size,
			find_chunk_entry(solver->b, solver->a.elems[solver->a.top]));
	ft_oprintln(ft_stderr(), "I: {u32}, A rot: {u32}", i, cheapest->a_rot);
	i++;
	while (i < solver->a.size)
	{
		if (!in_lis(solver->a, solver->lis, i))
		{
			new = optimal_chunk_transfer(
					solver->a.size, i, solver->b.size,
					find_chunk_entry(solver->b,
						solver->a.elems[solver->a.top]));
			ft_oprintln(ft_stderr(), "I: {u32}, A rot: {u32}", i, new.a_rot);
			if (new.cost < cheapest->cost)
				*cheapest = new;
		}
		i++;
	}
	return (true);
}
