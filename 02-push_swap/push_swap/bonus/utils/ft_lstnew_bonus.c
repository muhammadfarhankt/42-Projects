/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfarhan <mfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:23:04 by mfarhan           #+#    #+#             */
/*   Updated: 2026/09/30 17:23:05 by mfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_node	*ft_lstnew_bonus(int value, int rank)
{
	t_node	*t_list;

	t_list = malloc(sizeof(t_node));
	if (t_list == NULL)
		return (NULL);
	t_list->value = value;
	t_list->rank = rank;
	t_list->next = NULL;
	return (t_list);
}

t_ops	*ft_lstnew_ops_bonus(char *content)
{
	t_ops	*t_list;

	t_list = malloc(sizeof(t_ops));
	if (t_list == NULL)
		return (NULL);
	t_list->content = ft_strdup(content);
	t_list->next = NULL;
	free(content);
	return (t_list);
}
