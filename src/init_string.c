/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:44:38 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 13:21:28 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_man_str(char **list)
{
	int	i;

	i = -1;
	while (list[++i])
	{
		if (check_num(list[i]) != 0)
			return (invalid_input(1));
	}
	i = -1;
	while (list[++i])
	{
		if (check_int(list[i]) != 0)
			return (invalid_input(2));
	}
	i = -1;
	while (list[++i])
	{
		if (seeing_double(list[i], list, i) != 0)
			return (invalid_input(3));
	}
	return (0);
}

t_stack	*init_string(char **argv)
{
	t_stack		*stacka;
	char		**list;
	int			i;
	long int	num;
	int			x;

	i = 0;
	num = 1;
	list = ft_split(argv[1], 32);
	while (list[i] != NULL)
		i++;
	if (error_man_str(list) != 0)
		return (0);
	x = 0;
	while (x < i)
	{
		num = ft_atoi(list[x]);
		if (x == 0)
			stacka = create_node((int)num);
		else
			addtostack(&stacka, create_node((int)num));
		x++;
	}
	return (stacka);
}
