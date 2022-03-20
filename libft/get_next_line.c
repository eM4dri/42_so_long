/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:55:38 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 19:49:23 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*join;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = ft_calloc(sizeof(char), len);
	if (!join)
		return (0);
	ft_strlcat(join, s1, len);
	ft_strlcat(join, s2, len);
	free(s1);
	return (join);
}

static int	get_next_line2(int readable, char **s, char **line)
{
	char	*str_aux;
	char	*strchr_n;

	if (readable < 0)
		return (-1);
	else if (readable == 0 && !*s)
		return (0);
	strchr_n = ft_strchr(*s, '\n');
	if (strchr_n)
	{
		*line = ft_substr(*s, 0, strchr_n - *s);
		str_aux = ft_strdup(strchr_n + 1);
		free(*s);
		*s = str_aux;
		return (1);
	}
	*line = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[FD_SETSIZE];
	char		*buff;
	int			readable;

	if (!line || fd < 0 || fd > FD_SETSIZE)
		return (-1);
	buff = malloc(sizeof(char));
	readable = read(fd, buff, 1);
	while (readable >= 0)
	{
		buff[readable] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
			s[fd] = ft_strjoin_free(s[fd], buff);
		if (ft_strchr(s[fd], '\n') || readable < 1)
			break ;
		readable = read(fd, buff, 1);
	}
	free(buff);
	return (get_next_line2(readable, &s[fd], line));
}
