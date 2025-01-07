/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krenken <krenken@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:45:52 by kjell             #+#    #+#             */
/*   Updated: 2025/01/07 22:44:30 by krenken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* Function prototypes */
void				push(t_stack *src, t_stack *dest);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				parse_input(int argc, char **argv, t_stack *stack_a);
void				free_stack(t_stack *stack);
void				error_exit(void);
void				sort_two(t_stack *stack_a);
void				sort_three(t_stack *stack_a);
void				sort_small_stack(t_stack *stack_a, t_stack *stack_b);
int					is_sorted(t_stack *stack);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);
int					get_max_bits(t_stack *stack);
void				assign_indices(t_stack *stack_a);
void				hybrid_sort(t_stack *stack_a, t_stack *stack_b);
void				print_stack(t_stack *stack, const char *stack_name);
void				parse_argument(const char *arg, t_stack *stack_a);
int					has_duplicate(t_stack *stack, int value);
void				add_to_stack(t_stack *stack, int value);
int					is_sorted(t_stack *stack);

#endif