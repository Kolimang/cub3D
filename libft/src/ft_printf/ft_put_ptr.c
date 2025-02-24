/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:45:46 by ngharian          #+#    #+#             */
/*   Updated: 2023/11/14 16:45:52 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_put_ptr(void *address)
{
	int					tot;
	int					tmp;

	tot = write(1, "0x", 2);
	if (tot < 0)
		return (-1);
	tmp = ft_puthexa((unsigned long)address, "0123456789abcdef");
	if (tmp < 0)
		return (-1);
	tot += tmp;
	return (tot);
}
