/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:20:46 by emadriga          #+#    #+#             */
/*   Updated: 2023/04/03 18:31:11 by emadriga         ###   ########.fr       */
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
 * * Check rabbit survive, checking PJ's imap have coincidences with enemy's emap
 * @param imap	items map
 * @param emap	enemies map
*/
void	rabbit_survive(t_map_lines **imap, t_map_lines *emap)
{
	t_map_lines	*aux;
	char		*player;
	char		*enemies;

	aux = *imap;
	while (aux->next != NULL && emap->next != NULL)
	{
		player = aux->str;
		enemies = emap->str;
		while (*player != '\0' || *enemies != '\0')
		{
			if (ft_strchr("HhVvXx", *enemies) && *player == 'P')
			{
				if (!KILL_ALL_RABBITS)
					*player = 'K';
				else
					ft_replace_all_chars(imap, 'P', 'K');
			}
			player++;
			enemies++;
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
	char		*items;
	char		*enemies;

	aux = *emap;
	while (imap != NULL || aux != NULL)
	{
		enemies = aux->str;
		items = imap->str;
		while (*items != '\0' || *enemies != '\0')
		{
			if (*items != 'C' && *enemies == 'C')
				*enemies = '0';
			enemies++;
			items++;
		}
		aux = aux->next;
		imap = imap->next;
	}
}
