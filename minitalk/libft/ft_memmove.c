/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:55:34 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 20:04:26 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		while (n > i)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	else if (src < dest)
	{
		while (n-- != 0)
			((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}

/*int	main(void)
{
	char	dest[] = "123456";
	char	src[] = "abcd";
	size_t	n = 3;

	printf("%s", (char *)ft_memmove(dest, src, n));
	return (0);
}*/
