/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quoted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:36:54 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/03 08:59:57 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_quote_open(char *line, int i, int j, int **quoted)
{
	while (j < i)
	{
		if (line[j] != ''' && line[j] != '"')
			j++;
		else if (line[j] == ''' && !*quoted[0])
			*quoted[0] = 1;
		else if (line[j] == '"' && !*quoted[1])
			*quoted[1] = 1;
	}	
}

int	ft_is_quote_close(char *line, int i, int j, int **quoted)
{
	
}

int	ft_is_quoted(char *line, int i)
