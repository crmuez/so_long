/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:09 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/05/10 20:22:43 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		temp;

	total = 0;
	i = -1;
	va_start (args, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1] == 'd')
			temp = ft_conversion(s[++i], args);
		else
			temp = write (1, &s[i], 1);
		if (temp < 0)
			return (-1);
		total += temp;
	}
	va_end (args);
	return (total);
}
