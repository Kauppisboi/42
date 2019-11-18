/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:31:55 by ttampio           #+#    #+#             */
/*   Updated: 2019/11/08 08:24:35 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd	*ft_return_fd_ses(int fd, t_list **fd_lst)
{
	char	*res_str;
	t_fd	*fd_ses;
	t_list	*new_node;
	t_list	*cur;

	cur = *fd_lst;
	while (cur)
	{
		if (((t_fd*)cur->content)->fd_id == fd)
			return (cur->content);
		cur = cur->next;
	}
	fd_ses = (void*)malloc(sizeof(t_fd));
	res_str = ft_strnew(0);
	fd_ses->res_str = res_str;
	fd_ses->fd_id = fd;
	fd_ses->i = 0;
	new_node = ft_lstnew((void*)fd_ses, sizeof(t_fd));
	free(fd_ses);
	ft_lstadd(fd_lst, new_node);
	return (new_node->content);
}

static int	ft_handle_stream(t_fd *fd_ses, char **line)
{
	size_t	ln_brk_pos;
	char	*tmp;

	ln_brk_pos = ft_strchri(fd_ses->res_str + fd_ses->i, '\n');
	*line = ft_strsub(fd_ses->res_str, fd_ses->i, ln_brk_pos);
	fd_ses->i += ln_brk_pos + 1;
	if (ft_strchri(fd_ses->res_str + fd_ses->i, '\n') == -1)
	{
		tmp = ft_strdup(fd_ses->res_str + fd_ses->i);
		free(fd_ses->res_str);
		fd_ses->res_str = tmp;
		fd_ses->i = 0;
	}
	return (1);
}

static int	ft_read_fd(int fd, t_fd *fd_ses, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	long	ln_brk_pos;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((ln_brk_pos = ft_strchri(buf, '\n')) > -1)
		{
			tmp = ft_strndup(buf, ln_brk_pos);
			*line = ft_strjoin(fd_ses->res_str, tmp);
			free(tmp);
			free(fd_ses->res_str);
			fd_ses->res_str = ft_strdup(buf + ln_brk_pos + 1);
			return (1);
		}
		tmp = fd_ses->res_str;
		fd_ses->res_str = ft_strjoin(fd_ses->res_str, buf);
		free(tmp);
	}
	return (ret);
}

static void	ft_free_fd_ses(t_list **fd_lst, int fd)
{
	t_list	*cur;
	t_list	*prev;

	cur = *fd_lst;
	prev = NULL;
	while (cur)
	{
		if (((t_fd*)cur->content)->fd_id == fd)
		{
			if (prev == NULL)
				*fd_lst = cur->next;
			else
				prev->next = cur->next;
			free(((t_fd*)cur->content)->res_str);
			free(cur->content);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int			ft_get_next_line(const int fd, char **line)
{
	int				read_ret;
	static t_list	*fd_lst = NULL;
	t_fd			*fd_ses;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	fd_ses = ft_return_fd_ses(fd, &fd_lst);
	if (ft_strchri(fd_ses->res_str + fd_ses->i, '\n') > -1)
		return (ft_handle_stream(fd_ses, line));
	if ((read_ret = ft_read_fd(fd, fd_ses, line)) != 0)
		return (read_ret == -1 ? -1 : 1);
	if (ft_strlen(fd_ses->res_str))
	{
		*line = ft_strdup(fd_ses->res_str);
		ft_strclr(fd_ses->res_str);
		return (1);
	}
	ft_free_fd_ses(&fd_lst, fd);
	return (0);
}
