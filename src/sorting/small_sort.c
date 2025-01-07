/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:26:12 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:17:31 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		index;
	int		min_index;

	if (!stack || !stack->top)
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

static void	rotate_to_min(t_stack *stack_a, int min_index, int stack_size)
{
	if (min_index <= stack_size / 2)
	{
		while (min_index-- > 0)
		{
			write(1, "ra\n", 3);
			rotate(stack_a);
		}
	}
	else
	{
		min_index = stack_size - min_index;
		while (min_index-- > 0)
		{
			write(1, "rra\n", 4);
			reverse_rotate(stack_a);
		}
	}
}

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	stack_size;

	if (!stack_a || !stack_b || !stack_a->top)
		return ;
	min_index = find_min_index(stack_a);
	stack_size = stack_a->size;
	rotate_to_min(stack_a, min_index, stack_size);
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 4)
		return ;
	if (stack_a->size == 4)
	{
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		write(1, "pa\n", 3);
		push(stack_b, stack_a);
	}
	else if (stack_a->size == 5)
	{
		push_min_to_b(stack_a, stack_b);
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		write(1, "pa\n", 3);
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
		push(stack_b, stack_a);
	}
}
