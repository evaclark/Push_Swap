/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:19 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 13:43:17 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addtostack(t_stack **stack, t_stack *node)
{
	t_stack	*current;

	if (!node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	current = gettobottom(*stack);
	current->next = node;
}

t_stack	*create_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof * node);
	if (!node)
		return (NULL);
	node->value = n;
	node->index = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

int	sizeofstack(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	indexstack(t_stack *stack_a, int size)
{
	t_stack	*i;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		i = stack_a;
		value = -2147483647;
		highest = NULL;
		while (i)
		{
			if (i->value == -2147483647 && i->index == 0)
				i->index = 1;
			if (i->value > value && i->index == 0)
			{
				value = i->value;
				highest = i;
				i = stack_a;
			}
			else
				i = i->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

t_stack	*initialise(int argc, char **argv)
{
	t_stack		*stacka;
	long int	num;
	int			i;

	stacka = NULL;
	num = 0;
	i = 1;
	if (error_man(argv) != 0)
		return (0);
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1)
			stacka = create_node((int)num);
		else
			addtostack(&stacka, create_node((int)num));
		i++;
	}
	return (stacka);
}
