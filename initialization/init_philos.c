/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:42:14 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:17:50 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_init_mutex_philo(t_philo *philo)
{
	if (pthread_mutex_init(&philo->philo_lock, NULL))
	{
		printf("%s", ERROR_MUTEX3);
		return (0);
	}
	return (1);
}

static int	ft_init_philo(t_info *info, t_philo *philo, int id)
{
	philo->info = info;
	philo->philo_id = id + 1;
	philo->pending_meals = info->meals_to_eat;
	philo->eating = 0;
	philo->time_of_death = 0;
	philo->last_meal = 0;
	if (philo->philo_id == 1)
	{
		philo->rigth_fork_id = info->philo_count - 1;
		philo->left_fork_id = 0;
	}
	else
	{
		philo->rigth_fork_id = philo->philo_id - 2;
		philo->left_fork_id = philo->philo_id - 1;
	}
	if (!ft_init_mutex_philo(philo))
		return (0);
	return (1);
}

int	ft_init_philos(t_info *info)
{
	int		i;

	info->philos = (t_philo *)ft_calloc(info->philo_count, sizeof(t_philo));
	if (!info->philos)
	{
		printf("%s", ERROR_MALLOC_PHILO);
		return (0);
	}
	i = 0;
	while (i <= (info->philo_count - 1))
	{
		if (!ft_init_philo(info, &info->philos[i], i))
			return (0);
		i++;
	}
	return (1);
}
