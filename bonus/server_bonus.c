/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:37 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/03 09:35:13 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirmation(unsigned char c, int c_pid)
{
	usleep(100);
	if (kill(c_pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("error!\n", 1);
		exit (1);
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	c;
	static int				c_pid;

	if (c_pid != info->si_pid)
	{
		bit = 0;
		c = 0;
		c_pid = info->si_pid;
	}	
	if (sig == SIGUSR1)
		c |= 128 >> bit++;
	if (sig == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			confirmation(c, c_pid);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = (int)getpid();
	ft_putstr_fd("here is the server process ID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}
