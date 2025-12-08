/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:49:28 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:25:02 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	let;

	i = 0;
	let = c;
	if (let == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i++);
	}
	while (s[i])
	{
		if (s[i] == let)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
