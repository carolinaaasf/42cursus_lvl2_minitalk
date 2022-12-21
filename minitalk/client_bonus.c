/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:21:52 by csilva-f          #+#    #+#             */
/*   Updated: 2022/12/20 23:33:07 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <signal.h>
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
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

void	handler(int sig, siginfo_t *info, void *content)
{
	ft_printf("Caracter recebido\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	struct sigaction	sa_sig;

	if (argc != 3)
		ft_printf("The client must receive 2 parameters: the server PID and the string to send. Please try again.\n");
	else
	{	sa_sig.sa_sigaction = &handler;
		sa_sig.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
			ft_putstr_fd("Error: Failed to send SIGUSR1 \n", 2);
		send_signal(ft_atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
	return (0);
}
