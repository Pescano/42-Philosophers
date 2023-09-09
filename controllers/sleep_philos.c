/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:56:00 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 13:02:02 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_look_info_dead(t_info *info)
{
	pthread_mutex_lock(&info->info_lock);
	if (!info->dead)
	{
		pthread_mutex_unlock(&info->info_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->info_lock);
	return (0);
}

static int	ft_look_philo_dead(t_info *info, t_philo *philo)
{
	if (philo)
	{
		pthread_mutex_lock(&philo->philo_lock);
		if ((philo->last_meal + info->time_die) < ft_get_time())
		{
			pthread_mutex_lock(&info->info_lock);
			info->dead = 1;
			pthread_mutex_unlock(&info->info_lock);
			pthread_mutex_unlock(&philo->philo_lock);
			return (0);
		}
		pthread_mutex_unlock(&philo->philo_lock);
	}
	return (1);
}

int	ft_sleep_philos(unsigned long long time_stop, t_info *info, t_philo *philo)
{
	unsigned long long	time_start;

	time_start = ft_get_time();
	while (ft_look_info_dead(info))
	{
		if (philo && !ft_look_philo_dead(info, philo))
			return (0);
		if (ft_get_time() - time_start >= time_stop)
			break ;
		usleep(10);
	}
	return (1);
}
