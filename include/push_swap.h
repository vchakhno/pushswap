/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:23:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/29 17:25:32 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <libft/libft.h>

bool	parse_nums(t_u32 size, char **strs, t_vector *nums);
bool	parse_nums_packed(t_u32 size, char **strs, t_vector *packed);
bool	nums_to_pos(t_vector nums, t_vector *pos);

typedef struct s_lis
{
	t_u32	*scores;
	bool	*seq_mask;
}	t_lis;

bool	lis_alloc(t_lis *lis, t_u32 size);
void	lis_compute(t_lis lis, t_array nums);
void	lis_free(t_lis lis);

typedef struct s_rstack
{
	t_vector	vec;
	t_u32		offset;
}	t_rstack;

typedef struct s_solver
{
	t_lis		lis;
	t_rstack	a;
	t_rstack	b;
}	t_solver;

bool	solver_alloc(t_solver *solver, t_u32 size);
void	solver_run(t_solver solver, t_array nums);
void	solver_free(t_solver solver);

void	solver_print(t_solver solver);

bool	rstack_alloc(t_rstack *stack, t_u32 size);
void	rstack_free(t_rstack stack);

void	rstack_rotate(t_rstack *stack);
void	rstack_rrotate(t_rstack *stack);
void	rstack_push(t_rstack *src, t_rstack *dst);

void	stack_insert(t_rstack *stack, t_u32 value);

#endif