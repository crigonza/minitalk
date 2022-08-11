/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:42:23 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/11 13:23:06 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("ACK  ", 1);
}

void	send_bit(int pid, unsigned char byte)
{
	int	bpos;

	bpos = 0;
	while (bpos < 8)
	{
		if ((byte >> bpos) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bpos++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error.Invalid Arguments", 2);
		exit(EXIT_FAILURE);
	}
	sig.sa_handler = handler;
	sig.sa_flags = 0;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	while (argv[2][i])
	{
		send_bit(ft_atoi(argv[1]), (unsigned char)argv[2][i]);
		i++;
	}
	return (0);
}
