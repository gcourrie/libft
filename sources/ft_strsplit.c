/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:13:50 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:48:36 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_strtrim_c(const char *s, char c)
{
	const char	*end;
	char		*str;
	char		*ret;

	end = s;
	while (*s == c)
		s++;
	while (*end)
		end++;
	if (end != s)
	{
		while (*--end == c)
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

static void		put_in_table(char *s1, char **tab, int tablen, char c)
{
	char		*s2;

	s2 = s1;
	while (tablen--)
	{
		s1 = s2;
		while (*s2 != c && *s2)
			s2++;
		*tab = ft_strsub(s1, 0, s2 - s1);
		while (*s2 == c && *s2)
			s2++;
		tab++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	*s1;
	char	*s2;
	char	**tab;
	int		tablen;

	tablen = 0;
	s1 = ft_strtrim_c(s, c);
	s2 = s1;
	while (*s2)
	{
		tablen++;
		while (*s2 != c && *s2)
			s2++;
		while (*s2 == c && *s2)
			s2++;
	}
	tab = (char **)malloc(sizeof(char *) * (tablen + 1));
	if (!tab)
		return (NULL);
	tab[tablen] = NULL;
	put_in_table(s1, tab, tablen, c);
	free(s1);
	return (tab);
}
