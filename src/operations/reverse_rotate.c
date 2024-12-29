/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:21 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 23:00:18 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * reverse_rotate - Moves the last element of the stack to the top.
 * @stack: The stack to perform the operation on.
 *
 * If the stack has fewer than two elements or is NULL, the function does nothing.
 */
void reverse_rotate(t_stack *stack)
{
    t_node *second_last_node;
    t_node *last_node;

    // Check if the stack is valid and has at least two elements
    if (!stack || stack->size < 2)
        return;

    second_last_node = NULL;
    last_node = stack->top;

    // Traverse to the last node, keeping track of the second-to-last node
    while (last_node->next)
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }

    // Detach the last node and move it to the top of the stack
    second_last_node->next = NULL;
    last_node->next = stack->top;
    stack->top = last_node;
}
