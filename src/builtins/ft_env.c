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

char	*return_full_path_env(char *path)
{
	char	*tmp;
	char	*full_path;
	char	*name;

	tmp = ft_strjoin(path, "/");
	name = ft_strdup("env");
	full_path = ft_strjoin(tmp, name);
	free(name);
	free(tmp);
	return (full_path);
}

int	norm_help_path(char **path, char ***paths)
{
	if (!access(*path, F_OK))
	{
		ft_freex2arr(*paths);
		free(*path);
		return (FALSE);
	}
	free(*path);
	return (TRUE);
}

int	find_path_env(t_minishell *shell)
{
	t_elem	*tmp_env;
	char	**paths;
	char	*path;
	int		i;

	tmp_env = shell->env;
	while (tmp_env && ft_strcmp((char *)tmp_env->key, "PATH"))
	tmp_env = tmp_env->next;
	if (!tmp_env || *(char *)tmp_env->value == '\0')
		return (TRUE);
	else
	{
	i = 0;
	paths = ft_split(tmp_env->value, ':');
		while (paths[i])
		{
			path = return_full_path_env(paths[i]);
			if (!norm_help_path(&path, &paths))
				return (FALSE);
			i++;
		}
		ft_freex2arr(paths);
		return (TRUE);
	}
}

int	ft_env(t_minishell *shell)
{
	t_elem	*tmp;

	tmp = shell->env;
	if (find_path_env(shell))
	{
		ft_error(E_CNF, NULL);
		shell->exit_status = 127;
		return (TRUE);
	}
	while (tmp)
	{
		ft_putstr_fd((char *)tmp->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd((char *)tmp->value, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		tmp = tmp->next;
	}
	shell->exit_status = 0;
	return (TRUE);
}
