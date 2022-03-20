/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:59:07 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:41:29 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;

	mem1 = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	while ((mem1 || mem2) && n--)
		if (*mem1++ != *mem2++)
			return (mem1[-1] - mem2[-1]);
	return (0);
}
