/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:47:04 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/08 19:31:53 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f || !(*s))
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	ft_function(unsigned int n, char* str)
{
	int	i = -1;
	while (str[++i] != '\0')
		str[i] = '5';
}

int	main(void)
{
	char	str[] = "1234";

	ft_striteri(str, ft_function);
	return (0);
}*/
