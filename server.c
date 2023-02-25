/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:37 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/02/25 02:42:56 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void handler(int sig, siginfo_t *inf, void *context )
{
    if (sig == SIGUSR1)
     write (1,"0",1);
    if (sig == SIGUSR2)
        write (1,"1",1);
}

int main(void)
{
    int pid;
	struct sigaction sa;

    pid = (int)getpid();
   ft_putnbr_fd(pid, 1);
   write (1,"\n",1);
	sa.sa_sigaction = &handler;
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
