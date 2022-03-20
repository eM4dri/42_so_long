/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:52:32 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:39:41 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*mem;
	unsigned char	*out;

	mem = (unsigned char *)src;
	out = (unsigned char *)dst;
	if (dst != src)
		while (n-- > 0)
			*out++ = *mem++;
	return (dst);
}
