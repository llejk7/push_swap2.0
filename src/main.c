/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:04:54 by kjell             #+#    #+#             */
/*   Updated: 2024/12/30 00:13:57 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * main - Entry point for the Push_swap program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
    t_stack stack_a = {NULL, 0};
    t_stack stack_b = {NULL, 0};

    // Check for input arguments
    if (argc < 2)
        return (0);

    // Parse and validate input
    parse_input(argc, argv, &stack_a);

    // Check if the stack is already sorted
    if (is_sorted(&stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }

    // Sort the stack based on its size
    if (stack_a.size <= 5)
        sort_small_stack(&stack_a, &stack_b);
    else
        radix_sort(&stack_a, &stack_b);

    // Free allocated memory
    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}
