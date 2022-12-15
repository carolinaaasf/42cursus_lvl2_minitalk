/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:40:11 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 22:24:22 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_i(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		flag = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_find_k(char const *s1, char const *set, int i)
{
	int	lens1;
	int	k;
	int	j;
	int	flag;

	lens1 = ft_strlen(s1);
	k = lens1 - 1;
	while (k >= i)
	{
		j = 0;
		flag = 0;
		while (set[j] != '\0')
		{
			if (s1[k] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			break ;
		k--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		lensub;
	char	*sub;

	if (!s1)
		return (0);
	i = ft_find_i(s1, set);
	k = ft_find_k(s1, set, i);
	if (i == k)
		lensub = 1;
	else
		lensub = k - i + 1;
	sub = (char *)malloc(lensub * sizeof(char) + 1);
	if (sub == NULL)
		return (0);
	j = -1;
	while (++j < lensub)
		sub[j] = s1[i + j];
	sub[j] = '\0';
	return (sub);
}

/*int	main(void)
{
	char	s1[] = "aabccabcatarinaabc";
	char	s2[] = "abc";
	
	printf("%s", ft_strtrim(s1, s2));
	return (0);
}*/
