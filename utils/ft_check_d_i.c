/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:20:39 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/10 20:31:36 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(long nlong)
{
	char		str;
	static int	total;
	int			j;

	total = 0;
	if (nlong < 0)
	{
		j = write(1, "-", 1);
		nlong = nlong * -1;
		if (j == -1)
			return (-1);
	}
	if (nlong >= 10)
	{
		j = ft_putnbr(nlong / 10);
		str = '0' + (nlong % 10);
		if (j == -1)
			return (-1);
	}
	else
		str = '0' + nlong;
	j = write(1, &str, 1);
	if (j == -1)
		return (-1);
	return (++total);
}

int	ft_check_d_i(va_list args)
{
	long	n;
	int		j;

	n = va_arg(args, int);
	if (n < 0)
	{
		j = ft_putnbr(n) + 1;
		if (j == 0)
			return (-1);
		return (j);
	}
	return (ft_putnbr(n));
}

int	ft_conversion(char s, va_list args)
{
	if (s == 'd' || s == 'i')
		return (ft_check_d_i(args));
	return (0);
}
