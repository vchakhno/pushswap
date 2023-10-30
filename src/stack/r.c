/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 15:55:20 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rstack_rotate(t_rstack *stack)
{
	stack->elems[(stack->top + stack->size) % stack->capacity]
		= stack->elems[stack->top];
	stack->top = (stack->top + 1) % stack->capacity;
	stack->offset = (stack->offset + stack->size - 1) % stack->size;
}

void	rstack_ra(t_rstack *a)
{
	rstack_rotate(a);
	ft_println("ra");
}

void	rstack_rb(t_rstack *b)
{
	rstack_rotate(b);
	ft_println("rb");
}

void	rstack_rr(t_rstack *a, t_rstack *b)
{
	rstack_rotate(a);
	rstack_rotate(b);
	ft_println("rr");
}
