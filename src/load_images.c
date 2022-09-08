/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:29:57 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/08 19:35:42 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# define ERROR_LOADING_IMG_DETAIL "Error loading image: \n"
# define ERROR_LOADING_TEXTURE_DETAIL "Error loading texture: \n"


static mlx_texture_t *load_texture(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		log_error_free(ft_strreplace(ERROR_LOADING_TEXTURE_DETAIL, "{0}", path));
	return (texture);
}

static mlx_image_t *load_png(t_game *game, char *path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = load_texture(path);
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!img)
		log_error_free(ft_strreplace(ERROR_LOADING_IMG_DETAIL, "{0}", path));
	return (img);
}

static mlx_image_t *load_png_area(t_game *game, char *path, uint32_t width, uint32_t height)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	uint32_t		xy[2];
	uint32_t		wh[2];

	ft_memset(xy, 0, 2 * sizeof(uint32_t));
	wh[0] = width;
	wh[1] = height;
	texture = mlx_load_png(path);
	if (!texture)
		log_error_free(ft_strreplace(ERROR_LOADING_IMG_DETAIL, "{0}", path));
	img = mlx_texture_area_to_image(game->mlx, texture, xy, wh);
	mlx_delete_texture(texture);
	if (!img)
		log_error_free(ft_strreplace(ERROR_LOADING_IMG_DETAIL, "{0}", path));
	return (img);
}

void	load_images(t_game *g, t_map_lines *loaded_map)
{
	int			i;
	// t_player	*player;

	i = -1;
	g->envimgs[CARROT] = load_png(g, IMG_CARROT);
	g->envimgs[HOLE] = load_png(g, IMG_HOLE);
	g->envimgs[ODD_TERRAIN] = load_png(g, IMG_ODD_TERRAIN);
	g->envimgs[PAIR_TERRAIN] = load_png(g, IMG_PAIR_TERRAIN);
	g->envimgs[WALL] = load_png(g, IMG_WALL);
	g->envimgs[BLACK] = load_png(g, IMG_BLACK);
	g->envimgs[SKY] = load_png_area(g, IMG_SKY, g->win_width + WIDTH, g->win_height);
	g->player_textures[PLAYER_DOWN] =  load_texture(IMG_RABBIT_D);
	g->player_textures[PLAYER_KO] =  load_texture(IMG_RABBIT_KO);
	g->player_textures[PLAYER_LEFT] =  load_texture(IMG_RABBIT_L);
	g->player_textures[PLAYER_RIGHT] =  load_texture(IMG_RABBIT_R);
	g->player_textures[PLAYER_UP] =  load_texture(IMG_RABBIT_U);
	while (++i < g->rabbits)
	{
		// player = &g->players[i];
		g->players[i] = NULL;
		g->players[i] = (t_player *)malloc(sizeof(t_player));
		g->players[i]->img = \
			mlx_texture_to_image(g->mlx, g->player_textures[PLAYER_DOWN]);
		// ft_printmap(g->maps[ITEMS_MAP]);
		g->players[i]->map = NULL;
		g->players[i]->map = ft_copymap_matrix(loaded_map, g->map_height);
		// ft_copymap(&player->map, g->maps[ITEMS_MAP]);
		// ft_replace_all_except(&player->map, 'P', "p", i);
		ft_replace_all_matrix_except(g->players[i]->map, 'P', 'p', i);
		array_str_print(g->players[i]->map);
	}
	// game->imgs[RABBIT_D] = load_png(game, IMG_RABBIT_D);
	// game->imgs[RABBIT_KO] = load_png(game, IMG_RABBIT_KO);
	// game->imgs[RABBIT_L] = load_png(game, IMG_RABBIT_L);
	// game->imgs[RABBIT_R] = load_png(game, IMG_RABBIT_R);
	// game->imgs[RABBIT_U] = load_png(game, IMG_RABBIT_U);
	// game->imgs[SPIKES_D] = load_png(game, IMG_SPIKES_D);
	// game->imgs[SPIKES_U] = load_png(game, IMG_SPIKES_U);
	// game->imgs[FOX_D] = load_png(game, IMG_FOX_D);
	// game->imgs[FOX_U] = load_png(game, IMG_FOX_U);
	// game->imgs[RAT_L] = load_png(game, IMG_RAT_L);
	// game->imgs[RAT_R] = load_png(game, IMG_RAT_R);
}

