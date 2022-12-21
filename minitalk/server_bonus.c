/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:40:42 by csilva-f          #+#    #+#             */
/*   Updated: 2022/12/21 21:20:02 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/libftprintf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handler(int sig, siginfo_t *info, void *content)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)content;
	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
		return ;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_putstr_fd("Error: Failed to send SIGUSR2\n", 2);
}

int	main(void)
{
	struct sigaction	sa_sig;

	ft_printf("Server process id: %d\n", getpid());
	while (1)
	{
		sa_sig.sa_sigaction = &handler;
		sa_sig.sa_flags	= SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
			ft_putstr_fd("Error: Failed to send SIGUSR1\n", 2);
		if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
			ft_putstr_fd("Error: Failed to send SIGUSR2\n", 2);
	}
	return (0);
}
