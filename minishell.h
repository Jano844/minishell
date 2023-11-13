/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:07:05 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 19:22:58 by jsanger          ###   ########.fr       */
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
	char	*input;
	int		tokens;

}		t_shell;

typedef struct s_list
{
	char			*value;
	struct s_list	*next;
}	t_list;

// list utils
void		add_end(t_list **root, char *x);
void		deallocate(t_list **root);
void		add_front(t_list **root, char *x);
void		print_lst(t_list **lst);

// utils
char		**get_env(char **env_stack);
void		free_2d_array(char **arr);
int			array_2d_len(char **arr);
bool		quote_check(t_shell *sh);
t_list		**check_input(t_shell *sh);
int			add_tokens_to_lst(t_list **lst, t_shell *sh, char *c);

// temp
char		*ft_strjoin(char *s1, char c);

#endif