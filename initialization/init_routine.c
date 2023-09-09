/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:13:04 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 13:16:08 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	simulate_one(t_info *info, t_philo *philo)
{
	ft_print_msg(info, philo, TAKE_FORK, MAGENTA);
	usleep(info->time_die);
	pthread_mutex_lock(&info->info_lock);
	info->dead = 1;
	pthread_mutex_unlock(&info->info_lock);
}

void	*ft_init_routine(void *thread_struct)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)thread_struct;
	info = philo->info;
	if (info->philo_count == 1)
	{
		simulate_one(info, philo);
		return (NULL);
	}
	ft_print_msg(info, philo, THINK, YELLOW);
	if (philo->philo_id % 2 == 0 || (int)philo->philo_id == info->philo_count)
		ft_sleep_philos(info->time_eat * 0.5, info, NULL);
	while (1)
	{
		if (!ft_routine(philo, info))
			break ;
	}
	return (NULL);
}
