/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:27:38 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 12:28:48 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*find first element of source stack and save second element from
source stack in a temp, place first element from source into dest stack*/
void	push(t_stack **source, t_stack **dest)
{
	t_stack	*next_node;

	if (*source == NULL)
		return ;
	next_node = (*source)->next;
	(*source)->next = *dest;
	*dest = *source;
	*source = next_node;
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
