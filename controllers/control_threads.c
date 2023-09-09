/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:59:16 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:02:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_control_loop(t_info *info)
{
	int	i;

	pthread_mutex_unlock(&info->info_lock);
	while (1)
	{
		i = 0;
		while (i < (info->philo_count))
		{
			if (ft_check_philos_ate(info, i) || ft_check_philos_dead(info, i))
			{
				if (!ft_stop_all_threads(info))
					return (0);
				else
					return (1);
			}
			i++;
		}
		usleep(50);
	}
}

int	ft_init_philosopher(t_info *info)
{
	pthread_mutex_lock(&info->info_lock);
	if (!ft_start_all_threads(info))
		return (0);
	info->start_time = ft_get_time();
	if (!info->start_time)
		return (0);
	if (!ft_control_loop(info))
		return (0);
	return (1);
}
