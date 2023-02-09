/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:45 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/09 21:16:45 by ohaimad          ###   ########.fr       */
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
			usleep(300);
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
