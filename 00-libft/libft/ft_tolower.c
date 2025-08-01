/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:33:07 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:58:13 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include<stdio.h>
int main()
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('Z'));
	printf("%c\n", ft_tolower('z'));
	printf("%c\n", ft_tolower('1'));
	return 0;
}
*/
