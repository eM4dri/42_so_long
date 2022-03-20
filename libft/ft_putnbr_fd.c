/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:59:31 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:42:32 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int			un;

	if (n < 0)
	{
		un = (unsigned int) n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		un = (unsigned int) n;
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putnbr_fd(un % 10, fd);
	}
	else
		ft_putchar_fd(un + '0', fd);
}
