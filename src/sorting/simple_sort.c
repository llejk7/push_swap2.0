/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:08:31 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:09:32 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
	{
		write(1, "sa\n", 3);
		swap(stack_a);
	}
}

void	handle_sort_three(t_stack *stack_a, int first, int second, int third)
{
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
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || stack_a->size < 3)
		return ;
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	handle_sort_three(stack_a, first, second, third);
	if (first < second && second > third && first < third)
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
