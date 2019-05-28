/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:36:05 by dmorgil           #+#    #+#             */
/*   Updated: 2019/05/28 15:08:19 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	get_num(char *s, char c)
{
	int		i;
	int		num;

	i = -1;
	num = 0;
	while (s[++i])
		if (s[i] == c && i - 1 >= 0 && s[i - 1] != c)
			num++;
	num += ((i > 0 && s[i - 1] != c) ? 1 : 0);
	num += ((!num && s[0] && s[0] != c) ? 1 : 0);
	return (num);
}

static	int	get_len(char *str, char c)
{
	int		len;

	len = -1;
	while (str[++len] != c && str[len])
		;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		num;

	if (!s || !c)
		return (NULL);
	while (*s && *s == c)
		++s;
	num = get_num((char*)s, c);
	arr = (char **)ft_xmalloc(sizeof(char *) * num + 1 *sizeof(char *));
	i = -1;
	while (++i < num)
	{
		arr[i] = (char*)ft_xmalloc_darray(
				sizeof(char) * get_len((char*)s, c) + 1, arr);
		ft_strncpy(arr[i], (char*)s, get_len((char*)s, c));
		arr[i][get_len((char*)s, c)] = '\0';
		s += ((i == num - 1) ? 0 : get_len((char*)s, c));
		while (*s == c)
			++s;
	}
	arr[i] = NULL;
	return (arr);
}
