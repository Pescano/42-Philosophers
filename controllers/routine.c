/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:36:21 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:47:11 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_look_dead_filled_info(t_info *info)
{
	pthread_mutex_lock(&info->info_lock);
	if (info->dead || info->all_filled)
	{
		pthread_mutex_unlock(&info->info_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->info_lock);
	return (0);
}

static int	ft_set_philo_eating(t_info *info, t_philo *philo)
{
	if (ft_look_dead_filled_info(info))
		return (0);
	pthread_mutex_lock(&philo->philo_lock);
	philo->eating = 1;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->philo_lock);
	return (1);
}

static int	ft_update_meals(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	if (info->meals_to_eat != -1)
	{
		philo->pending_meals--;
		if (philo->pending_meals <= 0)
		{
			pthread_mutex_unlock(&philo->philo_lock);
			return (0);
		}
	}
	pthread_mutex_unlock(&philo->philo_lock);
	return (1);
}

static int	ft_philo_eat(t_info *info, t_philo *philo)
{
	ft_take_fork_rigth(info, philo);
	ft_take_fork_left(info, philo);
	if (!ft_set_philo_eating(info, philo))
	{
		ft_drop_fork_rigth(info, philo);
		ft_drop_fork_left(info, philo);
		return (0);
	}
	ft_print_msg(info, philo, EAT, GREEN);
	if (!ft_sleep_philos(info->time_eat, info, philo)
		|| !ft_update_meals(info, philo))
	{
		ft_drop_fork_rigth(info, philo);
		ft_drop_fork_left(info, philo);
		return (0);
	}
	ft_drop_fork_rigth(info, philo);
	ft_drop_fork_left(info, philo);
	return (1);
}

int	ft_routine(t_philo *philo, t_info *info)
{
	if (ft_look_dead_filled_info(info))
		return (0);
	if (!ft_philo_eat(info, philo))
		return (0);
	ft_print_msg(info, philo, SLEEP, BLUE);
	if (!ft_sleep_philos(info->time_sleep, info, philo))
		return (0);
	ft_print_msg(info, philo, THINK, YELLOW);
	return (1);
}
