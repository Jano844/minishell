/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:07:05 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 10:40:09 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
	char	**env;
	char	**root;
	char	*input;

}		t_shell;

// utils
char		**get_env(char **env_stack);
void		free_2d_array(char **arr);
int			array_2d_len(char **arr);
bool		quote_check(t_shell *sh);

#endif