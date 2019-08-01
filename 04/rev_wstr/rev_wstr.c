/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:08:58 by exam              #+#    #+#             */
/*   Updated: 2019/07/25 11:13:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_countwords(char *str)
{
	int	i;
	int	word;

	if (str == NULL)
		return (0);
	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			word++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
	}
	return (word);
}

char	*ft_strsub(char *str, int i, int len)
{
	char *ret;
	int		j;

	if (str == NULL)
		return (NULL);
	j = 0;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (j < len)
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**ft_strsplit(char *str)
{
	int		j;
	char	**arr;
	int		i;
	int 	x;
	int		len;

	if (str == NULL)
		return (NULL);
	len = ft_countwords(str);
	i = 0;
	x = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			j = i;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				i++;
			arr[x] = ft_strsub(str, j, i-j);
			x++;
		}
	}
	arr[x] = NULL;
	return (arr);
}

int		ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_rev_wstr(char *s)
{
	int		i;
	char**	str;
	int		len;

	if (s == NULL || ft_strlen(s) == 0)
		return ;
	len = ft_countwords(s);
	if (len == 0)
		return ;
	i = 0;
	str = ft_strsplit(s);
	while (len > 1)
	{
		len--;
		ft_putstr(str[len]);
		ft_putchar(' ');
	}
	len--;
	ft_putstr(str[len]);
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
	{	
		ft_rev_wstr(av[1]);
	}
	return (0);
}
