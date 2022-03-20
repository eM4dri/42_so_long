/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:02:42 by emadriga          #+#    #+#             */
/*   Updated: 2021/05/30 23:10:44 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*mem;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + s_len);
	mem = (char *)s + s_len - 1;
	while (s_len-- > 0)
	{
		if (*mem == (unsigned char)c)
			return (mem);
		mem--;
	}
	return (0);
}
