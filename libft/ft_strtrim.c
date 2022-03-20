/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:19:27 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:47:38 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_strchr(set, *s1) != 0 && len--)
		s1++;
	if (*s1 == '\0' || !len)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) != 0)
		len--;
	out = ft_substr(s1, 0, len);
	return (out);
}
