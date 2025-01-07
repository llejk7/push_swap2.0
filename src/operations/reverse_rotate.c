/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:21 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:03:36 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Moves the last element of the stack to the top.
** If the stack has fewer than two elements or is NULL, does nothing.
*/
void	reverse_rotate(t_stack *stack)
{
	t_node	*second_last_node;
	t_node	*last_node;

	if (!stack || stack->size < 2)
		return ;
	second_last_node = NULL;
	last_node = stack->top;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = stack->top;
	stack->top = last_node;
}
