/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:40:56 by emadriga          #+#    #+#             */
/*   Updated: 2021/05/29 12:06:37 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int) n * -1);
	return ((unsigned int) n);
}

static int	ft_numlen(int n)
{
	unsigned int	un;
	int				len;

	len = 0;
	un = ft_abs(n);
	if (n < 0)
		len++;
	while (un > 0 && ++len)
		un /= 10;
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*out;
	unsigned int	un;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_numlen(n);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	un = ft_abs(n);
	out[len] = '\0';
	while (--len >= 0 && un > 0)
	{
		out[len] = (unsigned char)(un % 10 + '0');
		un /= 10;
	}
	if (n < 0)
		out[len] = '-';
	return (out);
}
