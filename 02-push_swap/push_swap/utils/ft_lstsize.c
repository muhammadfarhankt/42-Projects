/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:18:47 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:18:48 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_node *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
