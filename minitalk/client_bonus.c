/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:21:52 by csilva-f          #+#    #+#             */
/*   Updated: 2022/12/21 23:36:38 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

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
					ft_putstr_fd("Error: Failed to send SIGUSR1\n", 1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_putstr_fd("Error: Failed to send SIGUSR2\n", 1);
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
		ft_printf("The signal was received successfully.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					i;

	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			ft_printf("The pid is invalid. Please try again.");
	if (argc != 3 || argv[2] == 0)
	{
		ft_printf("The arguments sent are invalid ");
		ft_printf("(you introduced a wrong nbr of arguments or msg is empty).");
		ft_printf(" Please try again.\n");
	}
	else
	{
		sa_sig.sa_handler = &handler;
		sa_sig.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa_sig, NULL);
		sigaction(SIGUSR2, &sa_sig, NULL);
		send_signal(ft_atoi(argv[1]), argv[2]);
	}
	return (EXIT_SUCCESS);
}
