/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:04:05 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 23:59:55 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * error_exit - Prints an error message and exits the program.
 */
void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

/**
 * free_stack - Frees all nodes in the stack and resets its state.
 * @stack: The stack to free.
 */
void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;

    if (!stack)  // Ensure the stack is valid
        return;

    current = stack->top;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->size = 0;
}
