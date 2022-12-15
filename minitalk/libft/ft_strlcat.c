/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:45:43 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 23:17:40 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (size < len_dst)
		return (len_src + size);
	while (src[i] != '\0' && (len_dst + i) < (size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/*int	main(void)
{
	//char	dest[20] = "abcdef";
	//char	src[] = "nyan !";
	//unsigned int	siz = 11;
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	size_t	max = strlen("the cake is a lie !\0I'm hidden lol\r\n") 
	+ strlen("there is no stars in the sky");
	size_t	n;

	n = ft_strlcat(buff1, str, max);
	printf("ft_strlcat: %d\n %s", (int)n, buff1);
	return (0);
}*/
