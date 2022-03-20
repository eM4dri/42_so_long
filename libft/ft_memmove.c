/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:56:26 by emadriga          #+#    #+#             */
/*   Updated: 2021/05/28 18:06:37 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*mem;
	unsigned char	*out;

	if (dst != src)
	{
		if (dst < src)
			ft_memcpy(dst, src, len);
		else
		{
			mem = (unsigned char *)src + len - 1;
			out = dst + len - 1;
			while (len--)
				*out-- = *mem--;
		}
	}
	return (dst);
}
