/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 09:21:43 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/03 16:54:21 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		check_brackets(char a, char b)
{
	if (a == '[' && b == ']')
		return (1);
	else if (a == '(' && b == ')')
		return (1);
	else if (a == '{' && b == '}')
		return (1);
	else
		return (0);
}

int		brackets(char *str)
{
	int i;
	int top;
	int stack[4096];

	i = 0;
	top = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			stack[++top] = str[i];
		if (str[i] == ']' || str[i] == '}' || str[i] == ')')
			if(!check_brackets(stack[top--], str[i]))
					return (0);
		i++;
	}
	return (!top);
}

int 	main(int ac, char **av)
{
	int i;

	if (ac == 1)
	{
		ft_putendl("");
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (brackets(av[i]))
			ft_putendl("OK");
		else
			ft_putendl("Error");
		i++;
	}
	return (0);
}
