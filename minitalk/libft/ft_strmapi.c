/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:46:31 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 18:40:33 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			size;

	if (!s || !f)
		return (0);
	i = 0;
	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	ft_sum_10(unsigned int n, char st)
{
	return ('5');
}

int	main(void)
{
	char	*str = "1234";

	printf("%s", ft_strmapi(str, ft_sum_10));
	return (0);
}*/
