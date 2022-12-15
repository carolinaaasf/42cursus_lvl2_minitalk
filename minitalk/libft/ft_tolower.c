/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:11:21 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 11:17:06 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c < -1)
		return ((unsigned char)c);
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <ctype.h>
int	main(void)
{
		int	c = 'R';
	printf("%d \n", ft_tolower(c));
	printf("%d", tolower(c));
	return (0);
}*/
