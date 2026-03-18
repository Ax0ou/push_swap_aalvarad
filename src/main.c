/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:06:54 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/17 18:03:25 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  int *numbers;
  t_node *stack_a = NULL;
  int len = 0;
	
  numbers = parse_numbers(argc, argv, &len);
  if (!numbers)
    return (0);
	build_stack(&stack_a, numbers, len);
  free(numbers);
  stack_clear(&stack_a);
  return (0);
}