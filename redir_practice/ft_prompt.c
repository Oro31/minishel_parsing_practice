/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:33:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/17 02:24:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_eof(char *line)
{
	if (!line)
	{
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
	int	i;
	int	k;

	i = 0;
	k = 0;
	line = readline("$>");
	if (ft_is_eof(line))
		return (1);
	if (ft_strlen(line) > 0)
	{
		add_history(line);
		pipe_char = ft_pipe_split(line, &k);
		while (i <= k)
		{
			j = -1;
			cmd_char = ft_cmdline_split(pipe_char[i]);
			cmd_char = ft_dollar_parse(cmd_char);
			cmd_char = ft_clean_cmdchar(cmd_char);
			*cmd = ft_eadd_tolist_cmd(*cmd, cmd_char, i, i);
			i++;
		}
		ft_print_list_cmd(*cmd);
		ft_free_list_cmd(cmd, 0);
	}
	return (0);
}
