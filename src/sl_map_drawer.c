/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:18:50 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/06 16:21:08 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define RED_COLOR 0x00FF0000

// static void	draw_lines_sky(t_game *g, char *str, int nbr_line, int pixel)
// {
// 	// int		odd;
// 	// size_t	len;
// 	void	*img;

// 	(void)str;
// 	// odd = nbr_line;
// 	// pixel = g->save % (2 * WIDTH) - 2 * WIDTH;
// 	// len = ft_strlen(str) + 2;
// 	// while (len-- && ++odd)
// 	// {
// 		img = g->envimgs[SKY];
// 		// if (odd % 2 && nbr_line % 2)
// 		// 	img = g->imgs[SKY_BR];
// 		// else if (nbr_line % 2)
// 		// 	img = g->imgs[SKY_BL];
// 		// else if (odd % 2)
// 		// 	img = g->imgs[SKY_TL];
// 		// else
// 		// 	img = g->imgs[SKY_TR];
// 		mlx_image_to_window(g->mlx, img, -g->map_width, nbr_line * HEIGHT);
// 		// mlx_put_image_to_window(g->mlx, g->win, img, pixel, nbr_line * HEIGHT);
// 		// str++;
// 		// pixel += WIDTH;
// 	// }
// }

static void	draw_lines_map(t_game *g, char *str, int nbr_line, double pixel)
{
	int			odd;
	mlx_image_t	*img;

	odd = nbr_line;
	while (*str != '\0' && ++odd)
	{
		if (*str != '1' || !FLY)
		{
			if (odd % 2)
				img = g->envimgs[ODD_TERRAIN];
			else
				img = g->envimgs[PAIR_TERRAIN];
			mlx_image_to_window(g->mlx, img, pixel * WIDTH, nbr_line * HEIGHT);
			mlx_set_instance_depth(img->instances, 1);
			
			// mlx_put_image_to_window(g->mlx, g->win, img, pixel * WIDTH, nbr_line * HEIGHT);
		}
		str++;
		pixel++;
	}
}

// static char	*ft_strjoin_free_both(char *s1, char *s2)
// {
// 	char	*join;
// 	size_t	len;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	join = ft_calloc(sizeof(char), len);
// 	if (!join)
// 		return (0);
// 	ft_strlcat(join, s1, len);
// 	ft_strlcat(join, s2, len);
// 	free(s1);
// 	free(s2);
// 	return (join);
// }

// static void	print_moves_and_carrots(t_game *g)
// {
// 	char	*str;

// 	mlx_put_image_to_window(g->mlx, g->win, g->imgs.black, 0, 0);
// 	str = ft_strjoin_free_both(ft_strdup("Moves: "), ft_itoa(g->moves));
// 	mlx_string_put(g->mlx, g->win, WIDTH / 2, 0, RED_COLOR, str);
// 	free(str);
// 	str = ft_strjoin_free_both(ft_strdup("Carrots: "), ft_itoa(g->carrots));
// 	mlx_string_put(g->mlx, g->win, WIDTH / 2, HEIGHT / 2, RED_COLOR, str);
// 	free(str);
// 	printf("\tmoves: %d\tcarrots: %d\n", g->moves, g->carrots);
// }

void	draw_map(t_game *g, int is_key_input)
{
	int		carrots;

	if (is_key_input)
	{
		if (DELAY_MULTIPLIER)
			g->clock = CLOCKTICKS * DELAY_MULTIPLIER;
		carrots = count_colectables(g->maps[ITEMS_MAP], 'C');
		if (g->carrots != carrots)
		{
			g->carrots = count_colectables(g->maps[ITEMS_MAP], 'C');
			clean_carrots(&g->maps[ENEMIES_MAP], g->maps[ITEMS_MAP]);
		}
		// print_moves_and_carrots(g);
		g->rabbits = count_colectables(g->maps[ITEMS_MAP], 'P');
	}
	if (!is_key_input || !DELAY_MULTIPLIER)
		g->save += PIXFOWARD;
	if ((FLY && !PERFORMANCE) || (PERFORMANCE && !g->drawn))
		mlx_image_to_window(g->mlx,  g->envimgs[SKY],- 2*WIDTH, 0);
		// ft_draw(g, g->maps[ITEMS_MAP], draw_lines_sky);
	ft_draw(g, g->maps[ITEMS_MAP], draw_lines_map);
	ft_draw(g, g->maps[ITEMS_MAP], draw_lines_objects_enemies);
	printf("sky %d\tterrain1 %d\tterrain2 %d\n", g->envimgs[SKY]->instances->z, \
	g->envimgs[PAIR_TERRAIN]->instances->z, g->envimgs[ODD_TERRAIN]->instances->z);
	printf("count1 %d\tcount2 %d\n",g->envimgs[PAIR_TERRAIN]->count, g->envimgs[ODD_TERRAIN]->count);
}

