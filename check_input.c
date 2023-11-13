/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:41:25 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 20:14:54 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_tokens_to_lst(t_list **lst, t_shell *sh, char *c)
{
	add_end(lst, c);
	sh->tokens += 1;
	return (1);
}

int	lst_word(t_list **lst, char *arg, int i)
{
	int		count;
	char	*str;

	str = strdup("");
	count = 0;
	while (arg[i] != '\0' && arg[i] != ' '
		&& arg[i] != '\t' && arg[i] != '<' && arg[i] != '>'
		&& arg[i] != '|' && arg[i] != '\"' && arg[i] != '\'')
	{
		str = str_plus_char(str, arg[i]);
		i++;
		count++;
	}
	add_end(lst, str);
	return (count);
}

bool	if_redir(char *arg, int i)
{
	if (arg[i] && arg[i] == '<' && arg[i + 1] && arg[i + 1] == '<')
		return (true);
	else if (arg[i] && arg[i] == '>' && arg[i + 1] && arg[i + 1] == '>')
		return (true);
	else if (arg[i] && arg[i] == '>')
		return (true);
	else if (arg[i] && arg[i] == '<')
		return (true);
	return (false);
}

int	get_redir(t_list **lst, char *arg, int i, t_shell *sh)
{
	int	j;

	j = 0;
	if (arg[i] && arg[i] == '<' && arg[i + 1] && arg[i + 1] == '<')
	{
		add_end(lst, "<<");
		j += 2;
	}
	else if (arg[i] && arg[i] == '>' && arg[i + 1] && arg[i + 1] == '>')
	{
		add_end(lst, ">>");
		j += 2;
	}
	else if (arg[i] && arg[i] == '>')
	{
		add_end(lst, ">");
		j++;
	}
	else if (arg[i] && arg[i] == '<')
	{
		add_end(lst, "<");
		j++;
	}
	sh->tokens += 1;
	return (j);
}

t_list	**check_input(t_shell *sh)
{
	int		i;
	t_list	**lst;

	lst = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	sh->tokens = 0;
	i = 0;
	while (sh->input[i] != '\0')
	{
		while (sh->input[i] && (sh->input[i] == ' ' || sh->input[i] == '\t'))
			i++;
		if (sh->input[i] == '|')
			i += add_tokens_to_lst(lst, sh, "|");
		else if (sh->input[i] == '\'')
			i += add_tokens_to_lst(lst, sh, "\'");
		else if (sh->input[i] == '\"')
			i += add_tokens_to_lst(lst, sh, "\"");
		else if (if_redir(sh->input, i))
			i += get_redir(lst, sh->input, i, sh);
		else if (sh->input[i])
			i += lst_word(lst, sh->input, i);
	}
	return (lst);
}
