/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:15:03 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 22:17:55 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

void assign_indices(t_stack *stack_a)
{
    t_node *current;
    t_node *compare;
    int index;

    current = stack_a->top;
    while (current)
    {
        index = 0;
        compare = stack_a->top;
        while (compare)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        printf("Value: %d, Index: %d\n", current->value, current->index); // Debugging
        current = current->next;
    }
}
