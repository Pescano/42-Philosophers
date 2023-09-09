/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:13:18 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:48:21 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_init_mutex_info(t_info *info)
{
	if (pthread_mutex_init(&info->info_lock, NULL) != 0)
	{
		printf("%s", ERROR_MUTEX1);
		return (0);
	}
	return (1);
}

static int	ft_init_info(t_info *info, char **argv, int argc)
{
	info->dead = 0;
	info->start_time = 0;
	info->all_filled = 0;
	info->philo_count = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	info->threads = (pthread_t *)ft_calloc(info->philo_count,
			sizeof(pthread_t));
	if (argc == 6)
		info->meals_to_eat = ft_atoi(argv[5]);
	else
		info->meals_to_eat = -1;
	return (1);
}

int	ft_init(t_info *info, char **argv, int argc)
{
	if (!ft_init_info(info, argv, argc))
		return (0);
	if (!ft_check_value_info(info))
		return (0);
	if (!ft_init_mutex_info(info))
		return (0);
	if (!ft_init_forks(info))
		return (0);
	if (!ft_init_philos(info))
		return (0);
	return (1);
}
