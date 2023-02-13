/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:47:26 by houaslam          #+#    #+#             */
/*   Updated: 2023/02/11 18:47:52 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_handle(char *buf)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!str)
		return (NULL);
	i++;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free (buf);
	return (str);
}

char	*after(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_check(char *buf, int fd)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	i = 1;
	while (!ft_strchr(buf, '\n') && i != 0)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == -1)
		{
			free(res);
			free(buf);
			return (NULL);
		}
		res[i] = '\0';
		buf = ft_strjoin(buf, res);
	}
	free(res);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_check(buf, fd);
	if (!buf)
		return (NULL);
	line = after(buf);
	buf = ft_handle(buf);
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	c = 0;
	while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[i] = '\0';
	free(s1);
	return (str);
}