/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:02:12 by emadriga          #+#    #+#             */
/*   Updated: 2021/08/01 10:25:25 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*mem;

	mem = (char *)s;
	while (*mem != '\0')
	{
		if (*mem++ == (char)c)
			return (--mem);
	}
	if (c == '\0')
		return (mem);
	return (NULL);
}
