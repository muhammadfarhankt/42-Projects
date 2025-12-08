/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:38 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:27:53 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	let;
	size_t			offset;

	let = c;
	offset = ft_strlen(s);
	ptr = (char *)s + offset;
	if (let == '\0')
		return (ptr++);
	while (ptr >= s)
	{
		if (*ptr == let)
			return (ptr);
		ptr--;
	}
	ptr = NULL;
	return (ptr);
}
