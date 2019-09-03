/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:08:58 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 16:43:24 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putendl(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int i = 1;
	int t[32] = {0};
	int j = 0;

	if (argc == 1)
	{
		ft_putendl("options: abcdefghijklmnopqrstuvwxyz");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j] && argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				if (argv[i][j] == 'h')
				{
					ft_putendl("options: abcdefghijklmnopqrstuvwxyz");
					return (0);
				}
				t['z' - argv[i][j] + 6] = 1;
				j++;
			}
			if (argv[i][j])
			{
				ft_putendl("Invalid Option");
				return (0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		t[i] = '0' + t[i];
		write(1, &t[i++], 1);
		if (i == 32)
			write(1, "\n", 1);
		else if (i % 8 == 0)
			write(1, " ", 1);
	}
	return (0);
}