/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc_darray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:12:35 by dmorgil           #+#    #+#             */
/*   Updated: 2019/04/19 12:21:09 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_xmalloc_darray(size_t size, char **arr)
{
	void *tmp;

	if (!(tmp = malloc(size)))
	{
		ft_free_darray(arr);
		write(2, "Memory cannot be allocated\n", 27);
		exit(EXIT_FAILURE);
	}
	ft_memset(tmp, 0, size);
	return (tmp);
}
