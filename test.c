/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:05:48 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 20:32:21 by jsanger          ###   ########.fr       */
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

bool	init(t_shell *sh, int argc, char **argv, char **env)
{
	if (argv)
	{
		if (argc > 1)
		{
			printf("Too many arguments!\n");
			exit(1);
		}
		sh->env = get_env(env);
	}
	return (true);
}

void	loop(t_shell *sh)
{
	t_list	**lst;

	lst = NULL;
	while (1)
	{
		sh->input = readline("minishell> ");
		if (sh->input && *sh->input)
		{
			if (quote_check(sh) == false)
				continue ;
			lst = check_input(sh);
			if (sh->tokens == 0)
				ft_no_tokens(sh);
			add_history(sh->input);
			free(sh->input);
			if (!(lst == NULL))
				deallocate(lst);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell	sh;

	init(&sh, argc, argv, env);
	loop(&sh);
}
