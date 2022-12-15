/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:56:55 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 11:14:09 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c < -1)
		return ((unsigned char)c);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*#include <ctype.h>
int	main(void)
{
	int	c = -4905;
	printf("%d \n", ft_toupper(c));
	printf("%d", toupper(c));
	return (0);
}*/
