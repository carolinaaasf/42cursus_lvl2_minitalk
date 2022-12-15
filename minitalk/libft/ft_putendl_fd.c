/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:20:56 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 22:35:33 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	if (fd < 0 || !s)
		return ;
	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
	ft_putchar_fd('\n', fd);
}

/*#include <fcntl.h>
int	main(void)
{
	int fd = open("testputendl", O_WRONLY | O_CREAT, 0777);
	ft_putendl_fd("abcd", fd);
	close(fd);
	return (0);
}*/
