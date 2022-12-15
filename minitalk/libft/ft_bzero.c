/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:57:06 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 19:30:19 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str2;
	int				i;

	str2 = s;
	i = 0;
	while (n > 0)
	{
		str2[i] = 0;
		i++;
		n--;
	}
	return (s);
}

/*int main(void)
 { 
 	char	str[] = "kifdskjf";

 	printf("imprime: %s", (char*)ft_bzero(str, 3));
 	return 0;
 }*/
