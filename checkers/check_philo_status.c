/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:08:47 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:35:39 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_check_any_die(t_info *info, int id)
{
	pthread_mutex_lock(&info->philos[id].philo_lock);
	if ((info->meals_to_eat == -1 || info->philos[id].pending_meals > 0)
		&& !info->philos[id].eating && ((info->philos[id].last_meal != 0
				&& info->philos[id].last_meal + info->time_die <= ft_get_time())
			|| (info->philo_count == 1 && (ft_get_time() - info->start_time)
				> info->time_die)))
	{
		pthread_mutex_unlock(&info->philos[id].philo_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->philos[id].philo_lock);
	return (0);
}

int	ft_check_philos_dead(t_info *info, int id)
{
	pthread_mutex_lock(&info->info_lock);
	if (info->all_filled)
	{
		pthread_mutex_unlock(&info->info_lock);
		return (0);
	}
	pthread_mutex_unlock(&info->info_lock);
	if (ft_check_any_die(info, id))
	{
		pthread_mutex_lock(&info->info_lock);
		info->dead = 1;
		pthread_mutex_unlock(&info->info_lock);
		ft_print_died(info, &info->philos[id]);
		return (1);
	}
	return (0);
}

int	ft_check_any_filled(t_info *info, int id)
{
	pthread_mutex_lock(&info->philos[id].philo_lock);
	if (info->philos[id].filled)
	{
		pthread_mutex_unlock(&info->philos[id].philo_lock);
		return (0);
	}
	if (info->philos[id].pending_meals == 0)
	{
		info->philos[id].filled = 1;
		pthread_mutex_unlock(&info->philos[id].philo_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->philos[id].philo_lock);
	return (0);
}

int	ft_check_philos_ate(t_info *info, int id)
{
	static int	philos_filled;

	if (info->meals_to_eat == -1)
		return (0);
	if (ft_check_any_filled(info, id))
		philos_filled++;
	if (philos_filled >= info->philo_count)
	{
		pthread_mutex_lock(&info->info_lock);
		info->all_filled = 1;
		pthread_mutex_unlock(&info->info_lock);
		return (1);
	}
	else
		return (0);
}
