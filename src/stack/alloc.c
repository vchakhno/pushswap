/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 15:53:35 by vchakhno         ###   ########.fr       */
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

void	rstack_free(t_rstack stack)
{
	free(stack.elems);
}
