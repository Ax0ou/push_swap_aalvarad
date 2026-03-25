/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:13:50 by aalvarad          #+#    #+#             */
/*   Updated: 2026/03/25 14:31:45 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_silent(t_node **stack_a)
{
	t_node *tmp;

	if(!(*stack_a) || stack_size(*stack_a) < 2)
		return;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	stack_add_back(stack_a, tmp);
}

void	ra(t_node **stack_a)
{
	ra_silent(stack_a);
	write(1, "ra\n", 3);
}

void	rb_silent(t_node **stack_b)
{
	t_node	*tmp;

	if(!(*stack_b) || stack_size(*stack_b) < 2)
		return;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	stack_add_back(stack_b, tmp);
}

void	rb(t_node **stack_b)
{
	rb_silent(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra_silent(stack_a);
	rb_silent(stack_b);
	write(1, "rr\n", 3);
}