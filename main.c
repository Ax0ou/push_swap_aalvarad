/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:06:54 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/27 14:35:05 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
  int *numbers;
  int len;
  t_node *stack_a = NULL;
  t_node *stack_b = NULL;

  len = 0;
  numbers = parse_numbers(argc, argv, &len);
  if (!numbers)
    return (0);
  build_stack(&stack_a, numbers, len);
  free(numbers);

  if (!is_sorted(stack_a))
  {
    if (len == 2)
      sort_two(&stack_a);
    else if (len == 3)
      sort_three(&stack_a);
    else if (len == 5)
      sort_five(&stack_a, &stack_b);

  }
  stack_clear(&stack_a);
  stack_clear(&stack_b);
  return (0);
}
