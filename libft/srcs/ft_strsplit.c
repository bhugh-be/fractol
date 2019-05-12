/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:12:02 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/19 17:09:22 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_w(const char *s, char ch)
{
	int		i;
	int		c;

	i = 1;
	c = 0;
	if (s[0] != ch && s[0] != '\0')
		c += 1;
	while (s[i])
	{
		if (s[i - 1] == ch && s[i] != ch)
			c++;
		i++;
	}
	return (c);
}

static int			ft_len(const char *s, int st, char ch)
{
	int		len;

	len = 0;
	while (s[st] && s[st] != ch)
	{
		st++;
		len++;
	}
	return (len);
}

static void			ft_free(char ***word)
{
	char **w;

	w = *word;
	while (*w)
		free(*w++);
	free(*word);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**rez;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(rez = (char**)malloc(sizeof(char**) * (ft_count_w(s, c) + 1))))
		return (0);
	while (j < ft_count_w(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (!(rez[j++] = ft_strsub(s, i, ft_len(s, i, c))))
		{
			ft_free(&rez);
			return (0);
		}
		while (s[i] != c && s[i])
			i++;
	}
	rez[j] = 0;
	return (rez);
}
