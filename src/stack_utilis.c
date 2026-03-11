/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:43:24 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/11 17:47:48 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_node **stack, t_node *new) // adresse du pointeur vers le premier node (**stack) && le node qu'on veux ajouter (*new)
{
	t_node	*last;
	if (!stack || !new)
		return;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	last = stack_last(*stack);
	last->next = new;
}

t_node *stack_last(t_node *stack)
{
	t_node	*last;
	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}
