/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:41:56 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/14 15:34:17 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putstr(char *str)
{
	size_t	tot;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	tot = ft_strlen(str);
	return (write(1, str, tot));
}
