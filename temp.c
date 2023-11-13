/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanger <jsanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:58:43 by jsanger           #+#    #+#             */
/*   Updated: 2023/11/13 18:46:02 by jsanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char c)
{
	unsigned int	len1;
	char			*str;

	len1 = strlen(s1);
	str = malloc(sizeof(char) * (len1 + 2));
	if (str == 0)
		return (NULL);
	len1 = 0;
	while (s1[len1] != '\0')
	{
		str[len1] = s1[len1];
		len1++;
	}
	str[len1] = c;
	len1++;
	str[len1] = '\0';
	free(s1);
	return (str);
}
