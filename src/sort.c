/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:24:49 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 12:34:13 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	largest_index(t_stack *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

/*sorts three numbers into ascending order*/
void	sortthree(t_stack **stack_a)
{
	int	largest;

	if (issorted(*stack_a))
		return ;
	largest = largest_index(*stack_a);
	if ((*stack_a)->index == largest)
		ra(stack_a);
	else if ((*stack_a)->next->index == largest)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

/*while stack size greater than 5 (to sort larger numbers), 
counter is less than size of stack andthe number of values 
pushed is less than half of the size of stack_a
we want the smaller numbers pushed first so it is somewhat 
easier to sort, so less than the middle index (size/2)
otherwise rotate so smaller indexes are pushed first
while numbers are 6 or under, easier to sort*/
static void	sortbpush(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	push;
	int	i;

	size = sizeofstack(*stack_a);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			push++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - push > 3)
	{
		pb(stack_a, stack_b);
		push++;
	}
}

/*rotates the stack until the lowest element is at the top ready to be pushed*/
static void	shift_stack(t_stack **stack_a)
{
	int	start_pos;
	int	size;

	size = sizeofstack(*stack_a);
	start_pos = lowest_index_pos(stack_a);
	if (start_pos > size / 2)
	{
		while (start_pos < size)
		{
			rra(stack_a);
			start_pos++;
		}
	}
	else
	{
		while (start_pos > 0)
		{
			ra(stack_a);
			start_pos--;
		}
	}
}

/*sorting algorithm for stacks larger than 3*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	sortbpush(stack_a, stack_b);
	sortthree(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		cost(stack_a, stack_b);
		execute_cheapest(stack_a, stack_b);
	}
	if (!issorted(*stack_a))
		shift_stack(stack_a);
}
