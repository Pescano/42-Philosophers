/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:42:04 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:17:40 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_init_forks(t_info *info)
{
	int	i;

	info->forks = (pthread_mutex_t *)ft_calloc(info->philo_count,
			sizeof(pthread_mutex_t));
	if (!info->forks)
	{
		printf("%s", ERROR_MALLOC_FORKS);
		return (0);
	}
	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
		{
			printf("%s", ERROR_MUTEX2);
			return (0);
		}
		i++;
	}
	return (1);
}
