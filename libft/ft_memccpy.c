/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:57:11 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:39:30 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	*out;

	mem = (unsigned char *)src;
	out = dst;
	while (n-- > 0)
	{
		*out++ = *mem;
		if (*mem++ == (unsigned char) c)
			return (out);
	}
	return (NULL);
}
