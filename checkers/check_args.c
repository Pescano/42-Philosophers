/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:15:26 by paescano          #+#    #+#             */
/*   Updated: 2023/09/03 11:52:27 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_check_argc(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("%s", ERROR_ARGC);
		return (0);
	}
	return (1);
}

static int	ft_check_exist(char *str)
{
	if (!str[0])
	{
		printf("%s", ERROR_ARGV);
		return (0);
	}
	return (1);
}

static int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!ft_check_exist(argv[i]))
		return (0);
	while (argv[i])
	{
		j = 0;
		if (!ft_check_exist(argv[i]))
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%s", ERROR_ARGV2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_check_meals(int argc, char **argv)
{
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("%s", ERROR_MEAL);
		return (0);
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	if (!ft_check_argc(argc))
		return (0);
	if (!ft_check_argv(argv))
		return (0);
	if (!ft_check_meals(argc, argv))
		return (0);
	return (1);
}
