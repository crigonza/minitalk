/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:50:44 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/05 18:11:14 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "./Libft/libft.h"

void    handler(int signal)
{
    static char c = 0;
    static int  bpos = 0;

    if( signal == SIGUSR1)
        c += 1 << bpos;
    else if (signal == SIGUSR2)
        c += 0 << bpos;
    bpos ++;
    if (bpos == 8)
    {
        ft_putchar_fd(c, 1);
        c = 0;
        bpos = 0;
    }
}

int main(void)
{
    struct sigaction    sact;

    sact.sa_handler = handler;
    sact.sa_flags = 0;
    sigemptyset(&sact.sa_mask);
    sigaction(SIGUSR1, &sact, NULL);
    sigaction(SIGUSR2, &sact, NULL);
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
    while (1)
        pause();
    return(0);
}
