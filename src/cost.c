/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:54:14 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 13:43:17 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*function looks to see if the element that is wanting to be moved is in
either the top or bottom half of the stack, if it is in the bottom it requires 
to be moved to the top of the stack to be pushed with rrb, if it is in the top
it requires rb - so by setting the cost of the values lower in the stack to
a negative we can easily distinguish which move is desired in the execution
function*/
void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = sizeofstack(temp_a);
	size_b = sizeofstack(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

/*finds cheapest number of moves to move desired value to into stack a*/
void	execute_cheapest(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stackb;
	cheapest = 2147483647;
	while (temp)
	{
		if (abs(temp->cost_a) + abs(temp->cost_b) < abs(cheapest))
		{
			cheapest = abs(temp->cost_b) + abs(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	movetstack(stacka, stackb, cost_a, cost_b);
}
