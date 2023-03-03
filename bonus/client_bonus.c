/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:16 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/03 09:39:56 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	check_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("usage : ./client [pid] [message]!!! \n", 1);
		exit(1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_putstr_fd("INVALID PID \n", 1);
			exit (1);
		}
		i++;
	}
	if (*argv[2] == 0)
	{
		ft_putstr_fd("invalid message !\n", 1);
		exit(1);
	}
	return (0);
}

void	ctob(char car, int s_pid)
{
	int	b;

	b = 8;
	while (b--)
	{
		if ((car >> b) & 1)
		{
			if (kill(s_pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("error!\n", 1);
				exit(1);
			}
		}
		else if (!((car >> b) & 1))
		{
			if (kill(s_pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("error!\n", 1);
				exit(1);
			}
		}
		usleep(300);
	}
}

void	send_mesage(char *msg, int s_pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		ctob(msg[i], s_pid);
	ctob('\0', s_pid);
}

void	respond(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("message sent to the server successfully :D\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	s_pid;
	int	c_pid;

	c_pid = getpid();
	signal(SIGUSR1, respond);
	signal(SIGUSR2, respond);
	ft_putstr_fd("The client process ID :", 1);
	ft_putnbr_fd(c_pid, 1);
	ft_putchar_fd('\n', 1);
	check_errors(argc, argv);
	s_pid = ft_atoi(argv[1]);
	ft_putstr_fd("message currently sending to server..\n", 1);
	send_mesage(argv[2], s_pid);
	return (0);
}
