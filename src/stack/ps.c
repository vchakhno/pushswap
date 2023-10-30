/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:44 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 11:57:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rstack_pa(t_rstack *a, t_rstack *b)
{
	rstack_push(a, rstack_pop(b));
	ft_println("pa");
}

void	rstack_pb(t_rstack *a, t_rstack *b)
{
	rstack_push(b, rstack_pop(a));
	ft_println("pb");
}

void	rstack_sa(t_rstack *a)
{
	t_u32	tmp;

	tmp = a->elems[a->top];
	a->elems[a->top] = a->elems[(a->top + 1) % a->capacity];
	a->elems[(a->top + 1) % a->capacity] = tmp;
	ft_println("sa");
}

void	rstack_sb(t_rstack *b)
{
	t_u32	tmp;

	tmp = b->elems[b->top];
	b->elems[b->top] = b->elems[(b->top + 1) % b->capacity];
	b->elems[(b->top + 1) % b->capacity] = tmp;
	ft_println("sb");
}
