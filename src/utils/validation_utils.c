/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:03:09 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:34:33 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <limits.h>

/*
** Skips leading whitespace characters in a string.
*/
static const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	return (str);
}

/*
** Checks if a string represents a valid integer.
** Returns 1 if valid, 0 otherwise.
*/
int	is_valid_int(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	str = skip_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

/*
** Parses and validates a single argument.
*/
void	parse_argument(const char *arg, t_stack *stack_a)
{
	int	parsed_value;

	if (!is_valid_int(arg))
		error_exit();
	parsed_value = atoi(arg);
	if (has_duplicate(stack_a, parsed_value))
		error_exit();
	add_to_stack(stack_a, parsed_value);
}
