/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:30:47 by hramos            #+#    #+#             */
/*   Updated: 2021/03/15 15:30:51 by hramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	strlen_trim(char const *s1, char const *set)
{
	int	len;
	int	i1;
	int	i2;

	len = ft_strlen(s1);
	i1 = 0;
	i2 = len - 1;
	while (i1 < len && isset(s1[i1], set))
	{
		i1++;
		len--;
	}
	while (i2 >= 0 && isset(s1[i2], set))
	{
		i2--;
		len--;
	}
	if (len < 0)
		len = 0;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_new;
	int		len;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = strlen_trim(s1, set);
	s_new = malloc(sizeof(char) * (len + 1));
	if (!(s_new))
		return (NULL);
	while (*s1 && isset(*s1, set))
		s1++;
	while (len--)
		s_new[i++] = *s1++;
	s_new[i] = '\0';
	return (s_new);
}
