/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:38:25 by aalvarad          #+#    #+#             */
/*   Updated: 2026/03/25 13:38:58 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node *tmp;
	
	if (!(*stack_b))
		return;
	tmp = (*stack_a);
	(*stack_a) = (*stack_b)->next;
	tmp->next = NULL;
	stack_add_front(stack_a, tmp);
	write(1, "pa\n", 3);	
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	t_node *tmp;
	
	if (!(*stack_a))
		return;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	stack_add_front(stack_b, tmp);
	write(1, "pb\n", 3);
}