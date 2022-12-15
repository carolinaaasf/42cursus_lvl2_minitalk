/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:52:53 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 22:26:34 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(unsigned int nb, int dig)
{
	unsigned int	aux;

	aux = nb;
	dig++;
	while (aux / 10 > 0)
	{
		dig++;
		aux /= 10;
	}
	return (dig);
}

static char	*ft_fill_str(int n, char *str, int dig, unsigned int nb)
{
	int	i;

	i = dig - 1;
	while (i >= 0)
	{
		if (n < 0 && i == 0)
			str[i] = '-';
		else
		{
			str[i] = nb % 10 + '0';
			nb /= 10;
		}
		i--;
	}
	str[dig] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				dig;
	char			*str;

	nb = n;
	dig = 0;
	if (nb == 0)
	{
		str = (char *)malloc(sizeof(char) * 1 + 1);
		if (str == NULL)
			return (0);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		dig++;
		nb *= -1;
	}
	dig = ft_count_digits(nb, dig);
	str = (char *)malloc((dig) * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	return (ft_fill_str(n, str, dig, nb));
}

/*int	main(void)
{
	int	n = 0;
	char	*str;

	str = ft_itoa(n);
	printf("string: %s", ft_itoa(n));
	return (0);
}*/
