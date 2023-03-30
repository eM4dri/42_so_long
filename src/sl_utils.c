/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:20:25 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 09:35:20 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Replace a set of characters on a string starting at some index
 * @param str		string to modify 
 * @param charset	set of characters to replace
 * @param index		starting point of replacing
*/
char	*ft_replace(char *str, char const *charset, size_t index)
{
	char	*out;
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(str);
	out = malloc(sizeof(char) * (len + 1));
	while (str[++i] != '\0')
		out[i] = str[i];
	out[i] = '\0';
	i = -1;
	while (charset[++i] != '\0')
		out[index + i] = charset[i];
	free(str);
	return (out);
}

/**
 * * Replace a set of characters on a string starting at some index
 * @param str		string to modify 
 * @param charset	set of characters to replace
 * @param index		starting point of replacing
*/
void ft_replace_this_charset(char **str, char const *charset)
{
	char 	*aux;
	size_t	i;

	aux = *str; 
	i = 0;
	while (charset[i])
	{
		aux[i] = charset[i];
		i++;
	}
}

/**
 * * Free map
 * @param map	map
*/
void	ft_freemap(t_map_lines *map)
{
	t_map_lines	*next;
	t_map_lines	*aux;

	next = map;
	aux = map;
	while (next != NULL)
	{
		next = next->next;
		free(aux->str);
		free(aux);
		aux = next;
	}
}

/**
 * * Print map
 * @param map	map
*/
void	ft_printmap(t_map_lines *map)
{
	while (map != NULL)
	{
		printf("%s\n", map->str);
		map = map->next;
	}
}

/**
 * * get_map_height
 * @param map	map
*/
int	get_map_height(t_map_lines *map)
{
	int	height;

	height = 0;
	while (map != NULL)
	{
		map = map->next;
		height++;
	}
	return (height);
}

/**
 * * count_colectables
 * @param map	map
*/
int	count_colectables(t_map_lines *map, char c)
{
	int		total;
	char	*str;

	total = 0;
	while (map != NULL)
	{
		str = map->str;
		while (*str != '\0')
		{
			if (*str++ == c)
				total++;
		}
		map = map->next;
	}
	return (total);
}
