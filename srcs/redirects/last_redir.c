/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:26:34 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/27 00:11:07 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*is_last_redir(char *cmd, char c, int i, int check)
{
	int	temp;
	int	append;

	append = 10241024;
	temp = 0;
	while (cmd[i] && (cmd[i] != c || (check == (append == i - 1))))
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
			i += count_while_in_qoutes(cmd, cmd[i], i);
		else if (cmd[i] == '\0')
			break ;
		if (cmd[i] == c)
		{
			if (i != 0 && cmd[i - 1] == c)
				append = i - 1;
			else
				append = i;
		}
		i++;
	}
	if (check == 0)
		return (cmd += append);
	else
		return (cmd += append - 1);
}
