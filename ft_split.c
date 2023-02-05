/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:08:31 by ohaimad           #+#    #+#             */
/*   Updated: 2023/02/03 15:15:34 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char **ft_split(char *s)
{
    char **str;
    int i;
    int len;

    len = ft_strlen(s) + 1;
    str = malloc(sizeof(char *)*len);
    while(s[i] != '\0')
    {
        s[i] = malloc(2);
        str[i][0] = s[i];
        str[i][1] = '\0';
        i++;
    }
    srt[i] = NULL;
    return(str);
}
