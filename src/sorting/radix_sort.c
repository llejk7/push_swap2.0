/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:40:41 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 22:50:49 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>
#include "unistd.h"

// Find the largest number to calculate the number of bits needed
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits;
    int size;
    int i;
    int j;

    assign_indices(stack_a); // Normalize values to indices
    size = stack_a->size;
    max_bits = get_max_bits(stack_a);

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((stack_a->top->index >> i) & 1) == 1)
            {
                write(1, "ra\n", 3);
                rotate(stack_a);
            }
            else
            {
                write(1, "pb\n", 3);
                push(stack_a, stack_b);
            }
            j++;
        }

        // Push elements back only for relevant bit or in the final pass
        while (stack_b->size > 0)
        {
            if (((stack_b->top->index >> (i + 1)) & 1) == 1 || i == max_bits - 1)
            {
                write(1, "pa\n", 3);
                push(stack_b, stack_a);
            }
            else
            {
                write(1, "rb\n", 3);
                rotate(stack_b);
            }
        }

        i++;
    }
}
