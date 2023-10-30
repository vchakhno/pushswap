/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 05:01:55 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	rstack_get_cyclic(t_rstack stack, t_i32 i)
{
	return (
		stack.elems[
			(stack.top + (stack.offset + i) % stack.size) % stack.capacity
		]
	);
}

t_u32	insert_index(t_rstack stack, t_u32 value)
{
	t_u32	i;

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
				insert_index(dst, src.elems[(src.top + i) % src.capacity]), src.size, i);
		if (new.cost < best.cost)
			best = new;
		i++;
	}
	return (best);
}

void	do_insertion_rr(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;
	t_u32	rr;

	rr = ft_u32_min(insert.a_rot, insert.b_rot);
	i = 0;
	while (i < rr)
	{
		rstack_rotate(dst);
		rstack_rotate(src);
		ft_println("rr");
		i++;
	}
	i = 0;
	while (i < insert.a_rot - rr)
	{
		rstack_rotate(dst);
		ft_println("ra");
		i++;
	}
	i = 0;
	while (i < insert.b_rot - rr)
	{
		rstack_rotate(src);
		ft_println("rb");
		i++;
	}
}

void	do_insertion_rrr(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;
	t_u32	rrr;

	rrr = ft_u32_min(insert.a_rot, insert.b_rot);
	i = 0;
	while (i < rrr)
	{
		rstack_rrotate(dst);
		rstack_rrotate(src);
		ft_println("rrr");
		i++;
	}
	i = 0;
	while (i < insert.a_rot - rrr)
	{
		rstack_rrotate(dst);
		ft_println("rra");
		i++;
	}
	i = 0;
	while (i < insert.b_rot - rrr)
	{
		rstack_rrotate(src);
		ft_println("rrb");
		i++;
	}
}

void	do_insertion_ra_rrb(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;

	i = 0;
	while (i < insert.a_rot)
	{
		rstack_rotate(dst);
		ft_println("ra");
		i++;
	}
	i = 0;
	while (i < insert.b_rot)
	{
		rstack_rrotate(src);
		ft_println("rrb");
		i++;
	}
}

void	do_insertion_rra_rb(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;

	i = 0;
	while (i < insert.a_rot)
	{
		rstack_rrotate(dst);
		ft_println("rra");
		i++;
	}
	i = 0;
	while (i < insert.b_rot)
	{
		rstack_rotate(src);
		ft_println("rb");
		i++;
	}
}

void	do_insertion(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	if (insert.type == INSERT_RR)
		do_insertion_rr(dst, src, insert);
	else if (insert.type == INSERT_RRR)
		do_insertion_rrr(dst, src, insert);
	else if (insert.type == INSERT_RA_RRB)
		do_insertion_ra_rrb(dst, src, insert);
	else if (insert.type == INSERT_RRA_RB)
		do_insertion_rra_rb(dst, src, insert);
	rstack_push(dst, rstack_pop(src));
}

void	stack_insert(t_rstack *stack, t_u32 value)
{
	t_u32	dest;
	t_u32	i;

	dest = insert_index(*stack, value);
	i = 0;
	if (dest < stack->size / 2)
	{
		while (i < dest)
		{
			ft_println("ra");
			rstack_rotate(stack);
			i++;
		}
	}
	else
	{
		while (i < stack->size - dest)
		{
			ft_println("rra");
			rstack_rrotate(stack);
			i++;
		}
	}
	ft_println("pa");
	rstack_push(stack, value);
}

// Find the insertion index:
// Ugly function
// Save offset
