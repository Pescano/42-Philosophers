/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:56:21 by paescano          #+#    #+#             */
/*   Updated: 2023/09/09 12:49:42 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (!ft_check_args(argc, argv))
		return (1);
	if (!ft_init(&info, argv, argc))
	{
		ft_clean_info(&info);
		return (1);
	}
	if (!ft_init_philosopher(&info))
	{
		ft_clean_info(&info);
		return (1);
	}
	ft_clean_info(&info);
	return (0);
}
