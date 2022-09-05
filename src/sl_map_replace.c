/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 08:21:59 by emadriga          #+#    #+#             */
/*   Updated: 2022/09/05 23:42:19 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Replace all characters 'c' with str in map
 * @param map	map
 * @param c		char to replace
 * @param str	str to put instead
*/
void	ft_replace_all(t_map_lines **map, char c, char *str)
{
	t_map_lines	*aux;
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i] != '\0')
		{
			if (aux->str[i] == c)
				aux->str = ft_replace(aux->str, str, i);
			i++;
		}
		aux = aux->next;
	}
}

/**
 * * Replace all characters 'c' with str in map
 * @param map	map
 * @param c		char to replace
 * @param str	str to put instead
*/
void	ft_replace_all_except(t_map_lines **map, char c, char *str, int id)
{
	t_map_lines	*aux;
	int			i;

	aux = *map;
	while (aux != NULL)
	{
		i = 0;
		while (aux->str[i] != '\0')
		{
			if (aux->str[i] == c)
			{
				if (id != 0)
					aux->str = ft_replace(aux->str, str, i);
				id--;
			}
			i++;
		}
		aux = aux->next;
	}
}
