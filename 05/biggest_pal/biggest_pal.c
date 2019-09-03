/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:08:21 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/03 16:53:31 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_pal(char *str, int b, int e)
{
	while (b < e)
	{
		if (str[b] != str[e])
			return (0);
		b++;
		e--;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int begin;
	int end;
	int len;
	int size;
	char *big_pal;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = ft_strlen(av[1]);
	end = len;
	begin = 0;
	size = 0;
	while (av[1][begin] != '\0')
	{
		if ((end - begin + 1) >= size && is_pal(av[1], begin, end))
		{
			size = end - begin + 1;
			big_pal = &av[1][begin];
		}
		end--;
		if (begin > end)
		{
			begin++;
			end = len;
			if (end - begin + 1 < size)
				break ;
		}
	}
	write(1, big_pal, size);
	write(1, "\n", 1);
	return (0);
}
