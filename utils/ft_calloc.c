/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:36:54 by paescano          #+#    #+#             */
/*   Updated: 2023/08/31 20:39:07 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tsize;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	tsize = nmemb * size;
	ptr = malloc(tsize);
	if (!ptr)
		return (NULL);
	memset(ptr, '\0', tsize);
	return (ptr);
}
