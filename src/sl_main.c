/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:29:57 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/08 19:32:41 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pre_map_exit(t_map_lines *map, const char *str, int free_needed)
{
	if (free_needed)
		ft_freemap(map);
	printf(ERROR, str);
	exit(0);
}

// static void	create_images(t_vars *v, int a)
// {
// 	v->imgs[CARROT] = mlx_load_png;
// 	v->imgs.hole = mlx_xpm_file_to_image(v->mlx, HOLE, &a, &a);
// 	v->imgs.rabbit_down = mlx_xpm_file_to_image(v->mlx, RABBIT_D, &a, &a);
// 	v->imgs.rabbit_ko = mlx_xpm_file_to_image(v->mlx, RABBIT_KO, &a, &a);
// 	v->imgs.rabbit_left = mlx_xpm_file_to_image(v->mlx, RABBIT_L, &a, &a);
// 	v->imgs.rabbit_right = mlx_xpm_file_to_image(v->mlx, RABBIT_R, &a, &a);
// 	v->imgs.rabbit_up = mlx_xpm_file_to_image(v->mlx, RABBIT_U, &a, &a);
// 	v->imgs.spikes_down = mlx_xpm_file_to_image(v->mlx, SPIKES_D, &a, &a);
// 	v->imgs.spikes_up = mlx_xpm_file_to_image(v->mlx, SPIKES_U, &a, &a);
// 	v->imgs.fox_down = mlx_xpm_file_to_image(v->mlx, FOX_D, &a, &a);
// 	v->imgs.fox_up = mlx_xpm_file_to_image(v->mlx, FOX_U, &a, &a);
// 	v->imgs.rat_left = mlx_xpm_file_to_image(v->mlx, RAT_L, &a, &a);
// 	v->imgs.rat_right = mlx_xpm_file_to_image(v->mlx, RAT_R, &a, &a);
// 	v->imgs.odd_terrain = mlx_xpm_file_to_image(v->mlx, ODD, &a, &a);
// 	v->imgs.pair_terrain = mlx_xpm_file_to_image(v->mlx, PAIR, &a, &a);
// 	v->imgs.wall = mlx_xpm_file_to_image(v->mlx, WALL, &a, &a);
// 	v->imgs.black = mlx_xpm_file_to_image(v->mlx, BLACK, &a, &a);
// 	v->imgs.sky_br = mlx_xpm_file_to_image(v->mlx, SKY_BR, &a, &a);
// 	v->imgs.sky_bl = mlx_xpm_file_to_image(v->mlx, SKY_BL, &a, &a);
// 	v->imgs.sky_tl = mlx_xpm_file_to_image(v->mlx, SKY_TL, &a, &a);
// 	v->imgs.sky_tr = mlx_xpm_file_to_image(v->mlx, SKY_TR, &a, &a);
// }

static void	load_maps(t_game *game, t_map_lines *loaded_map)
{
	(void) loaded_map;
	game->items_maps = NULL;
	game->enemies_maps = NULL;
	game->items_maps = ft_copymap_matrix(game->loadedMap, game->map_height);
	if (!game->items_maps)
		exit(1);
	if (ENEMIES)
	{
		ft_replace_all_matrix(game->items_maps, 'X', '0');
		ft_replace_all_matrix(game->items_maps, 'H', '0');
		ft_replace_all_matrix(game->items_maps, 'V', '0');
		ft_replace_all_matrix(game->items_maps, 'x', '0');
		ft_replace_all_matrix(game->items_maps, 'h', '0');
		ft_replace_all_matrix(game->items_maps, 'v', '0');
		game->enemies_maps = ft_copymap_matrix(game->loadedMap, game->map_height);
		if (!game->items_maps)
			exit(1);
		ft_replace_all_matrix(game->enemies_maps, 'P', '0');
	}
}

