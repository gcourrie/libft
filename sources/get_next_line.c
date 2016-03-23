/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:20:37 by gcourrie          #+#    #+#             */
/*   Updated: 2016/03/23 18:19:18 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/libft.h"

static char		*no_bsn(int fd, int *i, char *stackbuffer)
{
	char		*buffer;
	int			ret;

	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
	{
		*i = 0;
		return (NULL);
	}
	ret = read(fd, buffer, BUFF_SIZE);
	if (ret <= 0)
	{
		*i = 0;
		if (stackbuffer != NULL)
			*i = 1;
		free(buffer);
		if (ret == -1)
			*i = -1;
		return (NULL);
	}
	buffer[ret] = '\0';
	return (buffer);
}

static char		*found_bsn(char *stackbuffer, int i, char *buffer)
{
	char			*s2;

	if (stackbuffer == NULL)
		return (NULL);
	if (buffer == NULL)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen(stackbuffer) - i + 1));
	if (!s2)
		return (NULL);
	ft_strncpy(buffer, stackbuffer, i);
	ft_strcpy(s2, stackbuffer + i + 1);
	free(stackbuffer);
	if (s2[0] == '\0')
	{
		free(s2);
		s2 = NULL;
	}
	return (s2);
}

static int		check_bsn(char *stackbuffer)
{
	int			i;

	i = 0;
	if (!stackbuffer)
		return (-1);
	while (stackbuffer[i] != '\n' && stackbuffer[i])
		i++;
	if (stackbuffer[i] != '\n')
		return (-1);
	return (i);
}

static char		*malloc_2_string(char *s1, char *s2)
{
	char		*tot;

	if (s1 && !s2)
		return (s1);
	if (s2 && !s1)
		return (s2);
	if (!s1 && !s2)
		return (NULL);
	tot = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tot)
		return (NULL);
	ft_strcpy(tot, s1);
	ft_strcpy(tot + ft_strlen(s1), s2);
	free(s1);
	free(s2);
	return (tot);
}

int				get_next_line(int fd, char **line)
{
	static char	*stackbuffer;
	int			i;

	i = -1;
	if (fd < 0 || !line)
		return (-1);
	while (i == -1)
	{
		if ((i = check_bsn(stackbuffer)) != -1)
		{
			if (!(*line = ft_memalloc(i + 1)))
				return (-1);
			stackbuffer = found_bsn(stackbuffer, i, *line);
			return (1);
		}
		if ((*line = no_bsn(fd, &i, stackbuffer)) == NULL)
		{
			*line = stackbuffer;
			stackbuffer = NULL;
			return (i);
		}
		stackbuffer = malloc_2_string(stackbuffer, *line);
	}
	return (1);
}
