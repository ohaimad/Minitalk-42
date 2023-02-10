/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:29:59 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/10 20:40:59 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	if ((str[i] <= '0' || str[i] >= '9') && str[i] != '\0')
	{
		ft_printf(BOLD RED"invalid PID");
		exit(0);
	}
	return (res);
}
