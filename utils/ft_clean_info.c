/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:24:53 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:48:11 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_clean_info(t_info *info)
{
	int	i;

	i = info->philo_count;
	pthread_mutex_destroy(&info->info_lock);
	while (i > 0)
	{
		if (info->philos)
			pthread_mutex_destroy(&info->philos[i - 1].philo_lock);
		if (info->forks)
			pthread_mutex_destroy(&info->forks[i - 1]);
		i--;
	}
	if (info->philos)
		free(info->philos);
	if (info->forks)
		free(info->forks);
	if (info->threads)
		free(info->threads);
}
