#include "minishell.h"

static void	ft_handler(int signum)
{
	int	i;
	
	if (signum == SIGINT)
	{
		i = 0;
		rl_on_new_line();
//		rl_replace_line("", 0);
		rl_redisplay();
		ft_print_str("\n");
		g_status = 1;
	}
}

int	main(void)
{
	struct sigaction	action;
	t_cmd				*cmd;
	int					ret;

	action.sa_handler = ft_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	cmd = NULL;
	ret = 0;
	g_status = 0;
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &action, NULL);
	while (!ret || g_status)
		ret = ft_prompt(&cmd);
	printf("exit\n");
//	ft_print_list_cmd(cmd);
//	printf("nb cmd : %d\n", ft_size_list_cmd(cmd));
	return (0);
}
