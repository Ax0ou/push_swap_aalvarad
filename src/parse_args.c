/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:57 by aalvard           #+#    #+#             */
/*   Updated: 2026/03/09 18:46:08 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**tokens_from_argv(int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		j;

	tokens = malloc(sizeof(char *) * argc);
	if (!tokens)
		error_exit();
	i = 1;
	j = 0;
	while (i < argc)
	{
		tokens[j] = ft_strdup(argv[i]);
		if (!tokens[j])
		{
			tokens[j] = NULL;
			free_tokens(tokens);
			error_exit();
		}
		i++;
		j++;
	}
	tokens[j] = NULL;
	return (tokens);
}

char	**get_tokens(int argc, char **argv)
{
	char	**tokens;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (!tokens)
			error_exit();
		if (!tokens[0])
		{
			free_tokens(tokens);
			error_exit();
		}
		return (tokens);
	}
	return (tokens_from_argv(argc, argv));
}
