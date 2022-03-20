/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:04:33 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:46:47 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	if (!*needle)
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	while (*haystack != '\0' && len-- > 0)
	{
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, len_needle))
				return ((char *)haystack);
		haystack++;
		if (len_needle > len)
			break ;
	}
	return (0);
}
