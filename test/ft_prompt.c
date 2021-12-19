/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:33:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/19 21:15:41 by rvalton          ###   ########.fr       */
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

	if (*cmd)
		return (0);
	cmd_char = NULL;
	pipe_char = NULL;
	line = NULL;
	k = 0;
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
		pipe_char = ft_pipe_split(line, &k);
		printf("%d\n", k);
		i = -1;
		while (pipe_char[++i])
		{
//			printf("pipe__char=%s\n", pipe_char[i]);
//			cmd_char = ft_cmdline_split(pipe_char[i]);
//			cmd_char = ft_clean_cmdchar(cmd_char);
		}
//		free(pipe_char);
	}
	if (!pipe_char)
		free(line);
	else
	{
		i = 0;
		while (pipe_char[i])
		{
			free(pipe_char[i]);
			i++;
		}
		free(pipe_char);
/*		i = 0;
		while (cmd_char[i])
		{
			free(cmd_char[i]);
			i++;
		}
		free(cmd_char);*/
	}
	return (0);
}
