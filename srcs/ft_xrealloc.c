/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xrealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:16:28 by dmorgil           #+#    #+#             */
/*   Updated: 2019/04/19 12:20:45 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_xrealloc(void *ptr, size_t new_s, size_t old_s)
{
	void	*tmp;

	if (!(tmp = realloc(ptr, new_s)))
	{
		write(2, "Memory cannot be allocated\n", 27);
		exit(EXIT_FAILURE);
	}
	if (new_s > old_s)
		ft_memset(tmp + old_s, 0, new_s - old_s);
	return (tmp);
}
