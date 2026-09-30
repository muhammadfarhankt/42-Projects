/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:22:47 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:22:48 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	ft_copy_bonus(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	strlen_mod_bonus(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static char	**free_the_split_bonus(char **res, int words)
{
	while (words)
	{
		free (res[words]);
		words--;
	}
	free(res);
	return (NULL);
}

char	**ft_split_bonus(char *str, char c, int i, int j)
{
	char	**res;
	int		words;

	words = strlen_mod_bonus(str, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			res[words] = malloc(sizeof(char) * ((i - j) + 1));
			if (!res[words])
				return (free_the_split_bonus(res, words));
			(ft_copy_bonus (res[words], &str[j], (i - j)), words++);
		}
	}
	return (res[words] = NULL, res);
}
