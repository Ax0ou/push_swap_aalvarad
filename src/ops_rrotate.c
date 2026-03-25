/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:41:10 by aalvarad          #+#    #+#             */
/*   Updated: 2026/03/25 16:44:22 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_silent(t_node **stack_a)
{
	t_node *tmp;
	t_node *last;

	if (!(*stack_a) || !(*stack_a)->next)
		return;
	last = (*stack_a);
	while (last->next->next)
    	last = last->next;
	tmp = last->next;
	last->next = NULL;
	stack_add_front(stack_a, tmp);	
}

void	rra(t_node **stack_a)
{
	rra_silent(stack_a);
	write(1, "rra\n", 4);
}

void	rrb_silent(t_node **stack_b)
{
	t_node *tmp;
	t_node *last;

	if (!(*stack_b) || !(*stack_b)->next)
		return;
	last = (*stack_b);
	while (last->next->next)
    	last = last->next;
	tmp = last->next;
	last->next = NULL;
	stack_add_front(stack_b, tmp);
}

void	rrb(t_node **stack_b)
{
	rrb_silent(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra_silent(stack_a);
	rrb_silent(stack_b);
	write(1, "rrr\n", 4);
}

