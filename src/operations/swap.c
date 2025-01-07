/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:54:49 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:06:24 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Swaps the top two elements of the stack.
** If the stack has fewer than two elements or is NULL, does nothing.
*/
void	swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || stack->size < 2)
		return ;
	first_node = stack->top;
	second_node = stack->top->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	stack->top = second_node;
}
