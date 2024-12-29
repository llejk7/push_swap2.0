/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:15:03 by kjell             #+#    #+#             */
/*   Updated: 2024/12/30 00:02:59 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * assign_indices - Assigns an index to each element in the stack based on its value.
 * @stack_a: The stack to assign indices to.
 */
void assign_indices(t_stack *stack_a)
{
    t_node *current;
    t_node *compare;
    int index;

    if (!stack_a || !stack_a->top)  // Ensure stack is not empty
        return;

    current = stack_a->top;
    while (current)
    {
        index = 0;
        compare = stack_a->top;

        // Count elements with smaller values
        while (compare)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }

        // Assign the computed index to the current node
        current->index = index;
        current = current->next;
    }
}
