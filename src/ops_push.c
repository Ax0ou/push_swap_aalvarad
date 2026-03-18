/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:38:25 by aalvarad          #+#    #+#             */
/*   Updated: 2026/03/18 15:59:44 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	int tmp;
	if (!(*stack_b))
		return;
	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	write(1, "pa\n", 3);	
}