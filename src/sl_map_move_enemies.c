/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_move_enemies.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:19:21 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/09 09:14:47 by emadriga         ###   ########.fr       */
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
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i + 1] != '\0')
		{
			if (aux->str[i] == 'x')
				aux->str = ft_replace(aux->str, "X", i);
			else if (aux->str[i] == 'X')
				aux->str = ft_replace(aux->str, "x", i);
			i++;
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
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i + 1] != '\0')
		{
			if (aux->str[i] == 'H' && aux->str[i - 1] == '0')
				aux->str = ft_replace(aux->str, "H0", i - 1);
			if (aux->str[i + 1] == '0' && aux->str[i] == 'h')
				aux->str = ft_replace(aux->str, "0h", i++);
			i++;
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
	t_map_lines	*prev;
	int			i;

	prev = *map;
	aux = prev->next;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i] != '\0')
		{
			if (aux->str[i] == 'V' && prev->str[i] == '0')
			{
				aux->str = ft_replace(aux->str, "0", i);
				prev->str = ft_replace(prev->str, "V", i);
			}
			i++;
		}
		aux = aux->next;
		prev = prev->next;
	}
}

/**
 * * Vertical watch enemies v going down 
 * @param map	map
*/
static void	enemy_vertical_watch_down(t_map_lines **map)
{
	t_map_lines	*aux;
	t_map_lines	*next;
	int			i;

	aux = *map;
	next = aux->next;
	while (next != NULL)
	{
		i = 0;
		while (aux->str[i] != '\0')
		{
			if (aux->str[i] == 'v' && next->str[i] == '0')
			{
				aux->str = ft_replace(aux->str, "0", i);
				next->str = ft_replace(next->str, "b", i);
			}
			i++;
		}
		aux = aux->next;
		next = next->next;
	}
	ft_replace_all(map, 'b', "v");
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
		ft_replace_all(map, 'v', "B");
		ft_replace_all(map, 'H', "j");
		ft_replace_all(map, 'V', "b");
		ft_replace_all(map, 'h', "J");
		ft_replace_all(map, 'B', "V");
		ft_replace_all(map, 'j', "h");
		ft_replace_all(map, 'b', "v");
		ft_replace_all(map, 'J', "H");
		*clock = CLOCKWATCH;
	}
}
