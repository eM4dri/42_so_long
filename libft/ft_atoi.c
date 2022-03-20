/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:06:04 by emadriga          #+#    #+#             */
/*   Updated: 2021/05/29 09:32:57 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				sign;
	long long		result;

	sign = 1;
	result = 0;
	while (*str != 0 && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9' && result < 2147483648)
		result = 10 * result + (int)(*str++ - '0');
	if (result > 2147483647 && sign > 0)
		return (-1);
	if (result > 2147483648 && sign < 0)
		return (0);
	return ((int)result * sign);
}
