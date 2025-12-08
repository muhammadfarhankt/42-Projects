/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:47:00 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:23:54 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;

	if (!dst && !src)
		return (0);
	if (n == 0 || (dst == src))
		return (dst);
	dptr = dst;
	sptr = src;
	while (n != 0)
	{
		if (*dptr != *sptr)
			*dptr = *sptr;
		dptr++;
		sptr++;
		n--;
	}
	return (dst);
}
