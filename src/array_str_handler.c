/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_str_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:23:47 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/07 11:36:49 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * This function recieves a list of strings (pointer to pointers) and frees
 * * everything, including the main pointer. The last string must be NULL.
 * @param list		array to free
**/
void	array_str_free(char ***list)
{
	int	a;

	a = 0;
	if (*list)
	{
		while ((*list)[a])
			free((*list)[a++]);
		free((*list)[a]);
		free(*list);
	}
}

/**
 * * Print array of strings
 * @param array	array
*/
void	array_str_print(char **array)
{
	if (array != NULL)
		while (*array != NULL)
			printf("%s\n", *array++);
}

/**
 * * Get size of array of strings
 * @param array	array
*/
int	array_str_get_size(char **array)
{
	int	a;

	a = 0;
	if (array != NULL)
		while (array[a])
			a++;
	return (a);
}
