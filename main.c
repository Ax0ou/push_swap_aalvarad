/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:06:54 by aalvard           #+#    #+#             */
/*   Updated: 2026/04/01 10:23:01 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	int		len;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	len = 0;
	numbers = parse_numbers(argc, argv, &len);
	if (!numbers)
		return (0);
	build_stack(&stack_a, numbers, len);
	free(numbers);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, len);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
