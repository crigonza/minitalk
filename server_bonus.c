/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:50:44 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/11 13:43:38 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./Libft/libft.h"

void	handler(int signal, siginfo_t *info, void *useless)
{
	static unsigned char	c = 0;
	static int				bpos = 0;

	(void)useless;
	if (signal == SIGUSR1)
		c += 1 << bpos;
	else if (signal == SIGUSR2)
		c += 0 << bpos;
	bpos ++;
	if (bpos == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		bpos = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sact;

	sact.sa_sigaction = &handler;
	sact.sa_flags = SA_SIGINFO;
	sigemptyset(&sact.sa_mask);
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
