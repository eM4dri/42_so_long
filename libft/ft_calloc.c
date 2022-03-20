/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:12:02 by emadriga          #+#    #+#             */
/*   Updated: 2021/05/30 22:46:00 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*out;
	size_t	len;

	len = count * size;
	out = malloc(len);
	if (!out)
		return (0);
	ft_bzero(out, len);
	return (out);
}
