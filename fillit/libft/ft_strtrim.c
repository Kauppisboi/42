/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttampio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:03:26 by ttampio           #+#    #+#             */
/*   Updated: 2019/10/30 19:10:04 by ttampio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static size_t	ft_define_start_pos(char *s)
{
	size_t	i;

	i = 0;
	while ((ft_isspace(s[i])) && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	return (i);
}

static size_t	ft_define_end_pos(char *s, size_t last_pos)
{
	size_t	i;

	if (last_pos == 0)
		return (0);
	i = last_pos - 1;
	while (ft_isspace(s[i]) && i != 0)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	end_pos;
	size_t	start_pos;
	size_t	i;
	char	*new_s;
	size_t	c_to_write;

	if (!s)
		return (NULL);
	start_pos = ft_define_start_pos((char*)s);
	end_pos = ft_define_end_pos((char*)s, ft_strlen(s));
	if (!(new_s = ft_strnew(end_pos - start_pos + 1)))
		return (new_s);
	c_to_write = end_pos - start_pos + 1;
	if (end_pos == 0 && ft_isspace(s[0]))
		c_to_write--;
	i = 0;
	while (i < c_to_write)
	{
		new_s[i++] = s[start_pos++];
	}
	return (new_s);
}
