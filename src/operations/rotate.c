/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:01 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:05:09 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Moves the top element of the stack to the bottom.
** If the stack has fewer than two elements or is NULL, does nothing.
*/
void	rotate(t_stack *stack)
{
	t_node	*top_node;
	t_node	*last_node;

	if (!stack || stack->size < 2)
		return ;
	top_node = stack->top;
	stack->top = stack->top->next;
	last_node = stack->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = top_node;
	top_node->next = NULL;
}
