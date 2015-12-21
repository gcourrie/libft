/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:08:57 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:40:54 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*str++ == (unsigned char)c)
			return ((void *)(str - 1));
	}
	return (NULL);
}
