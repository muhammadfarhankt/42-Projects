/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:01:03 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:57:35 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isalpha('A'));  // 1
	printf("%d\n", ft_isalpha('z'));  // 1
	printf("%d\n", ft_isalpha('1'));  // 0
	printf("%d\n", ft_isalpha(' '));  // 0
	printf("%d\n", ft_isalpha(65));   // 1
	printf("%d\n", ft_isalpha(97));   // 1
	return 0;
}
*/
