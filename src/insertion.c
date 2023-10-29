/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 23:45:36 by vchakhno         ###   ########.fr       */
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
