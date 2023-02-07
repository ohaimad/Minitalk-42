/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:49:38 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/07 15:50:56 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    char_to_bin(char *str, int pid)
{
        int bit;
        int i;
        unsigned char c;
        
        bit = 7;
        i = 0;
        if (pid <= 0)
        {
            write(1, "Wrong PID", 9);
            exit(0);
        }
        while(str[i])
        {
            bit = 7;
            while(bit >= 0)
            {
                c = ((str[i] >> bit) & 1);
                if (c == 1)
                    kill(pid, SIGUSR1);
                else
                    kill(pid, SIGUSR2);
                usleep(200);
                bit--;
            }
            i++;
        }
}

int main(int ac, char **av)
{
    int pid;
    
    if (ac == 3)
    {
        pid = atoi(av[1]);
        char_to_bin(av[2], pid);
        char_to_bin("\n", pid);
    }
    else
        ft_printf("Usage: ./client [ pid ] [ str ]");
}