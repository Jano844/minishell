/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:43:16 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 20:22:35 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **env, char *path)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (ft_strncmp(ft_substr(env[i], 0, j), path, j) == 0)
			return (env[i] + j + 1);
		j = 0;
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(ft_getenv(env, "PATH"), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_2d_array(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free_2d_array(allpath);
	free_2d_array(s_cmd);
	return (cmd);
}
