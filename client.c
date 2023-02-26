/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:16 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/02/26 08:24:58 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


//client :

int     check_errors(int argc, char **argv)
{
    int i = 0;
    if (argc != 3)
    {
       ft_printf("usage : ./client [pid] [message]!!! \n");
        return 1;
    }
    while (argv[1][i])
    {
        if (!ft_strchr("0123456789", argv[1][i]))
        {
            ft_printf("The PID of an individual process should be an integer with a positive value! \n");
            return (1);
        }
        i++;
    }
    return (0);
}

void ctob(char car, int pid)
{
    int b;

    b = 8;

    while (--b >= 0)
    {
        if ((car >> b) & 1)
            kill(pid, SIGUSR1);
        else if(!((car >> b) & 1))
            kill(pid, SIGUSR2);

    }
    usleep(100);
}

void    send_mesage(char *msg, int pid)
{
    int i;

    i = -1;
    while (msg[++i])
        ctob(msg[i], pid);
    ctob('\0', pid);
}

int main(int argc, char **argv)
{
    int pid;

    if (check_errors(argc, argv))
        return 1;
    pid = ft_atoi(argv[1]);
    send_mesage(argv[2], pid);
    return (0);   
}
