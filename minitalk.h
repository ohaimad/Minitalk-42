/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:55:11 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/10 20:40:32 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include "printf/ft_printf.h"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

void	ft_design(void);
int		ft_atoi(const char *str);

#endif