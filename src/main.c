/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:04:54 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 22:53:46 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // For debugging

void print_stack(t_stack *stack, const char *name)
{
    t_node *current = stack->top;
    printf("Stack %s: ", name);
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack stack_a = {NULL, 0};
    t_stack stack_b = {NULL, 0};

    if (argc < 2)
    {
        printf("No input provided.\n");
        return (0);
    }

    parse_input(argc, argv, &stack_a);

    print_stack(&stack_a, "A (before sorting)");
    print_stack(&stack_b, "B (before sorting)");

    if (is_sorted(&stack_a))
    {
        printf("Stack is already sorted.\n");
        free_stack(&stack_a);
        return (0);
    }

    if (stack_a.size <= 5)
    {
        printf("Sorting small stack...\n");
        sort_small_stack(&stack_a, &stack_b);
    }
    else
    {
        printf("Sorting large stack with hybrid_sort...\n");
        hybrid_sort(&stack_a, &stack_b);
    }

    print_stack(&stack_a, "A (after sorting)");
    print_stack(&stack_b, "B (after sorting)");

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}