/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:04:54 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:36:21 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes stacks.
*/
void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_a->size = 0;
	stack_b->top = NULL;
	stack_b->size = 0;
}

/*
** Handles sorting based on the stack size.
*/
void	handle_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/*
** Main function for the push_swap program.
*/
int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	initialize_stacks(&stack_a, &stack_b);
	if (argc < 2)
		return (0);
	parse_input(argc, argv, &stack_a);
	if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	handle_sorting(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
