/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:37 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/03/01 04:59:38 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//server :
void handler(int sig, siginfo_t *info, void *context )
{
	static int				bit;
	static unsigned char	c;
	static int				pid;

	if (pid != info->si_pid)
	{
		bit = 0;
		c = 0;
		pid = info->si_pid;
	}	
	if (sig == SIGUSR1)
	{
		c |= 128 >> bit;
		bit++;
	}
	if (sig == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int main(void)
{
	int pid;
	struct sigaction sa;

	pid = (int)getpid();
	ft_printf("here is the process ID : %d\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return -1;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return -1;

	while (1)
		pause();
}
