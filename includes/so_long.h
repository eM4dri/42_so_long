/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:36 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/24 08:29:13 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"
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

typedef struct s_vars{
	void		*mlx;
	void		*win;
	void		*img;
	t_map_lines	*map;
	t_map_lines	*imap;
	t_map_lines	*emap;
	int			lastkey;
	int			moves;
	int			carrots;
	int			rabbits;
	int			save;
	int			clock;
	int			enemy_clock_watch;
	int			enemy_clock;
	int			drawn;
	int			map_width;
	int			map_height;
	int			win_width;
	int			win_height;
}t_vars;

void	parse_map(char *file, t_map_lines **map);
void	ft_freemap(t_map_lines *map);
char	*ft_replace(char *str, char const *charset, size_t index);
void	try_move_down(t_map_lines **map, int items);
void	try_move_left(t_map_lines **map, int items);
void	try_move_right(t_map_lines **map, int items);
void	try_move_up(t_map_lines **map, int items);
void	ft_printmap(t_map_lines *map);
void	draw_map(t_vars *vars, int is_key_input);
int		count_colectables(t_map_lines *map, char c);
int		get_map_height(t_map_lines *map);
void	pre_map_exit(t_map_lines *map, const char *str, int free_needed);
void	ft_lstadd_back_line(t_map_lines **map, char *line);
void	ft_replace_all(t_map_lines **map, char c, char *str);
void	ft_copymap(t_map_lines **dts, t_map_lines *src);
void	ft_emptymap(t_map_lines **map, int width, int height);
void	ft_comparemaps(t_map_lines **dts, t_map_lines *m1, t_map_lines *m2);
void	animate_enemies(t_map_lines **map, int *clock);
void	rabbit_survive(t_map_lines **imap, t_map_lines *emap);
void	clean_carrots(t_map_lines **emap, t_map_lines *imap);
void	draw_lines_objects_enemies(t_vars *v, char *str, int nbr_line, \
		 int pixel);
void	ft_draw(t_vars *vars, t_map_lines *map, \
				void (*func)(t_vars *, char *, int, int));
int		close_window( t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		draw_map_loop(t_vars *vars);
void	*ft_mlx_xpm_file_to_image(void *mlx, char *filename);
#endif
