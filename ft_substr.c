/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:17:52 by hramos            #+#    #+#             */
/*   Updated: 2021/02/12 12:17:53 by hramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!(str))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	size = 0;
	while (s[start + size] != '\0' && size < len)
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!(str))
		return (NULL);
	size = -1;
	while (s[start + ++size] != '\0' && size < len)
		str[size] = s[start + (size)];
	str[size] = '\0';
	return (str);
}
