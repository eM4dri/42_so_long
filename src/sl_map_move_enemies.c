/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_move_enemies.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:21 by emadriga          #+#    #+#             */
/*   Updated: 2023/04/03 18:42:22 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Replace x -> X & X -> x to handle trap animations
 * @param map	map
*/
void	trap_animation(t_map_lines **map)
{
	t_map_lines	*aux;
	char		*str;

	aux = (*map)->next;
	while (aux->next != NULL)
	{
		str = &aux->str[1];
		while (str[1] != '\0')
		{
			if (*str == 'x')
				*str = 'X';
			else if (*str == 'X')
				*str = 'x';
			str++;
		}
		aux = aux->next;
	}
}

/**
 * * Horizontal watch enemies h going right & H left
 * @param map	map
*/
static void	enemy_horizontal_watch(t_map_lines **map)
{
	t_map_lines	*aux;
	char		*str;

	aux = (*map)->next;
	while (aux->next != NULL)
	{
		str = &aux->str[1];
		while (str[1] != '\0')
		{
			if (*str == '0' && str[1] == 'H')
				ft_replace_this_charset(&str, "H0");
			else if (*str == 'h' && str[1] == '0')
				ft_replace_this_charset(&str, "0h");
			else
				str--;
			str += 2;
		}
		aux = aux->next;
	}
}

/**
 * * Vertical watch enemies V going Up
 * @param map	map
*/
static void	enemy_vertical_watch_up(t_map_lines **map)
{
	t_map_lines	*aux;
	char		*str;
	char		*next;

	aux = (*map)->next;
	while (aux->next != NULL)
	{
		str = aux->str;
		next = aux->next->str;
		while (*str != '\0' && *next != '\0')
		{
			if (*str == '0' && *next == 'V')
			{
				*str = 'V';
				*next = '0';
			}
			str++;
			next++;
		}
		aux = aux->next;
	}
}

/**
 * * Vertical watch enemies v going down 
 * @param map	map
*/
static void	enemy_vertical_watch_down(t_map_lines **map)
{
	t_map_lines	*aux;
	char		*str;
	char		*next;

	aux = (*map)->next;
	while (aux->next != NULL)
	{
		str = aux->str;
		next = aux->next->str;
		while (*str != '\0' && *next != '\0')
		{
			if (*str == 'v' && *next == '0')
			{
				*str = '0';
				*next = 'b';
			}
			str++;
			next++;
		}
		aux = aux->next;
	}
	ft_replace_all_chars(map, 'b', 'v');
}

void	animate_enemies(t_map_lines **map, int *clock)
{
	*clock -= 1;
	trap_animation(map);
	enemy_horizontal_watch(map);
	enemy_vertical_watch_up(map);
	enemy_vertical_watch_down(map);
	if (!*clock)
	{
		ft_replace_all_chars(map, 'v', 'B');
		ft_replace_all_chars(map, 'H', 'j');
		ft_replace_all_chars(map, 'V', 'b');
		ft_replace_all_chars(map, 'h', 'J');
		ft_replace_all_chars(map, 'B', 'V');
		ft_replace_all_chars(map, 'j', 'h');
		ft_replace_all_chars(map, 'b', 'v');
		ft_replace_all_chars(map, 'J', 'H');
		*clock = CLOCKWATCH;
	}
}
