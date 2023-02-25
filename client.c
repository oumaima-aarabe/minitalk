/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:16 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/02/25 04:09:56 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int     check_errors(int argc, char **argv)
{
    int i = 0;
    if (argc != 3)
    {
        ft_putstr_fd("usage : ./client [pid] [message]!!! \n", 1);
        return 1;
    }
    while (argv[1][i])
    {
        if (!ft_strchr("0123456789", argv[1][i]))
        {
            ft_putstr_fd("The PID of an individual process should be an integer with a positive value! \n", 1);
            return (1);
        }
        i++;
    }
    return (0);
}

void ctob(char car)
{
    int b;

    b = -1;
    while (b < 8)
    {
        if ((car << 7) & 0b1)
        {
            if (kill())
        }
        car = car >> 1;
    }
}

void    send_mesage(char *msg)
{
    int i;

    i = -1;
    while (msg[++i])
        ctob(msg[i]);
}

int main(int argc, char **argv)
{
    int pid;

    check_errors(argc, argv);
    pid = ft_atoi(argv[1]);
    send_mesage(argv[2]);
    kill(pid, SIGUSR1);
    kill(pid, SIGUSR2);
    
}
