/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammar <iammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:52:21 by iammar            #+#    #+#             */
/*   Updated: 2025/02/21 15:15:22 by iammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	t_atoi	strr;

	strr = (t_atoi){0};
	strr.d = 1;
	strr.s = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			strr.s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		strr.r = strr.r * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			strr.f = strr.f * 10 + (*str++ - '0');
			strr.d *= 10;
		}
	}
	return (strr.s * (strr.r + strr.f / strr.d));
}

int	ft_isdigit(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
			str++;
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
