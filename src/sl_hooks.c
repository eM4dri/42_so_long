/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:30:12 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/09 10:13:46 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window( t_vars *vars)
{
	ft_freemap(vars->map);
	ft_freemap(vars->imap);
	ft_freemap(vars->emap);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->lastkey = keycode;
	if (((keycode >= A_KEY && keycode <= D_KEY) || keycode == W_KEY \
	|| (keycode >= LEFT && keycode <= UP)) && vars->rabbits)
	{
		vars->moves++;
		if (!CLOCKENEMIES)
		{
			animate_enemies(&vars->emap, &vars->enemy_clock_watch);
			rabbit_survive(&vars->imap, vars->emap);
		}
		if (keycode == DOWN || keycode == S_KEY)
			try_move_down(&vars->imap, vars->carrots);
		else if (keycode == LEFT || keycode == A_KEY)
			try_move_left(&vars->imap, vars->carrots);
		else if (keycode == RIGHT || keycode == D_KEY)
			try_move_right(&vars->imap, vars->carrots);
		else if (keycode == UP || keycode == W_KEY)
			try_move_up(&vars->imap, vars->carrots);
		rabbit_survive(&vars->imap, vars->emap);
		draw_map(vars, 1);
	}
	if (keycode == ESC)
		close_window(vars);
	return (0);
}

int	draw_map_loop(t_vars *vars)
{
	if (!vars->enemy_clock)
	{
		animate_enemies(&vars->emap, &vars->enemy_clock_watch);
		rabbit_survive(&vars->imap, vars->emap);
		vars->enemy_clock = CLOCKENEMIES;
	}
	vars->enemy_clock--;
	if (!vars->clock)
	{
		vars->clock = CLOCKTICKS;
		draw_map(vars, 0);
	}
	vars->clock--;
	return (0);
}
