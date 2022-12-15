/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:38:11 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 23:40:44 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (0);
}

/*int	main(void)
{
	char	str[] = "abbbbbbbbbbb"; //"tescteteste";
	int		c = 'a';

	printf("%s", ft_strrchr(str, c));
	printf("\n%s", strrchr(str, c));
	return (0);
}*/
