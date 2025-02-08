#include "minishell.h"

t_pids	*new_pids(pid_t pid)
{
	t_pids	*lst;

	lst = (t_pids *)xmalloc(sizeof(t_pids));
	lst->pid = pid;
	lst->next = NULL;
	return (lst);
}

void	print_pids(t_pids *pids)
{
	t_pids	*node;

	node = pids;
	while (node)
	{
		dprintf(2, "pid : %d\n", node->pid);
		node = node->next;
	}
	return ;
}

t_pids	*last_pid(t_pids *lst)
{
	t_pids	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	addback_pid(t_pids **lst, t_pids *newpid)
{
	t_pids	*last;

	last = last_pid(*lst);
	newpid->next = NULL;
	if (!last)
	{
		*lst = newpid;
	}
	else
	{
		last->next = newpid;
	}
}

int	pids_size(t_pids *pids)
{
	t_pids	*node;
	int		ans;

	ans = 0;
	node = pids;
	while (node)
	{
		ans++;
		node = node->next;
	}
	return (ans);
}
