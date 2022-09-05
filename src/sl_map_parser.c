/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:21:43 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/05 23:40:31 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Add new line into list at back
 * @param map	map
 * @param line	new line to link
*/
void	ft_lstadd_back_line(t_map_lines **map, char *line)
{
	t_map_lines	*new;
	t_map_lines	*aux;

	new = malloc(sizeof(t_map_lines));
	if (!new)
	{
		ft_freemap(*map);
		free(line);
		exit(ENOMEM);
	}
	new->str = line;
	new->next = NULL;
	if (*map == NULL)
		*map = new;
	else
	{
		aux = *map;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

/**
 * * Validates map is closed, map has to be surrounded by walls
 * @param map	map
*/
static int	check_closed_map(t_map_lines *map)
{
	t_map_lines	*aux;
	char		*line;

	aux = map;
	while (aux != NULL)
	{
		line = aux->str;
		while (*line != '\0')
		{
			if ((aux->next == map->next || aux->next == NULL) && *line != '1')
				return (0);
			else if (aux->next != map->next && aux->next != NULL)
			{
				if ((aux->str == line || *(line + 1) == '\0') && *line != '1')
					return (0);
			}
			line++;
		}
		aux = aux->next;
	}
	return (1);
}

/**
 * * Validates map has at least one start, one exit and one collectable
 * * Validates map's allowed cells (characters) and shape (line sizes)
 * @param map	map
*/
static int	check_valid_map(t_map_lines *map)
{
	t_map_lines		*aux;
	char			*line;
	t_map_objects	o;
	size_t			len;

	o.exit = 0;
	o.start = 0;
	o.item = 0;
	aux = map;
	len = ft_strlen(aux->str);
	while (aux != NULL)
	{
		line = aux->str;
		while (*line != '\0')
		{
			if (!ft_strchr(VALIDCELLS, *line) || len != ft_strlen(aux->str))
				return (0);
			o.item += (*line == 'C');
			o.exit += (*line == 'E');
			o.start += (*line == 'P');
			line++;
		}
		aux = aux->next;
	}
	return (o.item && o.exit && o.start);
}

// void	pre_map_exit(t_map_lines *map, const char *str, int free_needed)
// {
// 	if (free_needed)
// 		ft_freemap(map);
// 	printf(ERROR, str);
// 	exit(0);
// }

void	parse_map(char *file, t_map_lines **map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		pre_map_exit(*map, strerror(EBADF), 0);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (!ft_strlen(line))
			pre_map_exit(*map, ERROR_VALIDMAP, 1);
		ft_lstadd_back_line(map, line);
	}
	ft_lstadd_back_line(map, line);
	if (!check_closed_map(*map) || !check_valid_map(*map))
		pre_map_exit(*map, ERROR_VALIDMAP, 1);
	if (ft_strlen(line) > MAXWIDTH || get_map_height(*map) > MAXHEIGHT)
		pre_map_exit(*map, ERROR_MAXDIMENSIONS, 1);
	if (close(fd) < 0 && fd != -1)
		pre_map_exit(*map, strerror(EBADF), 1);
}
