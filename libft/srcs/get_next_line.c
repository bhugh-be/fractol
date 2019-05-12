/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:10:59 by bhugh-be          #+#    #+#             */
/*   Updated: 2018/12/25 21:11:10 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_file		*ft_find_file(int fd, t_file **link)
{
	t_file			*tmp;

	if (!link)
		return (NULL);
	tmp = *link;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (0);
	tmp->content = ft_strnew(0);
	tmp->fd = fd;
	tmp->next = *link;
	*link = tmp;
	return (tmp);
}

static char			*ft_find_line(t_file *file, char **line)
{
	size_t			i;
	char			*temp;

	i = 0;
	temp = NULL;
	while (file->content[i] != '\n' && file->content[i] != '\0')
		i++;
	(*line) = ft_strsub(file->content, 0, i);
	if (i < ft_strlen(file->content))
	{
		temp = ft_strdup(file->content + i + 1);
		ft_strdel(&file->content);
		file->content = temp;
	}
	else
		ft_strclr(file->content);
	return (*line);
}

static char			*ft_sjoin(char *s1, char *s2)
{
	char			*str;

	if (!s1 || !s2)
		return (0);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strdel(&s1);
	ft_strcat(str, s2);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*link;
	t_file			*file;
	char			buf[BUFF_SIZE + 1];
	int				n;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || \
		!(file = ft_find_file(fd, &link)))
		return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		file->content = ft_sjoin(file->content, buf);
		if (ft_strchr(file->content, '\n'))
			break ;
	}
	if (!ft_strlen(file->content) && n < BUFF_SIZE)
		return (0);
	(*line) = ft_find_line(file, line);
	return (1);
}
