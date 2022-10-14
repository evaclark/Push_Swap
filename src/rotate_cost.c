/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:17:27 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 12:17:14 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*seperate rotating functions when sorting larger stacks - takes cost into
account to accurately chose either rotate or reverse rotate*/
void	rr_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(stack_a, stack_b);
	}
}

void	r_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(stack_a, stack_b);
	}
}

static void	rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stack_a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stack_b);
			(*cost)++;
		}
	}
}

/*if both costs are a negative number - rrr if both costs are positive rr
if costs arent matching rotate a and b seperately - then push a to b*/
void	movetstack(t_stack **stack_a, t_stack **stack_b, int costa, int costb)
{
	if (costa < 0 && costb < 0)
		rr_both(stack_a, stack_b, &costa, &costb);
	else if (costa > 0 && costb > 0)
		r_both (stack_a, stack_b, &costa, &costb);
	rotate_a(stack_a, &costa);
	rotate_b(stack_b, &costb);
	pa(stack_b, stack_a);
}
