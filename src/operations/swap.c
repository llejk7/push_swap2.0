/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:54:49 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 23:55:03 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The stack to perform the operation on.
 *
 * If the stack has fewer than two elements or is NULL, the function does nothing.
 */
void swap(t_stack *stack)
{
    t_node *first_node;
    t_node *second_node;

    // Check if the stack is valid and has at least two elements
    if (!stack || stack->size < 2)
        return;

    // Identify the first and second nodes
    first_node = stack->top;
    second_node = stack->top->next;

    // Swap the first two nodes
    first_node->next = second_node->next;
    second_node->next = first_node;

    // Update the stack's top pointer
    stack->top = second_node;
}
