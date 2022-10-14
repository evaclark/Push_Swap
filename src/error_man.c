/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:06:57 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 11:40:12 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '-')
			i++;
		if (!(argv [i] >= '0' && argv[i] <= '9'))
			return (-1);
	}
	return (0);
}

int	check_int(char *argv)
{
	long int	num;

	num = ft_atoi(argv);
	if (num < -2147483647 || num > 2147483647)
		return (-1);
	return (0);
}

int	seeing_double(char *argv, char **av, int i)
{
	long int	num;

	num = ft_atoi(argv);
	while (av[i + 1])
	{
		if (num == ft_atoi(av[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

int	invalid_input(int error)
{
	if (error == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (error == 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (error == 3)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (-1);
}

int	error_man(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (check_num(argv[i]) != 0)
			return (invalid_input(1));
	}
	i = 0;
	while (argv[++i])
	{
		if (check_int(argv[i]) != 0)
			return (invalid_input(2));
	}
	i = 0;
	while (argv[++i])
	{
		if (seeing_double(argv[i], argv, i) != 0)
			return (invalid_input(3));
	}
	return (0);
}
