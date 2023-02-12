/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:49:38 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/12 03:00:19 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sending(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(800);
	}
}

void	handling(int a)
{
	(void) a;
	ft_printf(BOLD GREEN"RECU ");
}

void	ft_protect(unsigned char c, int pid)
{
	if (c == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf(BOLD RED"invalid PID");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf(BOLD RED"invalid PID");
			exit(0);
		}
	}
}

void	char_to_bin(char *str, int pid)
{
	int				bit;
	int				i;
	unsigned char	c;

	bit = 7;
	i = 0;
	if (pid <= 0)
		exit(0);
	while (str[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			c = ((str[i] >> bit) & 1);
			ft_protect(c, pid);
			usleep(800);
			bit--;
		}
		i++;
	}
	sending(pid);
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, handling);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		char_to_bin(av[2], pid);
	}
	else
		ft_printf("Usage: ./client [ pid ] [ str ]");
}
