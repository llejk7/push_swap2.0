/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:54:33 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 22:59:33 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * push - Moves the top element from the source stack to the destination stack.
 * @source_stack: The stack to remove the element from.
 * @destination_stack: The stack to add the element to.
 *
 * If the source stack is empty or NULL, the function does nothing.
 */
void push(t_stack *source_stack, t_stack *destination_stack)
{
    t_node *temp;

    // Check if the source stack is valid and not empty
    if (!source_stack || !source_stack->top)
        return;

    // Remove the top element from the source stack
    temp = source_stack->top;
    source_stack->top = source_stack->top->next;
    source_stack->size--;

    // Add the removed element to the destination stack
    temp->next = destination_stack->top;
    destination_stack->top = temp;
    destination_stack->size++;
}
