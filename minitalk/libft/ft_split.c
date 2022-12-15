/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:51:28 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/08 21:36:10 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(const char *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			n++;
		if (s[i] == c && i != (int)ft_strlen(s) - 1)
		{
			if (s[i + 1] != c)
				n++;
		}
		i++;
	}
	return (n);
}

static void	ft_str_create(const char *s, char **str, char c)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	j = 0;
	len = 0;
	while (s[++i])
	{
		if (s[i] != c)
			len++;
		else
		{
			if (len)
			{
				str[j++] = (char *)malloc(sizeof(char) * (len + 1));
				len = 0;
			}
		}
	}
	if (len)
		str[j] = (char *)malloc(sizeof(char) * (len + 1));
}

static void	ft_str_allocate(const char *s, char **str, char c, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (n > 0)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		k = 0;
		j++;
		n--;
	}
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**str;

	if (!s)
		return (NULL);
	n = ft_n_words(s, c);
	str = malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	ft_str_create(s, str, c);
	ft_str_allocate(s, str, c, n);
	str[n] = 0;
	return (str);
}

/*int	main(void)
{
	char	str[] = "      split       this for   me  !       "; 
	char	**matrix;
	int		i = 0;

	matrix = ft_split(str, ' ');
	while (matrix[i] != 0)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	return (0);
}*/
