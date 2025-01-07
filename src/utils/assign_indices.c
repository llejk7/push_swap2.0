/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:15:03 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:19:02 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Assigns an index to each element in the stack based on its value.
** The smallest value gets index 0, the next smallest gets 1, and so on.
*/
void	assign_indices(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!stack_a || !stack_a->top)
		return ;
	current = stack_a->top;
	while (current)
	{
		index = 0;
		compare = stack_a->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
