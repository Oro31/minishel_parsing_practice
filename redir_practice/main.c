#include "minishell.h"

static void	ft_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_print_str("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
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
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGINT, &action, NULL);
	while (!ret)
		ret = ft_prompt(&cmd);
	printf("exit\n");
	ft_free_list_cmd(&cmd, 1);
	return (0);
}
