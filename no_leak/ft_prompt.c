/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:33:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/20 19:52:48 by rvalton          ###   ########.fr       */
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

int	ft_prompt()
{
	t_cmd	*cmd;
	char	**cmd_char;
	char	**pipe_char;
	char	*line;
	int	i;

	cmd_char = NULL;
	pipe_char = NULL;
	cmd = NULL;
	line = NULL;
	line = readline("$>");
	if (ft_is_eof(line))
		return (1);
	if (ft_strlen(line) > 0)
	{
		add_history(line);
		if (!ft_parse_error(line))
		{
			free(line);
			printf("syntax error\n");
			return (0);
		}
		pipe_char = ft_pipe_split(line);
		i = -1;
		while (pipe_char[++i])
		{
			cmd_char = ft_cmdline_split(pipe_char[i]);
//			cmd_char = ft_clean_cmdchar(cmd_char);
			cmd = ft_eadd_tolist_cmd(cmd, cmd_char, i);
/*			i = -1;
			while (cmd_char[++i])
				free(cmd_char[i]);
			free(cmd_char);
			cmd_char = NULL;
*/		}
		free(pipe_char);
	}
	if (!cmd)
		free(line);
	else
		ft_free_list_cmd(&cmd);
	return (0);
}
