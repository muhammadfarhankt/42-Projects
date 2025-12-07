/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:51:07 by mfarhan           #+#    #+#             */
/*   Updated: 2025/12/07 13:27:01 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_sz;
	char	*str;

	total_sz = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (total_sz + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_sz + 1);
	ft_strlcat(str, s2, total_sz + 1);
	return (str);
}
