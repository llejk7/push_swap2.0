/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:01 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 23:54:34 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * rotate - Moves the top element of the stack to the bottom.
 * @stack: The stack to perform the operation on.
 *
 * If the stack has fewer than two elements or is NULL, the function does nothing.
 */
void rotate(t_stack *stack)
{
    t_node *top_node;
    t_node *last_node;

    // Check if the stack is valid and has at least two elements
    if (!stack || stack->size < 2)
        return;

    // Save the top node and update the top of the stack
    top_node = stack->top;
    stack->top = stack->top->next;

    // Traverse to the last node
    last_node = stack->top;
    while (last_node->next)
        last_node = last_node->next;

    // Attach the old top node to the bottom of the stack
    last_node->next = top_node;
    top_node->next = NULL;
}
