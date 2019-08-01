/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:23:38 by exam              #+#    #+#             */
/*   Updated: 2019/07/18 13:39:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	int	i;
	int	rep;

	i = 0;
	while (str[i] != '\0')
	{
		rep = 1;
		if (str[i] >= 'a' && str[i] <= 'z')
			rep = str[i] - 96;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			rep = str[i] - 64;
		while (rep > 0)
		{
			ft_putchar(str[i]);
			rep--;
		}
		i++;
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else 
		repeat_alpha(av[1]);
	return (0);
}
