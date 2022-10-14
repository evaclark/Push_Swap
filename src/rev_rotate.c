/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:14:42 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 12:16:22 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find last value and place at top of stack
shift all other values down 1 in stack
gets end of stack, start of stack and second to last
of stack - start of stack now end of stack - end is first
pointer to end of stack is null, ending it.*/
void	rev_rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*almost;
	t_stack	*start;

	end = gettobottom(*stack);
	almost = secondlast(*stack);
	start = *stack;
	*stack = end;
	(*stack)->next = start;
	almost->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
