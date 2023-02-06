/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:56:47 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/06 13:54:30 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_pid(int a, siginfo_t *src, void *nun)
{
    static char c;
    static int bit;
    static int save;
    static int change; 
    (void)nun;
    
    if(!save)
        save = src->si_pid;
    change = src->si_pid;
    if(save != change)
    {
        save = change;
        c = 0;
        bit = 0;
    }
    c |= (a == SIGUSR1);
    bit ++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
    c <<= 1;
}

int main()
{
    struct sigaction sig;
	sig.sa_sigaction = ft_pid;
	sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    printf("YOUR PID IS : %d\n", getpid());
    while (1)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
}

