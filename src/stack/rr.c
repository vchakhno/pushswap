/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 15:55:11 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rstack_rrotate(t_rstack *stack)
{
	stack->top = (stack->top + stack->capacity - 1) % stack->capacity;
	stack->elems[stack->top]
		= stack->elems[(stack->top + stack->size) % stack->capacity];
	stack->offset = (stack->offset + 1) % stack->size;
}

void	rstack_rra(t_rstack *a)
{
	rstack_rrotate(a);
	ft_println("rra");
}

void	rstack_rrb(t_rstack *b)
{
	rstack_rrotate(b);
	ft_println("rrb");
}

void	rstack_rrr(t_rstack *a, t_rstack *b)
{
	rstack_rrotate(a);
	rstack_rrotate(b);
	ft_println("rrr");
}
