/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:36 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/07 11:40:13 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include "../src/mlx/include/MLX42/MLX42.h"
# include "options.h"
# include "constants.h"
# include "errors.h"
# include "images.h"

typedef struct s_map_objects
{
	int	start;
	int	exit;
	int	item;
}t_map_objects;

typedef struct s_map_lines
{
	char				*str;
	struct s_map_lines	*next;
}t_map_lines;

typedef struct s_player
{
	mlx_image_t		*img;
	t_map_lines		*map;
}t_player;

typedef struct s_enemy
{
	mlx_image_t		*img;
	t_map_lines		*map;
}t_enemy;

// typedef struct s_imgs{
// 	void	*carrot;
// 	void	*hole;
// 	void	*rabbit_down;
// 	void	*rabbit_ko;
// 	void	*rabbit_left;
// 	void	*rabbit_right;
// 	void	*rabbit_up;
// 	void	*spikes_down;
// 	void	*spikes_up;
// 	void	*fox_down;
// 	void	*fox_up;
// 	void	*rat_left;
// 	void	*rat_right;
// 	void	*odd_terrain;
// 	void	*pair_terrain;
// 	void	*wall;
// 	void	*black;
// 	void	*sky_br;
// 	void	*sky_bl;
// 	void	*sky_tl;
// 	void	*sky_tr;
// }t_imgs;

typedef struct s_game{
	void			*mlx;
	// void			*win;
	mlx_image_t		*envimgs[TOTAL_TEXTURES_ENVIROMENT];
	t_map_lines		*loadedMap;
	char			**items_maps;
	char			**enemies_maps;
	mlx_texture_t	*player_textures[TOTAL_TEXTURES_PLAYER];
	t_player		*players;
	// mlx_texture_t	*textures[TOTAL_TEXTURES_ENEMY];
	// t_map_lines	*imap;
	// t_map_lines	*emap;
	int				lastkey;
	int				moves;
	int				carrots;
	int				rabbits;
	int				save;
	int				clock;
	int				enemy_clock_watch;
	int				enemy_clock;
	int				drawn;
	int				map_width;
	int				map_height;
	int				win_width;
	int				win_height;
	int				tick;
}t_game;

void	parse_map(char *file, t_map_lines **map);
void	ft_freemap(t_map_lines *map);
char	*ft_replace(char *str, char const *charset, size_t index);
void	try_move_down(t_map_lines **map, int items);
void	try_move_left(t_map_lines **map, int items);
void	try_move_right(t_map_lines **map, int items);
void	try_move_up(t_map_lines **map, int items);
void	ft_printmap(t_map_lines *map);
void	draw_map(t_game *game, int is_key_input);
int		count_colectables(char **map, char c);
int		get_map_height(t_map_lines *map);
void	pre_map_exit(t_map_lines *map, const char *str, int free_needed);
void	ft_lstadd_back_line(t_map_lines **map, char *line);
void	ft_replace_all(t_map_lines **map, char c, char *str);
void	ft_replace_all_except(t_map_lines **map, char c, char *str, int id);
void	ft_copymap(t_map_lines **dts, t_map_lines *src);
void	ft_emptymap(t_map_lines **map, int width, int height);
void	ft_comparemaps(t_map_lines **dts, t_map_lines *m1, t_map_lines *m2);
void	animate_enemies(t_map_lines **map, int *clock);
void	rabbit_survive(t_map_lines **imap, t_map_lines *emap);
void	clean_carrots(t_map_lines **emap, t_map_lines *imap);
void	draw_lines_objects_enemies(t_game *v, char *str, int nbr_line, \
				double pixel);
void	ft_draw(t_game *game, t_map_lines *map, \
				void (*func)(t_game *, char *, int, double));
int		close_window( t_game *game);
void	key_hook(mlx_key_data_t keycode, void *game);
void	draw_map_loop(t_game *game);
void	load_images(t_game *game);
void	log_error(char *str_error);

void	log_error_free(char *malloc_str_error);
char	**ft_copymap_matrix(t_map_lines *src, int height);
void	ft_replace_all_matrix(char **map, char oldchar, char newchar);
void	ft_replace_all_matrix_except(char **map, char oldchar, char newchar, int id);
void	array_str_free(char ***list);
void	array_str_print(char **array);
int		array_str_get_size(char **array);
#endif
