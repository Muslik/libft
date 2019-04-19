/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:12:35 by dmorgil           #+#    #+#             */
/*   Updated: 2019/04/19 12:13:59 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_xmalloc(size_t size)
{
	void *tmp;

	if (!(tmp = malloc(size)))
	{
		write(2, "Memory cannot be allocated\n", 27);
		exit(EXIT_FAILURE);
	}
	ft_memset(tmp, 0, size);
	return (tmp);
}
