/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:18:33 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:49:04 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strtrim(const char *s)
{
	const char	*end;
	char		*str;
	char		*ret;

	end = s;
	while (*s == '\n' || *s == ' ' || *s == '\t')
		s++;
	while (*end)
		end++;
	if (end != s)
	{
		while (*--end == '\n' || *end == ' ' || *end == '\t')
			;
		end++;
	}
	str = (char *)malloc(sizeof(char) * ((end - s) + 1));
	if (!str)
		return (NULL);
	ret = str;
	while (s != end)
		*str++ = *s++;
	*str = '\0';
	return (ret);
}