static void	init_vars(t_game *g)
{
	g->moves = 0;
	g->lastkey = 1;
	g->save = 0;
	g->drawn = 0;
	g->clock = CLOCKTICKS;	
	g->map_height = get_map_height(g->loadedMap);
	load_maps(g, g->loadedMap);
	g->rabbits = count_colectables(g->items_maps, 'P');

	g->players = NULL;
	g->players = (t_player **) malloc((g->rabbits + 1) * sizeof(t_player *));
	g->players[g->rabbits] = NULL;
	g->map_width = ft_strlen(g->loadedMap->str);
	g->win_width = g->map_width * WIDTH;
	g->win_height = (g->map_height) * HEIGHT;
	g->mlx = mlx_init(g->win_width - WIDTH, g->win_height, WINDOW_TITLE, false);

	g->enemy_clock = CLOCKENEMIES;
	g->enemy_clock_watch = CLOCKWATCH;
	// game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, window_tittle);
	load_images(g, g->loadedMap);
}

// void	ft_leaks(void)
// {
// 	system("leaks parse");
// }
// #define LEAKS  0

/**
 * @brief Checks either one of the given keys is being pressed.
 *
 * @param k1 First key.
 * @param k1 Second key.
 * @param game Game to check.
 * @return int 1 if true. Else 0.
 */
// static int	either_key_pressed(keys_t k1, keys_t k2, t_game *g)
// {
// 	if (mlx_is_key_down(g->mlx, k1))
// 		return (1);
// 	if (mlx_is_key_down(g->mlx, k2))
// 		return (1);
// 	return (0);
// }

/**
 * @brief Handles the key press event.
 *
 * @param game Game structure.
 * @return int Value to return for the mlx function.
 */
void	game_tick(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	// if (either_key_pressed(MLX_KEY_W, MLX_KEY_S, g)  || either_key_pressed(MLX_KEY_A, MLX_KEY_D, g))
	// {
	// 	g->moves++;
	// 	if (!CLOCKENEMIES)
	// 	{
	// 		animate_enemies(&g->maps[ENEMIES_MAP], &g->enemy_clock_watch);
	// 		rabbit_survive(&g->maps[ITEMS_MAP], g->maps[ENEMIES_MAP]);
	// 	}
	// 	if (either_key_pressed(MLX_KEY_W, MLX_KEY_UP, g))
	// 		try_move_up(&g->maps[ITEMS_MAP], g->carrots);
	// 	else if (either_key_pressed(MLX_KEY_S, MLX_KEY_DOWN, g))
	// 		try_move_down(&g->maps[ITEMS_MAP], g->carrots);
	// 	else if (either_key_pressed(MLX_KEY_A, MLX_KEY_LEFT, g))
	// 		try_move_left(&g->maps[ITEMS_MAP], g->carrots);
	// 	else if (either_key_pressed(MLX_KEY_D, MLX_KEY_RIGHT, g))
	// 		try_move_right(&g->maps[ITEMS_MAP], g->carrots);
	// 	draw_map(g, 1);
	// }

	// rabbit_survive(&g->maps[ITEMS_MAP], g->maps[ENEMIES_MAP]);
	if (!g->tick--)
	{
		g->envimgs[SKY]->instances->x -= 2* WIDTH;
		g->tick =  2 * WIDTH * BACKGROUND_MOVE_FACTOR;
	}
	else if (!(g->tick % BACKGROUND_MOVE_FACTOR))
		g->envimgs[SKY]->instances->x += 1;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		close_window(g);
}

int	main(int argc, char **argv)
{
	t_game		game;

	// if (LEAKS)
	// 	atexit(ft_leaks);
	game.loadedMap = NULL;
	game.tick = 2 * WIDTH * BACKGROUND_MOVE_FACTOR;
	if (argc != 2)
		pre_map_exit(game.loadedMap, strerror(EINVAL), 0);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		pre_map_exit(game.loadedMap, ERROR_EXTENSIONMAP, 0);
	parse_map(argv[1], &game.loadedMap);
	ft_printmap(game.loadedMap);
	printf("HYE1\n");
	init_vars(&game);
	// init_maps(&game);
	printf("HYE\n");
	draw_map(&game, 0);
	game.drawn = 1;
	mlx_key_hook(game.mlx, key_hook, &game);
	// mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	// if ((FLY && !PERFORMANCE) || (CLOCKENEMIES > 0))
	mlx_loop_hook(game.mlx, game_tick, &game);
	mlx_loop(game.mlx);
}
