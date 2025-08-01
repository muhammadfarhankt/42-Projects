/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:49:31 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:57:44 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isascii('A'));  // 1
	printf("%d\n", ft_isascii(127));  // 1
	printf("%d\n", ft_isascii(128));  // 0
	printf("%d\n", ft_isascii(-1));   // 0
	printf("%d\n", ft_isascii(65));   // 1
	return 0;
}
*/
