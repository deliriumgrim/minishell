/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:16:48 by tyuuki            #+#    #+#             */
/*   Updated: 2021/12/07 20:05:00 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../includes/minishell.h"

# define FD_MAX 10243
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*prov(char const *s, unsigned int start, size_t len);
#endif
