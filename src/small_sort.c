/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:59 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:44 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_rstack *a)
{
	if (rstack_get(*a, 0) > rstack_get(*a, 1))
		rstack_sa(a);
}

void	sort_three(t_rstack *a)
{
	t_u32	max;

	max = rstack_max(*a);
	if (rstack_get(*a, 0) == max)
		rstack_ra(a);
	else if (rstack_get(*a, 1) == max)
		rstack_rra(a);
	sort_two(a);
}

void	sort_four(t_rstack *a, t_rstack *b)
{
	t_u32	min;

	min = rstack_min(*a);
	if (rstack_get(*a, 2) == min)
		rstack_ra(a);
	if (rstack_get(*a, 1) == min)
		rstack_ra(a);
	else if (rstack_get(*a, 3) == min)
		rstack_rra(a);
	rstack_pb(a, b);
	sort_three(a);
	rstack_pa(a, b);
}

void	sort_five(t_rstack *a, t_rstack *b)
{
	t_u32	min;

	min = rstack_min(*a);
	if (rstack_get(*a, 2) == min)
		rstack_ra(a);
	if (rstack_get(*a, 1) == min)
		rstack_ra(a);
	else if (rstack_get(*a, 3) == min)
		rstack_rra(a);
	if (rstack_get(*a, 4) == min)
		rstack_rra(a);
	rstack_pb(a, b);
	sort_four(a, b);
	rstack_pa(a, b);
}

void	small_sort(t_rstack *a, t_rstack *b)
{
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	if (a->size == 4)
		sort_four(a, b);
	if (a->size == 5)
		sort_five(a, b);
}
