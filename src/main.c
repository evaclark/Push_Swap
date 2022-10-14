/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:46:49 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 12:26:58 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*checks to see if stack is already in ascending order*/
int	issorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_method(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !issorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		sortthree(stack_a);
	else if (size > 3 && !issorted(*stack_a))
		sort(stack_a, stack_b);
}

void	free_stacks(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
	{
		return ;
	}
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		size;

	stackb = NULL;
	if (argc == 2)
		stacka = init_string(argv);
	else
		stacka = initialise(argc, argv);
	size = sizeofstack(stacka);
	indexstack(stacka, size + 1);
	sort_method(&stacka, &stackb, size);
	free_stacks(&stacka);
	free_stacks(&stackb);
	return (0);
}
/* to print out values
while (stacka != NULL)
	{
		printf("%d\n", stacka->value);
		stacka = stacka->next;
	}
*/
