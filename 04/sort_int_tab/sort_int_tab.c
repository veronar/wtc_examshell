/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:08:58 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 16:32:50 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int    i;

    i = 0;
    while (i + 1 <= size - 1)
    {
        if (tab[i] <= tab[i + 1])
            i++;
        else if (tab[i] > tab[i + 1])
        {
            ft_swap(&tab[i], &tab[i + 1]);
            i = 0;
        }
    }
}
