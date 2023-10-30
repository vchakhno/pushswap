/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:42:09 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 16:44:59 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_transfer_rr(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;
	t_u32	rr;

	rr = ft_u32_min(insert.a_rot, insert.b_rot);
	i = 0;
	while (i < rr)
	{
		rstack_rr(dst, src);
		i++;
	}
	i = 0;
	while (i < insert.a_rot - rr)
	{
		rstack_ra(dst);
		i++;
	}
	i = 0;
	while (i < insert.b_rot - rr)
	{
		rstack_rb(src);
		i++;
	}
}

void	do_transfer_rrr(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;
	t_u32	rrr;

	rrr = ft_u32_min(insert.a_rot, insert.b_rot);
	i = 0;
	while (i < rrr)
	{
		rstack_rrr(dst, src);
		i++;
	}
	i = 0;
	while (i < insert.a_rot - rrr)
	{
		rstack_rra(dst);
		i++;
	}
	i = 0;
	while (i < insert.b_rot - rrr)
	{
		rstack_rrb(src);
		i++;
	}
}

void	do_transfer_ra_rrb(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;

	i = 0;
	while (i < insert.a_rot)
	{
		rstack_ra(dst);
		i++;
	}
	i = 0;
	while (i < insert.b_rot)
	{
		rstack_rrb(src);
		i++;
	}
}

void	do_transfer_rra_rb(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	t_u32	i;

	i = 0;
	while (i < insert.a_rot)
	{
		rstack_rra(dst);
		i++;
	}
	i = 0;
	while (i < insert.b_rot)
	{
		rstack_rb(src);
		i++;
	}
}

void	do_transfer(t_rstack *dst, t_rstack *src, t_insertion insert)
{
	if (insert.type == INSERT_RR)
		do_transfer_rr(dst, src, insert);
	else if (insert.type == INSERT_RRR)
		do_transfer_rrr(dst, src, insert);
	else if (insert.type == INSERT_RA_RRB)
		do_transfer_ra_rrb(dst, src, insert);
	else if (insert.type == INSERT_RRA_RB)
		do_transfer_rra_rb(dst, src, insert);
}
