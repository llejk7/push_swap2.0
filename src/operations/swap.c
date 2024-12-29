/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:54:49 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 20:58:07 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void swap(t_stack *stack) {
    t_node *first;
    t_node *second;

    if (!stack || stack->size < 2)
        return;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}
