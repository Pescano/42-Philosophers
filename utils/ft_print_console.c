/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_console.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:59:09 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:21:19 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	ft_printf(t_info *info, t_philo *philo, char *msg, char *color)
{
	printf("%llu %i %s%s%s\n", ft_get_time() - info->start_time,
		philo->philo_id, color, msg, "\033[0m");
}

void	ft_print_died(t_info *info, t_philo *philo)
{
	printf("%llu %i %s%s%s\n", ft_get_time() - info->start_time,
		philo->philo_id, RED, DIED, "\033[0m");
}

void	ft_print_msg(t_info *info, t_philo *philo, char *msg, char *color)
{
	pthread_mutex_lock(&info->info_lock);
	if (info->dead)
	{
		pthread_mutex_unlock(&info->info_lock);
		if (philo->has_forks)
		{
			ft_drop_fork_rigth(info, philo);
			ft_drop_fork_left(info, philo);
		}
		return ;
	}
	ft_printf(info, philo, msg, color);
	pthread_mutex_unlock(&info->info_lock);
}
