/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 15:56:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rstack_push(t_rstack *stack, t_u32 value)
{
	if (stack->size && (stack->offset != 0 || value > stack->elems[stack->top]))
		stack->offset++;
	stack->top = (stack->top + stack->capacity - 1) % stack->capacity;
	stack->elems[stack->top] = value;
	stack->size++;
}

t_u32	rstack_pop(t_rstack *stack)
{
	t_u32	tmp;

	if (stack->offset != 0)
		stack->offset--;
	tmp = stack->elems[stack->top];
	stack->top = (stack->top + 1) % stack->capacity;
	stack->size--;
	return (tmp);
}

t_u32	rstack_get(t_rstack stack, t_i32 i)
{
	return (stack.elems[(stack.top + i) % stack.capacity]);
}

t_u32	rstack_get_cyclic(t_rstack stack, t_i32 i)
{
	return (rstack_get(stack, (stack.offset + i) % stack.size));
}
