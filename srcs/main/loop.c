/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:18 by slippert          #+#    #+#             */
/*   Updated: 2023/11/24 19:10:41 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	reset_vars(t_shell *sh)
{
	ft_free(sh->input);
	ft_free(sh->shell_name);
	sh->pipe_builtin = 0;
	sh->has_single_quote = 0;
	sh->is_heredoc = 0;
}

int	read_input(t_shell *sh)
{
	if (!sh->input)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		return (reset_vars(sh), 0);
	}
	else if (sh->input && *sh->input && quote_check(sh))
	{
		check_input(sh, connect(sh->input));
		if (sh->tokens == 0)
			ft_no_tokens(sh);
		else
			check_if_only_pipe(sh);
	}
	return (reset_vars(sh), 1);
}

int	loop(t_shell *sh)
{
	while (sh->is_running)
	{
		sh->input = readline(set_pathname(sh));
		add_history(sh->input);
		if (!read_input(sh))
			return (sh->exitcode);
	}
	return (sh->exitcode);
}
