/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:46:04 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:48:03 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (*s1 && *s2 && --n)
		if (*s1++ != *s2++)
			return (0);
	if (*s1 == *s2)
		return (1);
	return (0);
}
