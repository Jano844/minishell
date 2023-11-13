/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:54:53 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 10:40:06 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(char **env_stack)
{
	int		i;
	int		array_len;
	char	**env;

	i = 0;
	array_len = array_2d_len(env_stack);
	env = malloc(sizeof(char *) * (array_len + 1));
	if (env == NULL)
		return (NULL);
	while (i < array_len)
	{
		env[i] = strdup(env_stack[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	while (i > 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

int	array_2d_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
