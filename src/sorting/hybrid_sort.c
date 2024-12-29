/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:34:28 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 22:53:28 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <unistd.h> // For write function

void hybrid_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 5)
    {
        sort_small_stack(stack_a, stack_b); // Use existing logic for small stacks
        return;
    }

    // Partition stack_a into two halves
    int mid = stack_a->size / 2;
    int i = 0;

    while (i < mid)
    {
        write(1, "pb\n", 3);
        push(stack_a, stack_b);
        i++;
    }

    // Recursively sort both halves
    hybrid_sort(stack_a, stack_b);
    hybrid_sort(stack_b, stack_a);

    // Merge sorted halves back into stack_a
    while (stack_b->size > 0)
    {
        write(1, "pa\n", 3);
        push(stack_b, stack_a);
    }
}
