/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:24:00 by gcourrie          #+#    #+#             */
/*   Updated: 2016/02/18 15:16:40 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa_base(long long n, int base, int cap)
{
	int			size;
	long long	tmp;
	char		*str;
	static char	b_min[36] = {"0123456789abcdefghijklmnopqrstuvwxyz"};
	static char	b_maj[36] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	size = n <= 0 ? 1 : 0;
	tmp = n;
	while (tmp / base != 0)
		tmp = (size++ >= 0) ? tmp / base : tmp / base;
	str = ft_strnew(size + 1);
	if (n == 0 && (str[0] = '0'))
		return (str);
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[size--] = cap == 0 ? b_min[ABS(n % base)] : b_maj[ABS(n % base)];
		n /= base;
	}
	return (str);
}
