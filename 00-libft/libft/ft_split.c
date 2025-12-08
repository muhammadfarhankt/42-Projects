/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:49:22 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/09 02:24:55 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

static int	count_words(const char *s, char c)
{
	int	word_len;
	int	i;

	word_len = 0;
	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
	{
		if (*s)
			return (1);
		else
			return (0);
	}
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			word_len++;
		i++;
	}
	return (word_len);
}

static void	*free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		str;
	int		ptr;
	int		words;
	int		len;
	char	**res;

	if (!s)
		return (NULL);
	str = 0;
	ptr = 0;
	words = count_words(s, c);
	res = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (str < words)
	{
		while (s[ptr] && (s[ptr] == c))
			ptr++;
		len = str_len((s + ptr), c);
		res[str++] = ft_substr(s, ptr, len);
		if (!res[str - 1])
			return (free_split(res));
		ptr += len;
	}
	return (res);
}
