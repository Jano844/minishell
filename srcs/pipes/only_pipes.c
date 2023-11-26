/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:30:01 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/24 19:10:00 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	combine_lst(t_shell *sh, int pipe_count)
{
	char	**cmd;

	cmd = get_pipe_split(sh->input);
	pipex(pipe_count + 1, cmd, sh);
	free_2d_array(cmd);
}

bool	check_if_only_pipe(t_shell *sh)
{
	combine_lst(sh, sh->tokens);
	return (true);
}
