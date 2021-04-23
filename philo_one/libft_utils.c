/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:26:19 by mbrija            #+#    #+#             */
/*   Updated: 2021/04/23 14:29:27 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int result;

	result = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		result = -((unsigned int)n);
	}
	else
		result = n;
	if (result < 10)
		ft_putchar_fd(result + 48, 1);
	else
	{
		ft_putnbr(result / 10);
		ft_putchar_fd((result % 10) + 48, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i++], 1);
		}
	}
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str, int i)
{
	int		sign;
	int		integer;

	integer = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = (str[i] == 45 ? -1 : 1);
	if (sign == -1)
		return (-1);
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			if ((unsigned long)integer * 10 > 9223372036854775807)
				return (sign == 1) ? -1 : 0;
			integer *= 10;
			integer += str[i] - 48;
		}
		else
			return (integer * sign);
		i++;
	}
	return (integer * sign);
}
