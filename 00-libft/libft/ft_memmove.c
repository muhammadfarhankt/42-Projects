/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:47:04 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:24:04 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dptr;
	const char	*sptr;

	if (src == dst)
		return (dst);
	dptr = dst;
	sptr = src;
	if (sptr < dptr && sptr + len > dptr)
		while (len--)
			*(dptr + len) = *(sptr + len);
	else
	{
		while (len--)
		{
			*dptr = *sptr;
			sptr++;
			dptr++;
		}
	}
	return (dst);
}
