/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:22:40 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:22:41 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] != '\0'
		&& str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
