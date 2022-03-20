/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_drawer2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:18:54 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/24 08:31:12 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_lines_enemies(t_vars *v, char *str, int nbr_line, int pixel)
{
	while (*str != '\0')
	{
		if (*str == 'X' || *str == 'x' || *str == 'H' || *str == 'h' \
		|| *str == 'V' || *str == 'v')
		{
			if (*str == 'X')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, SPIKES_U);
			else if (*str == 'x')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, SPIKES_D);
			else if (*str == 'H')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RAT_L);
			else if (*str == 'h')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RAT_R);
			else if (*str == 'V')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, FOX_U);
			else if (*str == 'v')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, FOX_D);
			mlx_put_image_to_window(v->mlx, v->win, v->img, pixel * WIDTH, \
			(nbr_line - !PERFORMANCE) * HEIGHT);
			mlx_destroy_image(v->mlx, v->img);
		}
		str++;
		pixel++;
	}
}

static void	draw_lines_objects(t_vars *v, char *str, int nbr_line, int pixel)
{
	while (*str != '\0')
	{
		if (*str == 'C' || *str == 'E' || *str == 'P' || *str == 'K')
		{
			if (*str == 'K')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RABBIT_KO);
			else if (*str == 'C')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, CARROT);
			else if (*str == 'E')
				v->img = ft_mlx_xpm_file_to_image(v->mlx, HOLE);
			else if (v->lastkey == LEFT || v->lastkey == A_KEY)
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RABBIT_L);
			else if (v->lastkey == RIGHT || v->lastkey == D_KEY)
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RABBIT_R);
			else if (v->lastkey == UP || v->lastkey == W_KEY)
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RABBIT_U);
			else
				v->img = ft_mlx_xpm_file_to_image(v->mlx, RABBIT_D);
			mlx_put_image_to_window(v->mlx, v->win, v->img, pixel * WIDTH, \
			(nbr_line - (ft_strchr("CPK", *str) && !PERFORMANCE)) * HEIGHT);
			mlx_destroy_image(v->mlx, v->img);
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

/**
 * * In spite of being mandatory mlx_xpm_file_to_image don´t use height & width
 * * So this 'overrides' save handling that parameter
 * @param mlx
 * @param filename
*/
void	*ft_mlx_xpm_file_to_image(void *mlx, char *filename)
{
	int	a;

	a = 0;
	return (mlx_xpm_file_to_image(mlx, filename, &a, &a));
}
