#include "minishell.h"

int	ft_is_eof(char *line)
{
	if (!line)
		return (1);
	return (0);
}

int	ft_prompt(t_cmd **ppt)
{
	char	*line;

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
	else if (ft_strlen(line) > 0)
	{
		add_history(line);
		*ppt = ft_split_line(line);
		/**ppt = ft_hadd_tolistr(*ppt, str);*/
	}
	return (0);
}
