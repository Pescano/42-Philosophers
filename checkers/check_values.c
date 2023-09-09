/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:51:21 by paescano          #+#    #+#             */
/*   Updated: 2023/09/03 12:52:00 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_check_value_info(t_info *info)
{
	if (info->philo_count < 1 || info->philo_count > 200)
	{
		printf("%s", ERROR_PHILO);
		return (0);
	}
	else if (info->time_die < 1 || info->time_die > INT_MAX)
	{
		printf("%s", ERROR_DIE);
		return (0);
	}
	else if (info->time_eat < 1 || info->time_eat > INT_MAX)
	{
		printf("%s", ERROR_EAT);
		return (0);
	}
	else if (info->time_sleep < 1 || info->time_sleep > INT_MAX)
	{
		printf("%s", ERROR_SLEEP);
		return (0);
	}
	return (1);
}
