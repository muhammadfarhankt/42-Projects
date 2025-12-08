/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:46:03 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:20:27 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (&str[i]);
}

int	ft_atoi(const char *str)
{
	int			neg;
	long int	res;
	long int	tmp;

	str = ft_isspace(str);
	neg = 1;
	res = 0;
	tmp = 0;
	if (*str == '-')
		neg = -neg;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		tmp = res;
		res = res * 10 + (*str - 48);
		if (tmp > res && neg == 1)
			return (-1);
		else if (tmp > res && neg == 0)
			return (0);
		str++;
	}
	return (res * neg);
}
