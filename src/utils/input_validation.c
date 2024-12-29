/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:03:09 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 22:01:06 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h> // For debugging (optional)

// Utility function to check if a string is a valid integer
#include <limits.h>

int is_valid_int(const char *str)
{
    long num;
    int sign;

    num = 0;
    sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n'
        || *str == '\r' || *str == '\v' || *str == '\f')
    {
        str++;
    }
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str)
        return (0);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        num = num * 10 + (*str - '0');
        if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
            return (0);
        str++;
    }
    return (1);
}

// Utility function to check for duplicates
int has_duplicate(t_stack *stack, int value)
{
    t_node *current;

    current = stack->top;
    while (current)
    {
        if (current->value == value)
        {
            printf("Duplicate found: %d\n", value);
            return (1);
        }
        current = current->next;
    }
    return (0);
}

// Add a value to the stack
void add_to_stack(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        printf("Memory allocation failed for value: %d\n", value); // Debugging
        error_exit();
    }

    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    printf("Stack size after addition: %d\n", stack->size); // Debugging
}

int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;

    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

// Parse and validate input
void parse_input(int argc, char **argv, t_stack *stack_a)
{
    int value;

    if (argc < 2)
    {
        printf("No input provided\n");
        exit(0);
    }

    for (int i = argc - 1; i > 0; i--)
    {
        printf("Parsing argument: %s\n", argv[i]);
        if (!is_valid_int(argv[i]))
        {
            printf("Invalid integer detected: %s\n", argv[i]);
            error_exit();
        }

        value = atoi(argv[i]);
        if (has_duplicate(stack_a, value))
        {
            printf("Duplicate detected: %d\n", value);
            error_exit();
        }

        printf("Adding to stack_a: %d\n", value);
        add_to_stack(stack_a, value);
    }
}
