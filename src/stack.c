/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 06:46:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

bool	rstack_alloc(t_rstack *stack, t_u32 capacity)
{
	if (!ft_mem_malloc(&stack->elems, capacity * sizeof(t_u32)))
		return (false);
	stack->size = 0;
	stack->capacity = capacity;
	stack->top = 0;
	stack->offset = 0;
	return (true);
}

void	rstack_rotate(t_rstack *stack)
{
	stack->elems[(stack->top + stack->size) % stack->capacity]
		= stack->elems[stack->top];
	stack->top = (stack->top + 1) % stack->capacity;
	stack->offset = (stack->offset + stack->size - 1) % stack->size;
}

void	rstack_rrotate(t_rstack *stack)
{
	stack->top = (stack->top + stack->capacity - 1) % stack->capacity;
	stack->elems[stack->top]
		= stack->elems[(stack->top + stack->size) % stack->capacity];
	stack->offset = (stack->offset + 1) % stack->size;
}

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

t_u32	rstack_get_cyclic(t_rstack stack, t_i32 i)
{
	return (
		stack.elems[
			(stack.top + (stack.offset + i) % stack.size) % stack.capacity
		]
	);
}

void	rstack_free(t_rstack stack)
{
	free(stack.elems);
}
