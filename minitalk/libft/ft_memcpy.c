/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:04:59 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 20:05:36 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	while (n > i)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
	char	str1[] = "teste1";
	char	str2[] = "um";

	printf("imprime %s \n", (char *)memcpy(str1, str2, sizeof(str2)));

	char	str3[] = "teste1";
	char	str4[] = "um";
	printf("imprime %s", (char *)ft_memcpy(str3, str4, sizeof(str4)));
	return 0;
}*/
