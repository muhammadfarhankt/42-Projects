/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:54:07 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:57:49 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isdigit('0'));  // 1
	printf("%d\n", ft_isdigit('5'));  // 1
	printf("%d\n", ft_isdigit('9'));  // 1
	printf("%d\n", ft_isdigit('a'));  // 0
	printf("%d\n", ft_isdigit(' '));  // 0
	printf("%d\n", ft_isdigit(10));   // 0
	return 0;
}
*/
