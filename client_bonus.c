/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:49:38 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/09 21:29:20 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		res;

	res = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (res * signe);
}

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
	ft_printf(BOLD GREEN"FAMA 7AJA ");
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
			if (c == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
			bit--;
		}
		i++;
	}
	if (str[i - 1] != '\n')
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
		char_to_bin("\n", pid);
	}
	else
		ft_printf("Usage: ./client [ pid ] [ str ]");
}
