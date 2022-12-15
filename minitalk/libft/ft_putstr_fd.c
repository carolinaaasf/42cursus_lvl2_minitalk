/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:58:26 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/07 22:34:39 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd < 0 || !s)
		return ;
	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
}

/*#include <fcntl.h>
int	main(void)
{
	int fd = open("testputstr", O_WRONLY | O_CREAT, 0777);
	ft_putstr_fd("abcd", fd);
	close(fd);
	return (0);
}*/
