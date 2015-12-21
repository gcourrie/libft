/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:59:31 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:29:10 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *nptr)
{
	int	nbr;
	int	neg;

	nbr = 0;
	neg = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		nbr *= 10;
		nbr = *nptr - 48 + nbr;
		nptr++;
	}
	if (neg == 1)
		return (-nbr);
	return (nbr);
}
