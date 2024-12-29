/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjell <kjell@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:52:18 by kjell             #+#    #+#             */
/*   Updated: 2024/12/29 21:52:32 by kjell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int get_max_bits(t_stack *stack)
{
    t_node *current;
    int max;
    int bits;

    current = stack->top;
    max = current->value;
    bits = 0;

    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}
