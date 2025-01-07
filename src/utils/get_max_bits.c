/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:52:18 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:23:11 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Determines the number of bits needed to represent
** the largest number in the stack.
** Returns the number of bits required to represent the largest number in binary.
** If the stack is empty, returns 0.
*/
int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		bits;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	bits = 0;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
