/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:16:58 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/24 22:18:33 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_chr(va_arg(ap, int));
	else if (c == 's')
		len += ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_print_int(va_arg(ap, long int), 0);
	else if (c == 'u')
		len += ft_print_int(va_arg(ap, int), 1);
	else if (c == 'x' || c == 'X')
		ft_print_hex((va_arg(ap, unsigned int)), c, &len);
	return (len);
}

int	ft_printf(const char *argum, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	if (!argum)
		return (0);
	va_start(ap, argum);
	i = -1;
	len = 0;
	while (argum[++i] != '\0')
	{
		if (argum[i] == '%')
		{
			if (argum[++i] == '%')
				len += ft_print_chr(argum[i]);
			else
				len += ft_conversion(ap, argum[i]);
		}
		else
			len += ft_print_chr(argum[i]);
	}
	va_end(ap);
	return (len);
}
