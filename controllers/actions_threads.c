/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:13:04 by paescano          #+#    #+#             */
/*   Updated: 2023/09/07 20:16:06 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_start_all_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_create(&info->threads[i], NULL, &ft_init_routine,
				&info->philos[i]) != 0)
		{
			printf("%s", ERROR_THREAD1);
			return (0);
		}
		usleep(1);
		i++;
	}
	return (1);
}

int	ft_stop_all_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_join(info->threads[i], NULL) != 0)
		{
			printf("%s", ERROR_THREAD2);
			return (0);
		}
		i++;
	}
	return (1);
}
