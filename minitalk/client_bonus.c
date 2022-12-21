/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:21:52 by csilva-f          #+#    #+#             */
/*   Updated: 2022/12/21 23:44:01 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <stddef.h>
#include <unistd.h>

size_t	g_letras = 0;

void	send_signal(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_putstr_fd("Error: Failed to send SIGUSR2\n", 2);
			}
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_letras++;
		ft_printf("The signal was received successfully.\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					i;

	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			ft_printf("The pid is invalid. Please try again.");
	if (argc != 3 || *argv[2] == 0)
		ft_printf("The arguments sent are invalid \
				(wether you introduced a wrong number of arguments or \
				 the message is empty). Please try again.\n");
	else
	{
		sa_sig.sa_handler = &handler;
		sa_sig.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa_sig, NULL);
		send_signal(ft_atoi(argv[1]), argv[2]);
		while (g_letras < ft_strlen(argv[2]))
			pause();
	}
	return (0);
}
