/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:49:37 by mfarhan           #+#    #+#             */
/*   Updated: 2025/08/01 22:57:57 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
/*
#include <stdio.h>
int main(void)
{
	char str[100];
	printf("Enter a string : ");
	scanf("%s", str);
	int length = ft_strlen(str);
	printf("Length of string : %d\n", length);
	return 0;
}
*/
