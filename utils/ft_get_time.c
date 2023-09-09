/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:44 by paescano          #+#    #+#             */
/*   Updated: 2023/09/04 17:50:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned long long	ft_get_time(void)
{
	struct timeval			tv;

	if (gettimeofday(&tv, NULL) == 0)
		return (((tv.tv_sec) * (unsigned int)1000) + ((tv.tv_usec) / 1000));
	printf("%s", ERROR_GETTIME);
	return (0);
}
