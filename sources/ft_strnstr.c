/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:58:48 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:48:20 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_word(const char *s1, const char *s2, size_t n)
{
	if (!(*s2))
		return (1);
	else if (n == 0)
		return (0);
	else if (*s1 == *s2)
		return (ft_check_word(s1 + 1, s2 + 1, n - 1));
	else
		return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && n--)
	{
		if (*s1 == *s2)
			if (ft_check_word(s1 + 1, s2 + 1, n) != 0)
				return ((char *)s1);
		s1++;
	}
	return (NULL);
}
