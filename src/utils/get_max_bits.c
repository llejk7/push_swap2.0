/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:52:18 by kjell             #+#    #+#             */
/*   Updated: 2024/12/30 00:01:45 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../inc/push_swap.h"

/**
 * get_max_bits - Determines the number of bits needed to represent the largest number in the stack.
 * @stack: The stack to analyze.
 *
 * Returns the number of bits required to represent the largest number in binary.
 * If the stack is empty, returns 0.
 */
int get_max_bits(t_stack *stack)
{
    t_node *current;
    int max;
    int bits;

    if (!stack || !stack->top)  // Ensure the stack is not empty
        return (0);

    current = stack->top;
    max = current->value;
    bits = 0;

    // Find the maximum value in the stack
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }

    // Count the number of bits needed to represent the max value
    while ((max >> bits) != 0)
        bits++;

    return (bits);
}
