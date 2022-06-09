/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:31:05 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	check_istoken(t_elem **tmp)
{
	while (*tmp && ft_istoken((*tmp)->key_t))
		*tmp = (*tmp)->next;
	if (!*tmp)
		return (TRUE);
	return (FALSE);
}

void	return_full_path(char *path, t_minishell *shell, t_elem *tmp_c)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	shell->exec->path = ft_strjoin(tmp, (char *)tmp_c->value);
	free(tmp);
}

void	find_path_help(t_elem *tmp, t_minishell *shell, char **paths)
{
	if (*(char *)tmp->value == '.' || *(char *)tmp->value == '/')
		shell->exec->path = ft_strdup(tmp->value);
	else
		shell->exec->path = ft_strdup("");
	ft_freex2arr(paths);
}

void	check_path(t_minishell *shell, t_elem *path, t_elem *token)
{
	char	**paths;
	int		i;
	t_elem	*tmp;

	tmp = token;
	if (shell->exec->path)
		free(shell->exec->path);
	if (check_istoken(&tmp))
		return ;
	paths = ft_split(path->value, ':');
	i = 0;
	while (paths[i])
	{
		return_full_path(paths[i], shell, tmp);
		if (!access(shell->exec->path, F_OK))
		{
			ft_freex2arr(paths);
			return ;
		}
		free(shell->exec->path);
		i++;
	}
	find_path_help(tmp, shell, paths);
}

void	find_path(t_minishell *shell, t_elem *token)
{
	t_elem	*tmp_env;
	t_elem	*tmp_token;

	tmp_env = shell->env;
	shell->exec->path = NULL;
	while (tmp_env && ft_strcmp((char *)tmp_env->key, "PATH"))
		tmp_env = tmp_env->next;
	if (!tmp_env || *(char *)tmp_env->value == '\0')
	{
		tmp_token = token;
		while (ft_istoken(tmp_token->key_t))
			tmp_token = tmp_token->next;
		shell->exec->path = ft_strjoin("./", tmp_token->value);
	}
	else
		check_path(shell, tmp_env, token);
}
