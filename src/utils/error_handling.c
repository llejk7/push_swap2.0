/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:04:05 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 21:04:34 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Print error message and exit
void error_exit(void) {
    write(2, "Error\n", 6);
    exit(1);
}

// Free the stack
void free_stack(t_stack *stack) {
    t_node *current = stack->top;
    t_node *temp;

    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->size = 0;
}
