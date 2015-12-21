/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:50:19 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:41:26 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void				*ft_memcpy_bis(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = dst;
	s2 = src;
	while (len--)
		*s1++ = *s2++;
	return (dst);
}

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		tmp[len];
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = dst;
	s2 = src;
	ft_memcpy_bis(tmp, s2, len);
	ft_memcpy_bis(s1, tmp, len);
	return (dst);
}
