/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:08:31 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 21:18:24 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h> 

void sort_two(t_stack *stack_a)
{
    if (stack_a->top && stack_a->top->next)
    {
        if (stack_a->top->value > stack_a->top->next->value)
        {
            write(1, "sa\n", 3);
            swap(stack_a);
        }
    }
}

// Sort 3 elements in stack_a
void sort_three(t_stack *stack_a)
{
    int first = stack_a->top->value;
    int second = stack_a->top->next->value;
    int third = stack_a->top->next->next->value;

    if (first > second && second < third && first < third)
    {
        write(1, "sa\n", 3);
        swap(stack_a);
    }
    else if (first > second && second > third)
    {
        write(1, "sa\n", 3);
        swap(stack_a);
        write(1, "rra\n", 4);
        reverse_rotate(stack_a);
    }
    else if (first > second && second < third && first > third)
    {
        write(1, "ra\n", 3);
        rotate(stack_a);
    }
    else if (first < second && second > third && first < third)
    {
        write(1, "sa\n", 3);
        swap(stack_a);
        write(1, "ra\n", 3);
        rotate(stack_a);
    }
    else if (first < second && second > third && first > third)
    {
        write(1, "rra\n", 4);
        reverse_rotate(stack_a);
    }
}
