/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_drawer2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:18:54 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/05 21:55:14 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#  define ENEMYCELLS "XxVvHh"

// static void	draw_lines_enemies(t_game *g, char *str, int nbr_line, int pixel)
// {
// 	void	*img;

// 	while (*str != '\0')
// 	{
// 		if (*str == 'X' || *str == 'x' || *str == 'H' || *str == 'h'
// 		|| *str == 'V' || *str == 'v')
// 		if (ft_strchr(ENEMYCELLS, *str))
// 		{
// 			if (*str == 'X')
// 				img = g->imgs[SPIKES_U];
// 			else if (*str == 'x')
// 				img = g->imgs[SPIKES_D];
// 			else if (*str == 'H')
// 				img = g->imgs[RAT_L];
// 			else if (*str == 'h')
// 				img = g->imgs[RAT_R];
// 			else if (*str == 'V')
// 				img = g->imgs[FOX_U];
// 			else
// 				img = g->imgs[FOX_D];
// 			mlx_image_to_window(g->mlx, img, pixel * WIDTH,
// 				(nbr_line - !PERFORMANCE) * HEIGHT);
// 			// mlx_put_image_to_window(g->mlx, g->win, img, pixel * WIDTH, (nbr_line - !PERFORMANCE) * HEIGHT);
// 		}
// 		str++;
// 		pixel++;
// 	}
// }

static void	*get_img_object(t_game *g, char *str)
{
	if (*str == 'C')
		return (g->envimgs[CARROT]);
	else if (*str == 'E')
		return (g->envimgs[HOLE]);
	// else if (*str == 'K')
	// 	return (g->envimgs[HOLE]);
	// else if (g->lastkey == LEFT || g->lastkey == A_KEY)
	// 	return (g->imgs[RABBIT_L]);
	// else if (g->lastkey == RIGHT || g->lastkey == D_KEY)
	// 	return (g->imgs[RABBIT_R]);
	// else if (g->lastkey == UP || g->lastkey == W_KEY)
	// 	return (g->imgs[RABBIT_U]);
	else
		return (g->players[0].img);
		// return (g->envimgs[RABBIT_D]);
}

static void	draw_lines_objects(t_game *g, char *str, int nbr_line, double pixel)
{
	void	*img;

	while (*str != '\0')
	{
		if (*str == 'C' || *str == 'E' || *str == 'P' || *str == 'K')
		{
			img = get_img_object(g, str);
			mlx_image_to_window(g->mlx, img, pixel * WIDTH , \
				(nbr_line - (ft_strchr("CPK", *str) && !PERFORMANCE)) * HEIGHT);
			// mlx_put_image_to_window(v->mlx, v->win, img, pixel * WIDTH, (nbr_line - (ft_strchr("CPK", *str) && !PERFORMANCE)) * HEIGHT);
		}
		str++;
		pixel++;
	}
}

void	draw_lines_objects_enemies(t_game *v, char *str, int nbr_line, \
		double pixel)
{
	t_map_lines	*emap;
	int			i;

	emap = v->maps[ENEMIES_MAP];
	i = nbr_line - 2;
	while (i--)
		emap = emap->next;
	// draw_lines_enemies(v, emap->str, nbr_line, pixel);
	draw_lines_objects(v, str, nbr_line, pixel);
}

void	ft_draw(t_game *vars, t_map_lines *map, \
				void (*func)(t_game *, char *, int, double))
{
	int	nbr_line;
	double	pixel;

	nbr_line = 0;
	pixel = -0.5;
	while (map != NULL)
	{
		func(vars, map->str, nbr_line, pixel);
		map = map->next;
		nbr_line++;
	}
}

