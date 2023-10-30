/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:42:06 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	insert_index(t_rstack stack, t_u32 value)
{
	t_u32	i;

	if (stack.size == 0)
		return (0);
	i = 0;
	while (i < stack.size && rstack_get_cyclic(stack, i) < value)
		i++;
	return ((stack.offset + i) % stack.size);
}

t_insertion	best_elem_insertion(
	t_u32 a_size, t_u32 a_index, t_u32 b_size, t_u32 b_index
) {
	t_insertion	best;
	t_u32		new_cost;

	best = (t_insertion){INSERT_RR,
		a_index, b_index, ft_u32_max(a_index, b_index)};
	new_cost = a_size - a_index + b_index;
	if (new_cost < best.cost)
		best = (t_insertion){INSERT_RRA_RB,
			a_size - a_index, b_index, new_cost};
	new_cost = b_size - b_index + a_index;
	if (new_cost < best.cost)
		best = (t_insertion){INSERT_RA_RRB,
			a_index, b_size - b_index, new_cost};
	new_cost = ft_u32_max(a_size - a_index, b_size - b_index);
	if (new_cost < best.cost)
		best = (t_insertion){INSERT_RRR,
			a_size - a_index, b_size - b_index, new_cost};
	return (best);
}

t_insertion	best_stack_insertion(t_rstack dst, t_rstack src)
{
	t_insertion	best;
	t_insertion	new;
	t_u32		i;

	best = best_elem_insertion(dst.size,
			insert_index(dst, src.elems[src.top]), src.size, 0);
	i = 1;
	while (i < src.size)
	{
		new = best_elem_insertion(dst.size,
				insert_index(dst, rstack_get(src, i)), src.size, i);
		if (new.cost < best.cost)
			best = new;
		i++;
	}
	return (best);
}
