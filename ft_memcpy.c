/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:13:20 by hramos            #+#    #+#             */
/*   Updated: 2021/02/12 12:13:24 by hramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)str1)[i] = ((unsigned char *)str2)[i];
		i++;
	}
	return (str1);
}
