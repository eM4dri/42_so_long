/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:21:59 by emadriga          #+#    #+#             */
/*   Updated: 2021/10/03 09:35:17 by emadriga         ###   ########.fr       */
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
	char		*str;

	aux = *map;
	while (aux != NULL)
	{
		str = aux->str;
		while (str[1] != '\0')
		{
			if (*str == 'P' && str[1] == 'E' && (!items || ALLOWEXIT))
				ft_replace_this_charset(&str, "0E");
			else if (*str == 'P' && ft_strchr("0C", str[1]))
				ft_replace_this_charset(&str, "0p");
			str++;
		}
		aux = aux->next;
	}
	printf("RIGHT");
	ft_replace_all_chars(map, 'p', 'P');
}

/**
 * * Try moving players right
 * @param map	map
*/
void	try_move_left(t_map_lines **map, int items)
{
	t_map_lines	*aux;
	char		*str;

	aux = *map;
	while (aux != NULL)
	{
		str = aux->str;
		while (str[1] != '\0')
		{
			if (str[1] == 'P' && *str == 'E' && (!items || ALLOWEXIT))
				ft_replace_this_charset(&str, "E0");
			else if (str[1] == 'P' && ft_strchr("0C", *str))
				ft_replace_this_charset(&str, "P0");
			str++;
		}
		aux = aux->next;
	}
	printf("LEFT");
}

// /**
//  * * Replace all characters 'c' with str in map
//  * @param map	map
//  * @param c		char to replace 
//  * @param str	str to put instead
// */
// void	ft_replace_all(t_map_lines **map, char c, char *str)
// {
// 	t_map_lines	*aux;
// 	int			i;

// 	aux = *map;
// 	while (aux != NULL)
// 	{
// 		i = 0;
// 		while (aux->str[i] != '\0')
// 		{
// 			if (aux->str[i] == c)
// 				aux->str = ft_replace(aux->str, str, i);
// 			i++;
// 		}
// 		aux = aux->next;
// 	}
// }

/**
 * * Replace all characters 'c' with str in map
 * @param map	map
 * @param c		char to replace 
 * @param str	str to put instead
*/
void	ft_replace_all_chars(t_map_lines **map, char c1, char c2)
{
	t_map_lines	*aux;
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i] != '\0')
		{
			if (aux->str[i] == c1)
				aux->str[i] = c2;
			i++;
		}
		aux = aux->next;
	}
}

/**
 * * Try moving players down
 * @param map	map
*/
void	try_move_down(t_map_lines **map, int items)
{
	t_map_lines	*aux;
	char		*str;
	char		*next;

	aux = *map;
	while (aux->next != NULL)
	{
		str = aux->str;
		next = aux->next->str;
		while (*str != '\0' && *next != '\0')
		{
			if (*str == 'P' && *next == 'E' && (!items || ALLOWEXIT))
				str[0] = '0';
			else if (*str == 'P' && ft_strchr("0C", *next))
			{
				str[0] = '0';
				next[0] = 'p';
			}
			str++;
			next++;
		}
		aux = aux->next;
	}
	printf("DOWN");
	ft_replace_all_chars(map, 'p', 'P');
}

/**
 * * Try moving players up
 * @param map	map
*/
void	try_move_up(t_map_lines **map, int items)
{
	t_map_lines	*aux;
	char		*str;
	char		*prev;

	aux = *map;
	while (aux->next != NULL)
	{
		prev = aux->str;
		str = aux->next->str;
		while (*str != '\0' && *prev != '\0')
		{
			if (*str == 'P' && *prev == 'E' && (!items || ALLOWEXIT))
				*str = '0';
			else if (*str == 'P' && ft_strchr("0C", *prev))
			{
				*str = '0';
				*prev = 'P';
			}
			prev++;
			str++;
		}
		aux = aux->next;
	}
	printf("UP");
}
