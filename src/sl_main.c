/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:29:57 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/09 09:53:28 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_vars		v;

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
