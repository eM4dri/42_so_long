/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_drawer2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:18:54 by emadriga          #+#    #+#             */
/*   Updated: 2023/04/03 18:08:16 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_lines_enemies(t_vars *v, char *str, int nbr_line, int pixel)
{
	void	*img;

	while (*str != '\0')
	{
		if (*str == 'X' || *str == 'x' || *str == 'H' || *str == 'h' \
		|| *str == 'V' || *str == 'v')
		{
			if (*str == 'X')
				img = v->imgs.spikes_up;
			else if (*str == 'x')
				img = v->imgs.spikes_down;
			else if (*str == 'H')
				img = v->imgs.rat_left;
			else if (*str == 'h')
				img = v->imgs.rat_right;
			else if (*str == 'V')
				img = v->imgs.fox_up;
			else if (*str == 'v')
				img = v->imgs.fox_down;
			mlx_put_image_to_window(v->mlx, v->win, img, pixel * WIDTH, \
				(nbr_line - !PERFORMANCE) * HEIGHT);
		}
		str++;
		pixel++;
	}
}

static void	*get_img_object(t_vars *v, char *str)
{
	if (*str == 'K')
		return (v->imgs.rabbit_ko);
	else if (*str == 'C')
		return (v->imgs.carrot);
	else if (*str == 'E')
		return (v->imgs.hole);
	else if (v->lastkey == LEFT || v->lastkey == A_KEY)
		return (v->imgs.rabbit_left);
	else if (v->lastkey == RIGHT || v->lastkey == D_KEY)
		return (v->imgs.rabbit_right);
	else if (v->lastkey == UP || v->lastkey == W_KEY)
		return (v->imgs.rabbit_up);
	else
		return (v->imgs.rabbit_down);
}

static void	draw_lines_objects(t_vars *v, char *str, int nbr_line, int pixel)
{
	void	*img;

	while (*str != '\0')
	{
		if (*str == 'C' || *str == 'E' || *str == 'P' || *str == 'K')
		{
			img = get_img_object(v, str);
			mlx_put_image_to_window(v->mlx, v->win, img, pixel * WIDTH, \
				(nbr_line - (ft_strchr("CPK", *str) && !PERFORMANCE)) * HEIGHT);
		}
		str++;
		pixel++;
	}
}

void	draw_lines_objects_enemies(t_vars *v, char *str, int nbr_line, \
		int pixel)
{
	t_map_lines	*emap;
	int			i;

	emap = v->emap;
	i = nbr_line - 2;
	while (i--)
		emap = emap->next;
	draw_lines_enemies(v, emap->str, nbr_line, pixel);
	draw_lines_objects(v, str, nbr_line, pixel);
}

void	ft_draw(t_vars *vars, t_map_lines *map, \
				void (*func)(t_vars *, char *, int, int))
{
	int	nbr_line;
	int	pixel;

	nbr_line = 2;
	pixel = 0;
	while (map != NULL)
	{
		func(vars, map->str, nbr_line, pixel);
		map = map->next;
		nbr_line++;
	}
}
