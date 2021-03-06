/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:18:50 by emadriga          #+#    #+#             */
/*   Updated: 2022/06/19 20:04:43 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define RED_COLOR 0x00FF0000

static void	draw_lines_sky(t_vars *v, char *str, int nbr_line, int pixel)
{
	int		odd;
	size_t	len;
	void	*img;

	odd = nbr_line;
	pixel = v->save % (2 * WIDTH) - 2 * WIDTH;
	len = ft_strlen(str) + 2;
	while (len-- && ++odd)
	{
		if (odd % 2 && nbr_line % 2)
			img = v->imgs.sky_br;
		else if (nbr_line % 2)
			img = v->imgs.sky_bl;
		else if (odd % 2)
			img = v->imgs.sky_tl;
		else
			img = v->imgs.sky_tr;
		mlx_put_image_to_window(v->mlx, v->win, img, \
			pixel, nbr_line * HEIGHT);
		str++;
		pixel += WIDTH;
	}
}

static void	draw_lines_map(t_vars *v, char *str, int nbr_line, int pixel)
{
	int		odd;
	void	*img;

	odd = nbr_line;
	while (*str != '\0' && ++odd)
	{
		if (*str != '1' || !FLY)
		{
			if (*str == '1')
				img = v->imgs.wall;
			else if (odd % 2)
				img = v->imgs.odd_terrain;
			else
				img = v->imgs.pair_terrain;
			mlx_put_image_to_window(v->mlx, v->win, img, \
				pixel * WIDTH, nbr_line * HEIGHT);
		}
		str++;
		pixel++;
	}
}

static char	*ft_strjoin_free_both(char *s1, char *s2)
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
	free(s2);
	return (join);
}

static void	print_moves_and_carrots(t_vars *vars)
{
	char	*str;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.black, 0, 0);
	str = ft_strjoin_free_both(ft_strdup("Moves: "), ft_itoa(vars->moves));
	mlx_string_put(vars->mlx, vars->win, WIDTH / 2, 0, RED_COLOR, str);
	free(str);
	str = ft_strjoin_free_both(ft_strdup("Carrots: "), ft_itoa(vars->carrots));
	mlx_string_put(vars->mlx, vars->win, WIDTH / 2, HEIGHT / 2, RED_COLOR, str);
	free(str);
	printf("\tmoves: %d\tcarrots: %d\n", vars->moves, vars->carrots);
}

void	draw_map(t_vars *vars, int is_key_input)
{
	int		carrots;

	if (is_key_input)
	{
		if (DELAY_MULTIPLIER)
			vars->clock = CLOCKTICKS * DELAY_MULTIPLIER;
		carrots = count_colectables(vars->imap, 'C');
		if (vars->carrots != carrots)
		{
			vars->carrots = count_colectables(vars->imap, 'C');
			clean_carrots(&vars->emap, vars->imap);
		}
		print_moves_and_carrots(vars);
		vars->rabbits = count_colectables(vars->imap, 'P');
	}
	if (!is_key_input || !DELAY_MULTIPLIER)
		vars->save += PIXFOWARD;
	if ((FLY && !PERFORMANCE) || (PERFORMANCE && !vars->drawn))
		ft_draw(vars, vars->imap, draw_lines_sky);
	ft_draw(vars, vars->imap, draw_lines_map);
	ft_draw(vars, vars->imap, draw_lines_objects_enemies);
}
