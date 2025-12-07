/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:42 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/07 12:25:44 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	sublen;
	char	*trimmed;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && is_set(s1[i], set))
		i++;
	j = len - 1;
	while (j > i && is_set(s1[j], set))
		j--;
	sublen = j - i;
	trimmed = (char *)malloc(sizeof(char) * (sublen + 2));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + i, sublen + 1);
	trimmed[sublen + 1] = '\0';
	return (trimmed);
}
