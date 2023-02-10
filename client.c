/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:45 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/10 20:31:36 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		char_to_bin(av[2], pid);
		char_to_bin("\n", pid);
	}
	else
		ft_printf("Usage: ./client [ pid ] [ str ]");
}
