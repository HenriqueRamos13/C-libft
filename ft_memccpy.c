/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:12:54 by hramos            #+#    #+#             */
/*   Updated: 2021/02/12 12:12:55 by hramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	while (n != 0)
	{
		*(dest++) = *(src);
		if (*(src++) == (unsigned char)c)
			return (dest);
		n--;
	}
	return (NULL);
}
