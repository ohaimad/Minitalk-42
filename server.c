/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:56:47 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/05 18:13:39 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_test(int a, siginfo_t *src, void *nun)
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
    c = c | (a == SIGUSR1);
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
	sig.sa_sigaction = ft_test;
	sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    printf("%d\n", getpid());
    while (1)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
}

