/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:16 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/01 05:00:39 by ouaarabe         ###   ########.fr       */
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
		exit(1);
	}
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("The PID of an individual process should be an integer with a positive value! \n");
			exit(1);
		}
		i++;
	}
	return (0);
}

void ctob(char car, int pid)
{
	int b;

	b = 8;

	while (b--)
	{
		if ((car >> b) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("error!");
				exit(1);
			}
		}
		else if(!((car >> b) & 1))
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("error!");
				exit(1);
			}
		}
		usleep(300);
	}
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
	int s_pid;
	int c_pid;
	
	check_errors(argc, argv);
	s_pid = ft_atoi(argv[1]);
	send_mesage(argv[2], s_pid);
	return (0); 
}
