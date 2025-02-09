/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:21 by iammar            #+#    #+#             */
/*   Updated: 2025/01/31 10:44:19 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_atod(const char *str)
{
    double result = 0.0;
    double fraction = 0.0;
    int sign = 1;
    int decimal_found = 0;
    double divisor = 1.0;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    if (*str == '.')
    {
        decimal_found = 1;
        str++;
        while (*str >= '0' && *str <= '9')
        {
            fraction = fraction * 10 + (*str - '0');
            divisor *= 10;
            str++;
        }
    }

    result += fraction / divisor;

    return sign * result;
}



void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_strlen(char *str)
{
    int i= 0;
    while(str[i])
    {
        i++;
    }
        return i;
}