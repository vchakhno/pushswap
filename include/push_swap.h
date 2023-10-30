/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:23:40 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/30 10:51:23 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <libft/libft.h>

bool			parse_nums(t_u32 size, char **strs, t_vector *nums);
bool			parse_nums_packed(t_u32 size, char **strs, t_vector *packed);
bool			nums_to_pos(t_vector nums, t_vector *pos);

typedef struct s_lis
{
	t_u32	*scores;
	bool	*seq_mask;
	t_u32	size;
}	t_lis;

bool			lis_alloc(t_lis *lis, t_u32 size);
void			lis_compute(t_lis lis, t_array nums);
void			lis_free(t_lis lis);

typedef struct s_rstack
{
	t_u32		*elems;
	t_u32		size;
	t_u32		capacity;
	t_u32		top;
	t_u32		offset;
}	t_rstack;

typedef struct s_solver
{
	t_lis		lis;
	t_rstack	a;
	t_rstack	b;
}	t_solver;

bool			solver_alloc(t_solver *solver, t_u32 size);
void			solver_run(t_solver solver, t_array nums);
void			solver_free(t_solver solver);

void			solver_push_b(t_solver *solver, t_array nums);
void			solver_push_a(t_solver *solver);
void			solver_print(t_solver solver);

bool			rstack_alloc(t_rstack *stack, t_u32 capacity);
void			rstack_free(t_rstack stack);

t_u32			rstack_get_cyclic(t_rstack stack, t_i32 i);
void			rstack_rotate(t_rstack *stack);
void			rstack_rrotate(t_rstack *stack);
void			rstack_push(t_rstack *stack, t_u32 value);
t_u32			rstack_pop(t_rstack *stack);

void			stack_insert(t_rstack *stack, t_u32 value);

typedef enum e_insertion_type
{
	INSERT_RR,
	INSERT_RRR,
	INSERT_RA_RRB,
	INSERT_RRA_RB,
}	t_insertion_type;

typedef struct s_insertion
{
	t_insertion_type	type;
	t_u32				a_rot;
	t_u32				b_rot;
	t_u32				cost;
}	t_insertion;

t_insertion		best_stack_insertion(t_rstack dst, t_rstack src);
void			do_insertion(t_rstack *dst, t_rstack *src, t_insertion insert);

typedef struct s_chunk_entry
{
	t_u32	high;
	t_u32	low;
}	t_chunk_entry;

t_chunk_entry	find_chunk_entry(t_rstack stack, t_u32 value);
bool			cheapest_chunk_transfer(
					t_solver *solver, t_insertion *cheapest);
t_insertion		optimal_chunk_transfer(
					t_u32 a_size, t_u32 a_index,
					t_u32 b_size, t_chunk_entry b_entry);

bool			array_is_sorted(t_array nums);
bool			array_has_dups(t_array nums, t_i32 *dup);

#endif