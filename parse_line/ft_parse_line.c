/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:58:31 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/03 08:59:54 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_split_line(char *line)
{
		t_cmd	*tmp;
		char	*str;
		int		i;
		int		j;
		int		k;

		if (!line)
			return (NULL);
		split = malloc(sizeof(char *));
		split[0] = NULL;
		str = NULL;
		k = 0;
		i = 0;
		while (line[i])
		{
			if (line[i] == ' ')
			{
				if (str)
					split = ft_double_realloc(str, split);
				ft_skip_space(line, &i);
			}
			else if (line[i] == ''');
				ft_handle_simple_quotes(line, &str, &i, &j);
			else if (line[i] == '"')
				ft_handle_double_quotes(line, &str, &i, &j);
			else if (line[i] == '|')
				ft_handle_pipe(line, &i);
			else
				str = ft_realloc(str, line[i]);
			if (line[i])
				i++;
		}
		split = ft_double_realloc(str, split);
}

int	ft_skip_space(char *line, int start)
{
	int	i;

	i = start;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	ft_is_special_char(char c)
{
	if (c == ''' || c == '"' || c == '$' || c == '?' || c == '|')
		return (1);
	return (0);
}

int	ft_is_simple_char(char *line, int i, int j, int quoted)
{
	if (!ft_is_special_char(line[i]))
		return (1);
	if (quoted == 1)
		return (ft_look_for_simple_quote(line, i, j));
	else if (quoted == 2)
		return (ft_look_for_double_quote(line, i, j));
	else
		return (ft_handle_special_char(line, i, j));
}

int	ft_is_quoted(char *line, int i)
{
	int	j;
	int	quoted[2];

	quoted[0] = 0;
	quoted[1] = 0;
	j = 0;
	while (j < i)
	{
		if (line[j] == ''')
		{
			if (quoted[1])
			{
				j++;
				while (j < i && line[j] != ''' && line[j] != '"')
					j++;
				if (line[j] == '"')
					quoted[1] = 0;
				else if (j == i)
				{
					while (line[j] && line[j] != ''' && line[j] != '"')
						j++;
					if (!line[j])
						return (0);
				}
			}
			else
			{
				if (quoted[0])
					quoted[0] = 0;
				else
					quoted[0] = 1;
			}
		}
		else if (line[j] == '"')
		{
			if (quoted[0])
			{
				j++;
				while (j < i && line[j] != ''' && line[j] != '"')
					j++;
				if (line[j] == ''')
					quoted[0] = 0;
				else if (j == i)
				{
					while (line[j] && line[j] != ''' && line[j] != '"')
						j++;
					if (!line[j])
						return (0);
				}
			}
			else
			{
				if (quoted[1])
					quoted[1] = 0;
				else
					quoted[1] = 1;
			}
		}
		j++;
	}
	if (quoted[1])
	{
		while (line[j] && line[j] != ''' && line[j] != '"')
			j++;
		if (!line[j])
			return (0);	
	}
}

int	ft_is_pipe(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '|')
	{
		if (ft_is_quoted(line, i))
			return (0);
		else
			return (1);
	}
	return (0);
}

char	**ft_split_line(char *line)
{
	char	**tmp;
	char	*str;
	int		i;
	int		quoted[2];

	if (!ft_malloc_dblchar(&tmp, 1))
		return (NULL);
	if (!ft_malloc_splchar(&str, 1))
		return (NULL);
	quoted[0] = 0;
	quoted[1] = 0;
	i = 0;
	i = ft_skip_space(line, i);
	while (line[i])
	{
		while (line[i] && !ft_is_pipe(line, i, quoted))
		{
			ft_is_quote_open(line, i, &quoted);
			str = ft_realloc(str, line[i]);
		}
	}	
}
