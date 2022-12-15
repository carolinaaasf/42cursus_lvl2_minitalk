/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:59:56 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 22:17:18 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null_str(void)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char) * 1);
	if (substr == NULL)
		return (0);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	lens;

	i = 0;
	if (!s)
		return (0);
	lens = ft_strlen(s);
	if (lens < (size_t)start)
		return (ft_null_str());
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (0);
	while (len > 0 && s[i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

/*int	main(void)
{
	char			str[] = "01234";//"abcdefghijklmn";
	//unsigned int	st = 10;
	size_t			n = 10;
	
	printf("Length s: %d \n", (int)ft_strlen(str));
	printf("Substring: %s", ft_substr(str, 10, n));
	return (0);
}*/
