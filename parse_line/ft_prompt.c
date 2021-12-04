#include "minishell.h"

int	ft_is_eof(char *line)
{
	if (!line)
		return (1);
	return (0);
}

int	ft_prompt(char **str)
{
	char	*line;
	int		i;

	if (!g_status)
		ft_print_str("$>");
	line = readline("");
	if (ft_is_eof(line))
	{
		g_status = 0;
		free(line);
		return (1);
	}
	g_status = 0;
	i = 0;
	if (ft_strlen(line) > 0)
	{
		add_history(line);
		*str = ft_str_copy(line);
	}
	return (0);
}
