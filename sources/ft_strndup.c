/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 22:16:29 by gcourrie          #+#    #+#             */
/*   Updated: 2016/02/15 22:27:11 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strndup(const char *str, int n, int i)
{
	char	*ret;
	char	*tmp;

	if (n >= i)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (i - n + 1))))
		return (NULL);
	tmp = ret;
	while (n < i && str[n])
		*tmp++ = str[n++];
	*tmp = '\0';
	return (ret);
}
