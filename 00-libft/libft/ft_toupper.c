/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:32:58 by mfarhan           #+#    #+#             */
/*   Updated: 2025/07/31 22:35:35 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include<stdio.h>
int main()
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('z'));
	printf("%c\n", ft_toupper('Z'));
	printf("%c\n", ft_toupper('1'));
	return 0;
}
*/
