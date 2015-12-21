/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:05:01 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:44:56 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int						ft_strcmp(const char *s1, const char *s2)
{
	const char	*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	while (*str1 && *str1 == *str2)
	{
		str2++;
		str1++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
