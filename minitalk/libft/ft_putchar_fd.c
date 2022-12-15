/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:55:32 by csilva-f          #+#    #+#             */
/*   Updated: 2022/11/06 17:08:38 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*#include <fcntl.h>
int	main(void)
{
	int fd = open("testputchar", O_WRONLY | O_CREAT, 0777);
	ft_putchar_fd('z', fd);
	close(fd);
	return (0);
}*/
