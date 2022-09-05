/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:21:59 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/05 23:02:58 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Try moving players right
 * @param map	map
*/
void	try_move_right(t_map_lines **map, int items)
{
	t_map_lines	*aux;
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i + 1] != '\0')
		{
			if (aux->str[i] == 'P' && ft_strchr("0C", aux->str[i + 1]))
				aux->str = ft_replace(aux->str, "0P", i++);
			else if (aux->str[i] == 'P' && aux->str[i + 1] == 'E'\
			&& (!items || ALLOWEXIT))
				aux->str = ft_replace(aux->str, "0E", i++);
			i++;
		}
		aux = aux->next;
	}
	printf("RIGHT");
}

/**
 * * Try moving players right
 * @param map	map
*/
void	try_move_left(t_map_lines **map, int items)
{
	t_map_lines	*aux;
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i + 1] != '\0')
		{
			if (aux->str[i] == 'P' && ft_strchr("0C", aux->str[i - 1]))
				aux->str = ft_replace(aux->str, "P0", i - 1);
			else if (aux->str[i] == 'P' && aux->str[i - 1] == 'E'\
			&& (!items || ALLOWEXIT))
				aux->str = ft_replace(aux->str, "E0", i - 1);
			i++;
		}
		aux = aux->next;
	}
	printf("LEFT");
}

/**
 * * Try moving players down
 * @param map	map
*/
void	try_move_down(t_map_lines **map, int items)
{
	t_map_lines	*aux;
	t_map_lines	*next;
	int			i;

	aux = *map;
	next = aux->next;
	while (next != NULL)
	{
		i = -1;
		while (aux->str[++i] != '\0')
		{
			if (aux->str[i] == 'P' && ft_strchr("0C", next->str[i]))
			{
				aux->str = ft_replace(aux->str, "0", i);
				next->str = ft_replace(next->str, "p", i);
			}
			else if (aux->str[i] == 'P' && next->str[i] == 'E'\
			&& (!items || ALLOWEXIT))
				aux->str = ft_replace(aux->str, "0", i);
		}
		aux = aux->next;
		next = next->next;
	}
	printf("DOWN");
	ft_replace_all(map, 'p', "P");
}

/**
 * * Try moving players up
 * @param map	map
*/
void	try_move_up(t_map_lines **map, int items)
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
			if (aux->str[i] == 'P' && ft_strchr("0C", prev->str[i]))
			{
				aux->str = ft_replace(aux->str, "0", i);
				prev->str = ft_replace(prev->str, "P", i);
			}
			else if (aux->str[i] == 'P' && prev->str[i] == 'E'\
			&& (!items || ALLOWEXIT))
				aux->str = ft_replace(aux->str, "0", i);
			i++;
		}
		aux = aux->next;
		prev = prev->next;
	}
	printf("UP");
}
