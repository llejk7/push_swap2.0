/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:26:12 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 21:32:34 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Find the index of the smallest element in the stack
int find_min_index(t_stack *stack)
{
    t_node *current = stack->top;
    int min = current->value;
    int index = 0;
    int min_index = 0;

    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_index = index;
        }
        current = current->next;
        index++;
    }
    return (min_index);
}

// Push the smallest element to stack_b
void push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int min_index = find_min_index(stack_a);
    int size = stack_a->size;

    if (min_index <= size / 2)
    {
        while (min_index-- > 0)
        {
            write(1, "ra\n", 3);
            rotate(stack_a);
        }
    }
    else
    {
        min_index = size - min_index;
        while (min_index-- > 0)
        {
            write(1, "rra\n", 4);
            reverse_rotate(stack_a);
        }
    }
    write(1, "pb\n", 3);
    push(stack_a, stack_b);
}


// Sort stacks with 4 or 5 elements
void sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size == 4)
    {
        push_min_to_b(stack_a, stack_b);  // Push the smallest to stack_b
        sort_three(stack_a);             // Sort the remaining 3 in stack_a
        write(1, "pa\n", 3);
        push(stack_b, stack_a);          // Push back the smallest
    }
    else if (stack_a->size == 5)
    {
        push_min_to_b(stack_a, stack_b); // Push the smallest to stack_b
        push_min_to_b(stack_a, stack_b); // Push the next smallest to stack_b
        sort_three(stack_a);             // Sort the remaining 3 in stack_a
        write(1, "pa\n", 3);
        push(stack_b, stack_a);          // Push back the smallest
        write(1, "pa\n", 3);
        push(stack_b, stack_a);          // Push back the next smallest
    }
}
