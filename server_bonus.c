/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:28:11 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/07 15:51:09 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_design()
{
    ft_printf(RED BOLD " _______           _______ _________ _______  _______  ______  \n");
    ft_printf("(  ___  )|\\     /|(  ___  )\\__   __/(       )(  ___  )(  __  \\ \n");
    ft_printf("| (   ) || )   ( || (   ) |   ) (   | () () || (   ) || (  \\  )\n");
    ft_printf("| |   | || (___) || (___) |   | |   | || || || |   | || |   ) |\n");
    ft_printf("| |   | ||  ___  ||  ___  |   | |   | |(_)| || |   | || |   | |\n");
    ft_printf("| |   | || (   ) || (   ) |   | |   | |   | || |   | || |   ) |\n");
    ft_printf("| (___) || )   ( || )   ( |___) (___| )   ( || (___) || (__/  )\n");
    ft_printf("(_______)|/     \\||/     \\|\\_______/|/     \\|(_______)(______/ \n" RESET);
    ft_printf("\n");
    ft_printf(BOLD"\t\tYOUR PID IS : %d\n", getpid());
}

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
	sig.sa_sigaction = ft_pid;
	sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    ft_design();
    while (1)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
}