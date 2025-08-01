/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:49:59 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:57:53 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_isprint(' '));  // 1
	printf("%d\n", ft_isprint('A'));  // 1
	printf("%d\n", ft_isprint('z'));  // 1
	printf("%d\n", ft_isprint(31));   // 0
	printf("%d\n", ft_isprint(127));  // 0
	return 0;
}
*/
