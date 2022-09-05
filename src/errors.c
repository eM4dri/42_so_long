/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:13:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/09/05 14:26:07 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * * Log error into STDERR_FILENO
 * @param str_error		Error to log into STDERR_FILENO
*/
void	log_error(char *str_error)
{
	ft_putstr_fd(str_error, STDERR_FILENO);
}

/**
 * * Log error into STDERR_FILENO
 * * Free malloc log error input
 * @param malloc_str_error	Error to log into STDERR_FILENO
*/
void	log_error_free(char *malloc_str_error)
{
	log_error(malloc_str_error);
	free(malloc_str_error);
}
