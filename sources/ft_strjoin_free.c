/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 22:30:11 by gcourrie          #+#    #+#             */
/*   Updated: 2016/02/15 22:34:41 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (s1 && !s2)
		return (s1);
	if (!s1 && s2)
		return (s2);
	if (!s1 && !s2)
		return (NULL);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}
