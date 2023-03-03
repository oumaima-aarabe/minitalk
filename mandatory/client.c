/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:16 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/03 09:33:57 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	int	s_pid;

	check_errors(argc, argv);
	s_pid = ft_atoi(argv[1]);
	send_mesage(argv[2], s_pid);
	return (0);
}
