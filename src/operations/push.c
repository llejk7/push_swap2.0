/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:54:33 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:02:36 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Moves the top element from the source stack to the destination stack.
** If the source stack is empty or NULL, the function does nothing.
*/
void	push(t_stack *source_stack, t_stack *destination_stack)
{
	t_node	*temp;

	if (!source_stack || !source_stack->top)
		return ;
	temp = source_stack->top;
	source_stack->top = source_stack->top->next;
	source_stack->size--;
	temp->next = destination_stack->top;
	destination_stack->top = temp;
	destination_stack->size++;
}
