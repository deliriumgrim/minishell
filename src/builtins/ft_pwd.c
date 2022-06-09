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

int	ft_pwd(t_minishell *shell)
{
	char	buf[PATH_MAX + 1];

	if (!getcwd(buf, PATH_MAX + 1))
	{
		ft_putstr_fd(strerror(errno), 1);
		shell->exit_status = 128;
		return (TRUE);
	}
	ft_putstr_fd(buf, 1);
	write(1, "\n", 1);
	shell->exit_status = 0;
	return (TRUE);
}
