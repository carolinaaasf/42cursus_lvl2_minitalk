/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:04:41 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 18:48:17 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;
	size_t	n;

	n = nmemb * size;
	str = (char *)malloc(n);
	if (str == NULL)
		return (0);
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
	return ((void *)str);
}

/*#include <stdio.h>

int main(void)
{
	printf("imprime: %s", (char*)ft_calloc(4, sizeof(char)));
	return 0;
}*/
