/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuphal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:39:19 by hkuphal           #+#    #+#             */
/*   Updated: 2019/02/19 16:00:33 by hkuphal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_reverse_bits(int octet)
{
	return (((octet >> 0) & 1) << 7) |\
	(((octet >> 1) & 1) << 6) |\
	(((octet >> 2) & 1) << 5) |\
	(((octet >> 3) & 1) << 4) |\
	(((octet >> 4) & 1) << 3) |\
	(((octet >> 5) & 1) << 2) |\
	(((octet >> 6) & 1) << 1) |\
	(((octet >> 7) & 1) << 0);
}
