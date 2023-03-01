/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:16 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/01 06:00:09 by ouaarabe         ###   ########.fr       */
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

void ctob(char car, int s_pid)
{
	int b;

	b = 8;

	while (b--)
	{
		if ((car >> b) & 1)
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				ft_printf("error!");
				exit(1);
			}
		}
		else if(!((car >> b) & 1))
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				ft_printf("error!");
				exit(1);
			}
		}
		usleep(300);
	}
}

void    send_mesage(char *msg, int s_pid)
{
	int i;

	i = -1;
	while (msg[++i])
		ctob(msg[i], s_pid);
	ctob('\0', s_pid);
}

void	respond (int signal)
{
	if(signal == SIGUSR1)
	{
		ft_printf("message sent to the server successfully\n");
		exit(0);
	}
	
}
int main(int argc, char **argv)
{
	int s_pid;
	int c_pid;
	
	c_pid = getpid();
	signal(SIGUSR1, respond);
	signal(SIGUSR2, respond);
	ft_printf ("The client process ID : %d\n", c_pid);
	check_errors(argc, argv);
	s_pid = ft_atoi(argv[1]);
	ft_printf("message currently sending to server\n");
	send_mesage(argv[2], s_pid);
	return (0); 
}
