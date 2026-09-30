/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:18:38 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:18:40 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*t_list;

	t_list = malloc(sizeof(t_node));
	if (t_list == NULL)
		return (NULL);
	t_list->value = value;
	t_list->next = NULL;
	return (t_list);
}
