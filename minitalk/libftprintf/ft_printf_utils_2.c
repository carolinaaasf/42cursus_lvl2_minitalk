/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:38:06 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/27 19:51:15 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long long p, int *len)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16, len);
		ft_put_ptr(p % 16, len);
	}
	else
	{
		if (p < 10)
			(*len) += ft_print_chr(p + '0');
		else
			(*len) += ft_print_chr(p - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long p)
{
	int	len;

	if (!p)
		return (write(1, "(nil)", 5));
	len = 0;
	len += write(1, "0x", 2);
	ft_put_ptr(p, &len);
	return (len);
}
