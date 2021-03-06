/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:20:46 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 09:35:21 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Copy a map src into map dts
 * @param dts	map dts
 * @param src	map src
*/
void	ft_copymap(t_map_lines **dts, t_map_lines *src)
{
	char	*line;

	line = NULL;
	while (src != NULL)
	{
		line = ft_strdup(src->str);
		ft_lstadd_back_line(dts, line);
		src = src->next;
	}
}

/**
 * * Creates a map (width x height) full of ceros
 * @param map   	map
 * @param width 	map width
 * @param height    map height
*/
void	ft_emptymap(t_map_lines **map, int width, int height)
{
	char	*line;

	line = NULL;
	line = ft_substr(FULL_ZEROS_STRING, 0, width);
	while (height--)
		ft_lstadd_back_line(map, ft_strdup(line));
	free(line);
}

/**
 * * Compare two maps returning a map with diferences to print from empty map
 * @param map	map
 * @param m1	map m1
 * @param m2	map m2
*/
void	ft_comparemaps(t_map_lines **dts, t_map_lines *m1, t_map_lines *m2)
{
	t_map_lines	*aux;
	t_map_lines	*prev;
	int			i;

	prev = *dts;
	while (m1 != NULL || m2 != NULL)
	{
		i = 0;
		aux = prev->next;
		while (m1->str[i] != '\0' || m2->str[i] != '\0')
		{
			if (m1->str[i] != m2->str[i])
				aux->str = ft_replace(aux->str, "1", i);
			if (m1->str[i] != m2->str[i] && !PERFORMANCE)
				prev->str = ft_replace(prev->str, "1", i);
			i++;
		}
		m1 = m1->next;
		m2 = m2->next;
		prev = prev->next;
	}
}

/**
 * * Check rabbit survive, checking PJ's imap have coincidences with enemy's emap
 * @param imap	items map
 * @param emap	enemies map
*/
void	rabbit_survive(t_map_lines **imap, t_map_lines *emap)
{
	t_map_lines	*aux;
	int			i;

	aux = *imap;
	while (emap != NULL || aux != NULL)
	{
		i = 0;
		while (emap->str[i] != '\0' || aux->str[i] != '\0')
		{
			if (ft_strchr("HhVvXx", emap->str[i]) && aux->str[i] == 'P')
			{
				if (!KILL_ALL_RABBITS)
					aux->str = ft_replace(aux->str, "K", i);
				else
					ft_replace_all(imap, 'P', "K");
			}
			i++;
		}
		aux = aux->next;
		emap = emap->next;
	}
}

/**
 * * Clean emap's carrots, from imap
 * @param emap	enemies map
 * @param imap	items map
*/
void	clean_carrots(t_map_lines **emap, t_map_lines *imap)
{
	t_map_lines	*aux;
	int			i;

	aux = *emap;
	while (imap != NULL || aux != NULL)
	{
		i = 0;
		while (imap->str[i] != '\0' || aux->str[i] != '\0')
		{
			if (imap->str[i] != 'C' && aux->str[i] == 'C')
				aux->str = ft_replace(aux->str, "0", i);
			i++;
		}
		aux = aux->next;
		imap = imap->next;
	}
}
