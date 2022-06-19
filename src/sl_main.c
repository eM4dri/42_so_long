/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:29:57 by emadriga          #+#    #+#             */
/*   Updated: 2022/06/19 19:51:33 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_images(t_vars *v, int a)
{
	v->imgs.carrot = mlx_xpm_file_to_image(v->mlx, CARROT, &a, &a);
	v->imgs.hole = mlx_xpm_file_to_image(v->mlx, HOLE, &a, &a);
	v->imgs.rabbit_down = mlx_xpm_file_to_image(v->mlx, RABBIT_D, &a, &a);
	v->imgs.rabbit_ko = mlx_xpm_file_to_image(v->mlx, RABBIT_KO, &a, &a);
	v->imgs.rabbit_left = mlx_xpm_file_to_image(v->mlx, RABBIT_L, &a, &a);
	v->imgs.rabbit_right = mlx_xpm_file_to_image(v->mlx, RABBIT_R, &a, &a);
	v->imgs.rabbit_up = mlx_xpm_file_to_image(v->mlx, RABBIT_U, &a, &a);
	v->imgs.spikes_down = mlx_xpm_file_to_image(v->mlx, SPIKES_D, &a, &a);
	v->imgs.spikes_up = mlx_xpm_file_to_image(v->mlx, SPIKES_U, &a, &a);
	v->imgs.fox_down = mlx_xpm_file_to_image(v->mlx, FOX_D, &a, &a);
	v->imgs.fox_up = mlx_xpm_file_to_image(v->mlx, FOX_U, &a, &a);
	v->imgs.rat_left = mlx_xpm_file_to_image(v->mlx, RAT_L, &a, &a);
	v->imgs.rat_right = mlx_xpm_file_to_image(v->mlx, RAT_R, &a, &a);
	v->imgs.odd_terrain = mlx_xpm_file_to_image(v->mlx, ODD, &a, &a);
	v->imgs.pair_terrain = mlx_xpm_file_to_image(v->mlx, PAIR, &a, &a);
	v->imgs.wall = mlx_xpm_file_to_image(v->mlx, WALL, &a, &a);
	v->imgs.black = mlx_xpm_file_to_image(v->mlx, BLACK, &a, &a);
	v->imgs.sky_br = mlx_xpm_file_to_image(v->mlx, SKY_BR, &a, &a);
	v->imgs.sky_bl = mlx_xpm_file_to_image(v->mlx, SKY_BL, &a, &a);
	v->imgs.sky_tl = mlx_xpm_file_to_image(v->mlx, SKY_TL, &a, &a);
	v->imgs.sky_tr = mlx_xpm_file_to_image(v->mlx, SKY_TR, &a, &a);
}

static void	init_vars(t_vars *v, char *s)
{
	v->moves = 0;
	v->lastkey = 1;
	v->save = 0;
	v->drawn = 0;
	v->clock = CLOCKTICKS;
	v->rabbits = count_colectables(v->map, 'P');
	v->map_width = ft_strlen(v->map->str);
	v->map_height = get_map_height(v->map);
	v->win_width = v->map_width * WIDTH;
	v->win_height = (v->map_height + 4) * HEIGHT;
	v->mlx = mlx_init();
	v->enemy_clock = CLOCKENEMIES;
	v->enemy_clock_watch = CLOCKWATCH;
	v->win = mlx_new_window(v->mlx, v->win_width, v->win_height, s);
	create_images(v, 0);
}

static void	init_maps(t_vars *v)
{
	v->imap = NULL;
	v->emap = NULL;
	ft_copymap(&v->imap, v->map);
	ft_replace_all(&v->imap, 'X', "0");
	ft_replace_all(&v->imap, 'H', "0");
	ft_replace_all(&v->imap, 'V', "0");
	ft_replace_all(&v->imap, 'x', "0");
	ft_replace_all(&v->imap, 'h', "0");
	ft_replace_all(&v->imap, 'v', "0");
	ft_copymap(&v->emap, v->map);
	ft_replace_all(&v->emap, 'P', "0");
}

void	ft_leaks(void)
{
	system("leaks parse");
}
#define LEAKS  0

int	main(int argc, char **argv)
{
	t_vars		v;

	if (LEAKS)
		atexit(ft_leaks);
	v.map = NULL;
	if (argc != 2)
		pre_map_exit(v.map, strerror(EINVAL), 0);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		pre_map_exit(v.map, ERROR_EXTENSIONMAP, 0);
	parse_map(argv[1], &v.map);
	init_vars(&v, argv[1]);
	init_maps(&v);
	draw_map(&v, 0);
	v.drawn = 1;
	mlx_key_hook(v.win, key_hook, &v);
	mlx_hook(v.win, 17, 1L << 17, close_window, &v);
	if ((FLY && !PERFORMANCE) || (CLOCKENEMIES > 0))
		mlx_loop_hook(v.mlx, draw_map_loop, &v);
	mlx_loop(v.mlx);
}
