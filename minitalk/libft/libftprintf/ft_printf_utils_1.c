/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:12 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/27 19:50:11 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (i);
}

int	ft_print_int(unsigned int n, int uns)
{
	int		len;
	char	*str_nbr;

	len = 0;
	if (uns == 0 && ((int)n < 0))
	{
		write (1, "-", 1);
		len++;
		n *= -1;
	}
	str_nbr = ft_itoa2(n, uns);
	len += ft_print_str(str_nbr);
	free(str_nbr);
	return (len);
}

void	ft_print_hex(unsigned int n, char c, int *len)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16, c, len);
		ft_print_hex(n % 16, c, len);
	}
	else
	{
		if (n < 10)
			(*len) += ft_print_chr(n + '0');
		else if (c == 'x')
			(*len) += ft_print_chr(n + 'a' - 10);
		else if (c == 'X')
			(*len) += ft_print_chr(n + 'A' - 10);
	}
}
