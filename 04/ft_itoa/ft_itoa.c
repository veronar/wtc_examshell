/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:08:58 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 16:32:53 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_intlen(int n)
{
    int len;

    len = 0;
    if (n == 0)
        return (1);
    if (n < 0)
    {
        len++;
        n = n * -1;
    }
    while (n)
    {
        len++;
        n = n / 10;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    int     len;
    char    *ret;
    int     neg;
    int     sign;

    neg = 0;
    sign = 1;
    len = ft_intlen(n);
    if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
        return (NULL);
    ret[len] = '\0';
    if (n < 0)
    {
        ret[0] = '-';
        neg = 1;
        sign = -1;
    }
    while (len > neg)
    {
        len--;
        ret[len] = '0' + (n % 10) * sign;
        n = n / 10;
    }
    return (ret);
}