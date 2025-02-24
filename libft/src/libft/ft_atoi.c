/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:29:29 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/06 15:44:55 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_convert(int i, const char *str, int sign)
{
	unsigned long long int	max;
	unsigned long long int	res;

	res = 0;
	max = 9223372036854775807;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > max && sign > 0)
			return (-1);
		if (res > max && sign < 0)
			return (0);
		++i;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	res;
	int						i;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	res = ft_convert(i, str, sign);
	return ((int)res);
}
