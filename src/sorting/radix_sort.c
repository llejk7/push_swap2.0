/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:40:41 by kjell             #+#    #+#             */
/*   Updated: 2024/12/30 00:06:12 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * radix_sort - Sorts a stack using the Radix Sort algorithm.
 * @stack_a: The primary stack to be sorted.
 * @stack_b: The auxiliary stack used for sorting.
 */
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits;
    int size;
    int i;
    int j;

    // Normalize values to indices
    assign_indices(stack_a);
    size = stack_a->size;
    max_bits = get_max_bits(stack_a);

    // Sort based on each bit
    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            if ((stack_a->top->index >> i) & 1)
            {
                write(1, "ra\n", 3);
                rotate(stack_a);
            }
            else
            {
                write(1, "pb\n", 3);
                push(stack_a, stack_b);
            }
        }

        // Push all elements back to stack_a
        while (stack_b->size > 0)
        {
            write(1, "pa\n", 3);
            push(stack_b, stack_a);
        }
    }
}
