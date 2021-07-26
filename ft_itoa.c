/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:10:38 by hramos            #+#    #+#             */
/*   Updated: 2021/02/12 12:11:12 by hramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*num;
	long	copy;

	copy = n;
	size = get_int_len(copy);
	num = ft_calloc(size + 1, sizeof(char));
	if (!(num))
		return (NULL);
	if (copy <= 0)
	{
		if (copy == 0)
			num[0] = '0';
		else
			num[0] = '-';
		copy = -copy;
		if (copy == 0)
			return (num);
	}
	while (copy > 0)
	{
		num[--size] = (copy % 10) + 48;
		copy /= 10;
	}
	return (num);
}
