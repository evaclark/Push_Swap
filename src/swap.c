/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:18:08 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 12:17:55 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*access first number and second number*/
/*swap both*/
/*indexies must be swapped too*/
void	swap(t_stack *stack)
{
	int	c;

	if (stack == NULL || stack->next == NULL)
		return ;
	c = stack->value;
	stack->value = stack->next->value;
	stack->next->value = c;
	c = stack->index;
	stack->index = stack->next->index;
	stack->next->index = c;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
