/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:10:52 by emadriga          #+#    #+#             */
/*   Updated: 2021/05/29 12:31:26 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len_s1;

	len_s1 = ft_strlen(s1) + 1;
	copy = malloc(sizeof(char) * len_s1);
	if (!copy)
		return (0);
	ft_memcpy(copy, s1, len_s1);
	return (copy);
}
