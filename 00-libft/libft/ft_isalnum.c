/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 23:04:32 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:59:06 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isalnum('A'));  // 1
	printf("%d\n", ft_isalnum('z'));  // 1
	printf("%d\n", ft_isalnum('5'));  // 1
	printf("%d\n", ft_isalnum('@'));  // 0
	printf("%d\n", ft_isalnum(' '));  // 0
	printf("%d\n", ft_isalnum(65));   // 1
	printf("%d\n", ft_isalnum(97));   // 1
	return 0;
}
*/
