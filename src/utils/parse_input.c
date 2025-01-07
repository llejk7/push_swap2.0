/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:29:37 by krenken           #+#    #+#             */
/*   Updated: 2025/01/07 22:30:08 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
** Parses and validates command-line arguments, adding them to stack_a.
*/
void	parse_input(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	if (argc < 2)
		exit(0);
	i = argc - 1;
	while (i > 0)
	{
		parse_argument(argv[i], stack_a);
		i--;
	}
}
