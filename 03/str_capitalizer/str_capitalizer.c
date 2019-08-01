/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:00:50 by exam              #+#    #+#             */
/*   Updated: 2019/07/18 15:28:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	str_capitalizer(char *str)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')	
	{
		len++;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 32;
	while (len)
	{
		if (str[len] >= 'A' && str[len] <= 'Z')
		   str[len] = str[len] + 32;	
		if (str[len - 1] == ' ' || str[len - 1] == '\t')
		{
			if (str[len] >= 'a' && str[len] <= 'z')
				str[len] = str[len] - 32;
		}
		len--;
	}
	ft_putstr(str);
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else 
	{
		while (i < ac)
		{
			str_capitalizer(av[i]);
			i++;
		}
	}
	return (0);
}
