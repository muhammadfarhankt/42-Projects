/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:12 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/06 19:46:48 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	sum;

	i = 0;
	sum = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > dest_len)
		sum = dest_len + src_len;
	else
		return (src_len + size);
	while (src[i] && (dest_len + 1) < size)
		dst[dest_len++] = src[i++];
	dst[dest_len] = '\0';
	return (sum);
}
