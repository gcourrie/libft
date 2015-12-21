/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:17:16 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:48:55 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)malloc(sizeof(char) * ((len - start) + 1));
	if (!s1)
		return (NULL);
	s2 = s1;
	s += start;
	while (len--)
		*s2++ = *s++;
	return (s1);
}
