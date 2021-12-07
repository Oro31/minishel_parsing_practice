/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:33:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/05 13:10:27 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_eof(char *line)
{
	if (!line)
	{
		g_status = 0;
		free(line);
		return (1);
	}
	return (0);
}

int	ft_prompt(t_cmd **cmd)
{
	char	**cmd_char;
	char	**pipe_char;
	char	*line;
	int		i;
	int		k;

	i = 0;
	k = 0;
	line = readline("$>");
	if (ft_is_eof(line))
		return (1);
	g_status = 0;
	if (ft_strlen(line) > 0)
	{
		add_history(line);
		pipe_char = ft_pipe_split(line, &k);
		while (i <= k)
		{
			cmd_char = ft_cmdline_split(pipe_char[i]);
			*cmd = ft_hadd_tolist_cmd(*cmd, cmd_char, (i % 1), i);
			i++;
		}
		ft_print_list_cmd(*cmd);
	}
	return (0);
}
