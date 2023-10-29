/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 17:26:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rstack_alloc(t_rstack *stack, t_u32 size)
{
	if (!ft_vector_alloc(&stack->vec, sizeof(t_u32), size))
		return (false);
	stack->offset = 0;
	return (true);
}

void	rstack_rotate(t_rstack *stack)
{
	t_u32	tmp;

	ft_vector_pop(&stack->vec, &tmp);
	ft_vector_insert(&stack->vec, 0, &tmp);
}

void	rstack_rrotate(t_rstack *stack)
{
	t_u32	tmp;

	ft_vector_remove(&stack->vec, 0, &tmp);
	ft_vector_push(&stack->vec, &tmp);
}

void	rstack_push(t_rstack *src, t_rstack *dst)
{
	t_u32	tmp;

	ft_vector_pop(&src->vec, &tmp);
	ft_vector_push(&dst->vec, &tmp);
}

void	rstack_free(t_rstack stack)
{
	ft_vector_free(stack.vec);
}
