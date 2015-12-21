/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:29:44 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 19:18:44 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_itoa_rec(int nbr, char *str)
{
	if (nbr == -2147483648)
	{
		ft_itoa_rec(-21474, str);
		ft_itoa_rec(83648, str + 6);
	}
	if (nbr < 0 && nbr != -2147483648)
	{
		*str = '-';
		ft_itoa_rec(nbr * -1, str + 1);
	}
	if (nbr < 10 && nbr >= 0)
		*str++ = nbr + 48;
	if (nbr >= 10)
	{
		str = ft_itoa_rec(nbr / 10, str);
		str = ft_itoa_rec(nbr % 10, str);
	}
	return (str);
}

char			*ft_itoa(int nbr)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	ft_itoa_rec(nbr, str);
	return (str);
}
