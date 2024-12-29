/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:26:12 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 23:56:59 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Find the index of the smallest element in the stack
int find_min_index(t_stack *stack)
{
    t_node *current;
    int min;
    int index;
    int min_index;

    if (!stack || !stack->top)  // Handle NULL or empty stack
        return (-1);

    current = stack->top;
    min = current->value;
    index = 0;
    min_index = 0;

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
    int min_index;
    int stack_size;

    if (!stack_a || !stack_b || !stack_a->top)  // Validate stacks
        return;

    min_index = find_min_index(stack_a);
    stack_size = stack_a->size;

    if (min_index <= stack_size / 2)
    {
        while (min_index-- > 0)
        {
            write(1, "ra\n", 3);  // Rotate stack_a upwards
            rotate(stack_a);
        }
    }
    else
    {
        min_index = stack_size - min_index;
        while (min_index-- > 0)
        {
            write(1, "rra\n", 4);  // Rotate stack_a downwards
            reverse_rotate(stack_a);
        }
    }
    write(1, "pb\n", 3);  // Push top of stack_a to stack_b
    push(stack_a, stack_b);
}

// Sort stacks with 4 or 5 elements
void sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size < 4)  // Validate stacks
        return;

    if (stack_a->size == 4)
    {
        push_min_to_b(stack_a, stack_b);  // Push the smallest to stack_b
        sort_three(stack_a);             // Sort the remaining 3 in stack_a
        write(1, "pa\n", 3);             // Push the smallest back to stack_a
        push(stack_b, stack_a);
    }
    else if (stack_a->size == 5)
    {
        push_min_to_b(stack_a, stack_b);  // Push the smallest to stack_b
        push_min_to_b(stack_a, stack_b);  // Push the next smallest to stack_b
        sort_three(stack_a);              // Sort the remaining 3 in stack_a
        write(1, "pa\n", 3);              // Push the smallest back to stack_a
        push(stack_b, stack_a);
        write(1, "pa\n", 3);              // Push the next smallest back to stack_a
        push(stack_b, stack_a);
    }
}
