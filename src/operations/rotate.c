/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:01 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 20:58:12 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void rotate(t_stack *stack) {
    t_node *temp;
    t_node *current;

    if (!stack || stack->size < 2)
        return;
    temp = stack->top;
    stack->top = stack->top->next;
    current = stack->top;
    while (current->next)
        current = current->next;
    current->next = temp;
    temp->next = NULL;
}
