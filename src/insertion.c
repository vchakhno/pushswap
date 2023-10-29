/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 17:41:24 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u32	insert_index(t_rstack stack, t_u32 value)
{
	t_u32	i;

	i = 0;
	while (i < stack.vec.size && ((t_u32 *)stack.vec.elems)[
		stack.vec.size - 1 - (i + stack.offset) % stack.vec.size
	] < value)
		i++;
	return ((i + stack.offset) % stack.vec.size);
}

void	stack_insert(t_rstack *stack, t_u32 value)
{
	t_u32	dest;
	t_u32	i;

	dest = insert_index(*stack, value);
	i = 0;
	if (dest < stack->vec.size / 2)
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
		while (i < stack->vec.size - dest)
		{
			ft_println("rra");
			rstack_rrotate(stack);
			i++;
		}
	}
	stack->offset = (stack->offset + stack->vec.size - dest) % stack->vec.size;
	if (value > ((t_u32 *)stack->vec.elems)[stack->vec.size - 1 - stack->offset])
		stack->offset++;
	ft_println("pa");
	ft_vector_push(&stack->vec, &value);
}

// Find the insertion index:
// Ugly function
// Save offset
