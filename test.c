/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:05:48 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 10:40:41 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	quote_check(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->input[i])
	{
		if (sh->input[i] && sh->input[i] == '\'')
		{
			i++;
			while (sh->input[i] && sh->input[i] != '\'')
				i++;
			if (sh->input[i] != '\'')
				return (printf("Quotes not closed\n"), false);
		}
		if (sh->input[i] && sh->input[i] == '\"')
		{
			i++;
			while (sh->input[i] && sh->input[i] != '\"')
				i++;
			if (sh->input[i] != '"')
				return (printf("Quotes not closed\n"), false);
		}
		i++;
	}
	return (true);
}

bool	init(t_shell *sh, int argc, char **env)
{
	if (argc > 1)
	{
		printf("Too many arguments!\n");
		exit(1);
	}
	sh->env = get_env(env);
	return (true);
}

void	loop(t_shell *sh)
{
	while (1)
	{
		sh->input = readline("minishell> ");
		if (sh->input && *sh->input)
		{
			if (quote_check(sh))
				continue ;
			check_input(sh);
			printf("%s\n", sh->input);
			add_history(sh->input);
			free(sh->input);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	sh;

	init(&sh, argc, env);
	loop(&sh);
}
