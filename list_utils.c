/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:14:58 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 12:00:23 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_end(t_list **root, char *x)
{
	t_list	*new_node;
	t_list	*curr;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		exit (1);
	new_node->value = x;
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	deallocate(t_list **root)
{
	t_list	*temp;
	t_list	*curr;

	curr = *root;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*root = NULL;
}

void	add_front(t_list **root, char *x)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		exit(1);
	new_node->value = x;
	new_node->next = *root;
	*root = new_node;
}

void	print_lst(t_list **lst)
{
	t_list	*curr;

	if (lst == NULL || *lst == NULL)
	{
		printf("list is empty\n");
		return ;
	}
	curr = *lst;
	while (curr != NULL)
	{
		printf("%s\n", curr->value);
		curr = curr->next;
	}
}
