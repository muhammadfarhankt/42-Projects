/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:48 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:28:10 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;
	size_t	dstlen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		dstlen = ft_strlen(src) + 1;
	else
		dstlen = len + 1;
	dst = malloc(dstlen * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, dstlen);
	return (dst);
}
