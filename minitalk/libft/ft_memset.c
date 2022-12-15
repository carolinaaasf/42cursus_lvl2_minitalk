/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:04:25 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 10:45:45 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str2;
	int				i;

	str2 = s;
	i = 0;
	while (n > 0)
	{
		str2[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}

/*int main(void)
{
	char	str[] = "kifdskjf";

	printf("imprime: %s", (char*)ft_memset(str, 'c', 3));
	return 0;
}*/
