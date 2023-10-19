/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:49:42 by vchakhno          #+#    #+#             */
/*   Updated: 2023/10/19 07:50:25 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libft/libft.h>

void	ft_match_sign(t_str *str, t_i8 *sign)
{
	*sign = 1;
	if (*str->c_str == '+' || *str->c_str == '-')
	{
		if (*str->c_str == '-')
			*sign = -1;
		str->len--;
		str->c_str++;
	}
}

bool	ft_i32_parse_digits(t_str str, t_i32 *val)
{
	t_i32	num;
	t_u32	i;

	if (str.len > 10 || !ft_str_is_digit(str))
		return (false);
	if (str.len == 10 && ft_str_compare_c_str(str, "2147483647") > 0)
		return (false);
	num = 0;
	i = 0;
	while (i < str.len)
	{
		num = num * 10 + str.c_str[i] - '0';
		i++;
	}
	*val = num;
	return (true);
}

bool	ft_i32_from_str(t_str str, t_i32 *num)
{
	t_i8	sign;
	t_i32	val;

	if (ft_str_equal_c_str(str, "-2147483648"))
	{
		*num = -2147483647 - 1;
		return (true);
	}
	ft_match_sign(&str, &sign);
	if (!ft_i32_parse_digits(str, &val))
		return (false);
	*num = val * (t_i32) sign;
	return (true);
}

bool	parse_nums(t_u32 size, char **strs, t_vector *nums)
{
	t_u32	i;
	t_i32	num;

	if (!ft_vector_alloc(nums, sizeof(t_i32), size))
		return (false);
	i = 0;
	while (i < size)
	{
		if (!ft_i32_from_str(ft_str(strs[i]), &num))
		{
			ft_vector_free(*nums);
			return (false);
		}
		ft_vector_push(nums, &num);
		i++;
	}
	return (true);
}
