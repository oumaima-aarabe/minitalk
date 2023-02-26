/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:15:37 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/02/26 05:17:21 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//server :
void handler(int sig, siginfo_t *info, void *context )
{
    static int bit;
    static int c;

    printf("handler");
    if (sig == SIGUSR1)
        c |= 1 << bit;
    bit++;
    if (bit == 8)
    {
        printf("%c", c);
        c = 0;
        bit = 0;
    }
    if (sig == SIGUSR2)
        bit++;

}

int main(void)
{
    int pid;
	struct sigaction sa;

    pid = (int)getpid();
    ft_printf("here is the process ID : %d\n", pid);
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
