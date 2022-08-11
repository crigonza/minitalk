/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:42:23 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/11 13:16:42 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_byte(int pid, char byte)
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
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error.Invalid Arguments", 2);
		exit(EXIT_FAILURE);
	}
	while (argv[2][i])
	{
		send_byte(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	return (0);
}
