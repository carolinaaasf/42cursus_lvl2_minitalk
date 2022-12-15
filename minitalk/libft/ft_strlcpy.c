/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:36:35 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 11:00:02 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*#include <unistd.h>
int	main(void)
{
	char	src[] = "f/h39rhfi";
	char	dest[] = "12iqiu";

	int c = ft_strlcpy(dest, src, 7);
	printf("%d \n", c);
	for (int i = 0; dest[i] != '\0'; i++)
	{
		write(1, &dest[i], 1);
	}
	return (0);
}*/
