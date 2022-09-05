/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:30:12 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/05 22:43:44 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *g)
{
	int	i;

	if(!g->envimgs)
		return ;
	i = 0;
	while(i < TOTAL_TEXTURES_ENVIROMENT)
		mlx_delete_image(g->mlx, g->envimgs[i++]);

	// mlx_delete_image(g->mlx, g->imgs[CARROT]);
	// mlx_delete_image(g->mlx, g->imgs[HOLE]);
	// mlx_delete_image(g->mlx, g->imgs[RABBIT_D]);
	// mlx_delete_image(g->mlx, g->imgs[RABBIT_KO]);
	// mlx_delete_image(g->mlx, g->imgs[RABBIT_L]);
	// mlx_delete_image(g->mlx, g->imgs[RABBIT_R]);
	// mlx_delete_image(g->mlx, g->imgs[RABBIT_U]);
	// mlx_delete_image(g->mlx, g->imgs[SPIKES_D]);
	// mlx_delete_image(g->mlx, g->imgs[SPIKES_U]);
	// mlx_delete_image(g->mlx, g->imgs[FOX_D]);
	// mlx_delete_image(g->mlx, g->imgs[FOX_U]);
	// mlx_delete_image(g->mlx, g->imgs[RAT_L]);
	// mlx_delete_image(g->mlx, g->imgs[RAT_R]);
	// mlx_delete_image(g->mlx, g->imgs[ODD_TERRAIN]);
	// mlx_delete_image(g->mlx, g->imgs[PAIR_TERRAIN]);
	// mlx_delete_image(g->mlx, g->imgs[BLACK]);
	// mlx_delete_image(g->mlx, g->imgs[SKY_BL]);
	// mlx_delete_image(g->mlx, g->imgs[SKY_BR]);
	// mlx_delete_image(g->mlx, g->imgs[SKY_TL]);
	// mlx_delete_image(g->mlx, g->imgs[SKY_TR]);
}

int	close_window(t_game *game)
{
	ft_freemap(game->maps[INITIAL_MAP]);
	ft_freemap(game->maps[ITEMS_MAP]);
	ft_freemap(game->maps[ENEMIES_MAP]);
	destroy_images(game);
	// mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit (0);
}

// int	key_hook(int keycode, t_game *g)
// {
// 	g->lastkey = keycode;
// 	if (((keycode >= A_KEY && keycode <= D_KEY) || keycode == W_KEY
// 	|| (keycode >= LEFT && keycode <= UP)) && g->rabbits)
// 	{
// 		g->moves++;
// 		if (!CLOCKENEMIES)
// 		{
// 			animate_enemies(&g->maps[ENEMIES_MAP], &g->enemy_clock_watch);
// 			rabbit_survive(&g->maps[ITEMS_MAP], g->maps[ENEMIES_MAP]);
// 		}
// 		if (keycode == DOWN || keycode == S_KEY)
// 			try_move_down(&g->maps[ITEMS_MAP], g->carrots);
// 		else if (keycode == LEFT || keycode == A_KEY)
// 			try_move_left(&g->maps[ITEMS_MAP], g->carrots);
// 		else if (keycode == RIGHT || keycode == D_KEY)
// 			try_move_right(&g->maps[ITEMS_MAP], g->carrots);
// 		else if (keycode == UP || keycode == W_KEY)
// 			try_move_up(&g->maps[ITEMS_MAP], g->carrots);
// 		rabbit_survive(&g->maps[ITEMS_MAP], g->maps[ENEMIES_MAP]);
// 		draw_map(g, 1);
// 	}
// 	if (keycode == ESC)
// 		close_window(g);
// 	return (0);
// }


void	key_hook(mlx_key_data_t keydata, void	*game)
{
	t_game	*g;
	int	i;

	g = (t_game *)game;
	i = -1;
	if (keydata.action == MLX_PRESS)
	{
		while (++i < g->rabbits)
		{
			if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
				mlx_draw_texture(g->players[i].img, g->player_textures[PLAYER_UP], 0, 0);
				// try_move_down(game->maps[ITEMS_MAP], game->carrots);
			else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
				mlx_draw_texture(g->players[i].img, g->player_textures[PLAYER_DOWN], 0, 0);
				// try_move_left(game->maps[ITEMS_MAP], game->carrots);
			else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
				mlx_draw_texture(g->players[i].img, g->player_textures[PLAYER_LEFT], 0, 0);
				// try_move_right(game->maps[ITEMS_MAP], game->carrots);
			else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
				mlx_draw_texture(g->players[i].img, g->player_textures[PLAYER_RIGHT], 0, 0);
				// try_move_up(game->maps[ITEMS_MAP], game->carrots);
		}



	}

}

void	draw_map_loop(t_game *g)
{
	if (!g->enemy_clock)
	{
		animate_enemies(&g->maps[ENEMIES_MAP], &g->enemy_clock_watch);
		rabbit_survive(&g->maps[ITEMS_MAP], g->maps[ENEMIES_MAP]);
		g->enemy_clock = CLOCKENEMIES;
	}
	g->enemy_clock--;
	if (!g->clock)
	{
		g->clock = CLOCKTICKS;
		draw_map(g, 0);
	}
	g->clock--;
	// return (0);
}
