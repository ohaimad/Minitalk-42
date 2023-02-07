/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:56:47 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/07 23:03:11 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_design(void)
{
	ft_printf(RED "  _____  _     _        _____ ______         _____   \n");
	ft_printf(" / ___ \\| |   | |  /\\  (_____)  ___ \\   /\\  (____ \\  \n");
	ft_printf("| |   | | |__ | | /  \\    _  | | _ | | /  \\  _   \\ \\ \n");
	ft_printf("| |   | |  __)| |/ /\\ \\  | | | || || |/ /\\ \\| |   | |\n");
	ft_printf("| |___| | |   | | |__| |_| |_| || || | |__| | |__/ / \n");
	ft_printf(" \\_____/|_|   |_|______(_____)_||_||_|______|_____/  \n"RESET);
	ft_printf("\n");
	ft_printf(BOLD"\t\tYOUR PID IS : %d\n", getpid());
}

void	ft_pid(int a, siginfo_t *src, void *nun)
{
	static char	c;
	static int	bit;
	static int	save;
	static int	change;

	(void)nun;
	if (!save)
		save = src->si_pid;
	change = src->si_pid;
	if (save != change)
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

int	main(void)
{
	struct sigaction	sig;

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
