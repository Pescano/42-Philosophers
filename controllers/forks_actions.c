/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:03:37 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 11:25:45 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_take_fork_rigth(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	pthread_mutex_lock(&info->forks[philo->rigth_fork_id]);
	philo->has_forks = 1;
	pthread_mutex_unlock(&philo->philo_lock);
	ft_print_msg(info, philo, TAKE_FORK, MAGENTA);
}

void	ft_take_fork_left(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	pthread_mutex_lock(&info->forks[philo->left_fork_id]);
	philo->has_forks = 1;
	pthread_mutex_unlock(&philo->philo_lock);
	ft_print_msg(info, philo, TAKE_FORK, MAGENTA);
}

void	ft_drop_fork_rigth(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	pthread_mutex_unlock(&info->forks[philo->rigth_fork_id]);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->philo_lock);
}

void	ft_drop_fork_left(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	pthread_mutex_unlock(&info->forks[philo->left_fork_id]);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->philo_lock);
}
