/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionsss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:36:06 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 13:43:06 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*allocates position of desired value in stack
temp is assigned the stack
while the stack exists the position of each node
is assigned a value beginning from 0, temp moves to
next node in stack*/
void	get_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

/*find the node with the lowest index in the stack and return the 
position of this node (value) if the index is higher than 'lowest'
assign lowest this new index - cycle to the next node until lowest
index is found - return the position of this node*/
int	lowest_index_pos(t_stack **stack_a)
{
	t_stack	*temp;
	int		lowest;
	int		position;

	temp = *stack_a;
	lowest = 2147483647;
	get_pos(stack_a);
	position = temp->pos;
	while (temp)
	{
		if (temp->index < lowest)
		{
			lowest = temp->index;
			position = temp->pos;
		}
		temp = temp->next;
	}
	return (position);
}

/*finds ideal target for value in stack b to move to stack a*/
int	get_target(t_stack **stack_a, int index_b, int t_index, int target_pos)
{
	t_stack	*tempa;

	tempa = *stack_a;
	while (tempa)
	{
		if (tempa->index > index_b && tempa->index < t_index)
		{
			t_index = tempa->index;
			target_pos = tempa->pos;
		}
		tempa = tempa->next;
	}
	if (t_index != 2147483647)
		return (target_pos);
	tempa = *stack_a;
	while (tempa)
	{
		if (tempa->index < t_index)
		{
			t_index = tempa->index;
			target_pos = tempa->pos;
		}
		tempa = tempa->next;
	}
	return (target_pos);
}

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, 2147483647, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}	
