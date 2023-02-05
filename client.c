/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:45 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/05 18:08:20 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                    |  _ \|  _ \ / _ \ / ___|/ _ \                          */
/*                    | | | | |_) | | | | |  _| | | |                         */
/*                    | |_| |  _ <| |_| | |_| | |_| |                         */
/*                    |____/|_| \_\\___/ \____|\___/                          */

#include "minitalk.h"

int main(int ac, char **av)
{
    int a;
    int b;
    unsigned char x;
    (void)ac;

    a = 7;
    b = 0;
    while(av[2][b])
    {
        a = 7;
        while(a >= 0)
        {
            x = ((av[2][b] >> a) & 1);
            if (x == 1)
                kill(atoi(av[1]), SIGUSR1);
            else
                kill(atoi(av[1]), SIGUSR2);
            usleep(200);
            a--;
        }
        b++;
    }
}