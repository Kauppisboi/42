/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:32:19 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/07 17:46:50 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE  32

typedef struct	s_fd
{
	int			fd_id;
	size_t		i;
	char		*res_str;
}				t_fd;

int				ft_get_next_line(const int fd, char **line);

#endif
