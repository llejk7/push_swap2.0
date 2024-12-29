/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:03:09 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 23:58:57 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <limits.h>  // For INT_MAX and INT_MIN

/**
 * is_valid_int - Checks if a string represents a valid integer.
 * @str: The input string to validate.
 *
 * Returns 1 if the string is a valid integer, 0 otherwise.
 */
int is_valid_int(const char *str)
{
    long num = 0;
    int sign = 1;

    // Skip leading whitespaces
    while (*str == ' ' || *str == '\t' || *str == '\n'
           || *str == '\r' || *str == '\v' || *str == '\f')
        str++;

    // Handle optional sign
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Check if there are any digits
    if (!*str)
        return (0);

    // Parse digits and check for overflow
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

/**
 * has_duplicate - Checks if a value already exists in the stack.
 * @stack: The stack to check for duplicates.
 * @value: The value to check.
 *
 * Returns 1 if a duplicate is found, 0 otherwise.
 */
int has_duplicate(t_stack *stack, int value)
{
    t_node *current = stack->top;

    while (current)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

/**
 * add_to_stack - Adds a value to the top of the stack.
 * @stack: The stack to add the value to.
 * @value: The value to add.
 */
void add_to_stack(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        error_exit();  // Handle memory allocation failure

    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

/**
 * is_sorted - Checks if the stack is sorted in ascending order.
 * @stack: The stack to check.
 *
 * Returns 1 if sorted, 0 otherwise.
 */
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

/**
 * parse_input - Parses and validates command-line arguments, adding them to stack_a.
 * @argc: The argument count.
 * @argv: The argument vector.
 * @stack_a: The stack to populate with parsed values.
 */
void parse_input(int argc, char **argv, t_stack *stack_a)
{
    int parsed_value;

    if (argc < 2)
        exit(0);  // No input provided; exit silently

    for (int i = argc - 1; i > 0; i--)
    {
        if (!is_valid_int(argv[i]))
            error_exit();  // Invalid integer detected

        parsed_value = atoi(argv[i]);
        if (has_duplicate(stack_a, parsed_value))
            error_exit();  // Duplicate value detected

        add_to_stack(stack_a, parsed_value);
    }
}
