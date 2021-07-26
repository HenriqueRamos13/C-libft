/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:14:15 by hramos            #+#    #+#             */
/*   Updated: 2021/02/12 12:14:16 by hramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_start(const char *s1, const char *set)
{
	size_t	start;
	size_t	pos_set;
	size_t	count;

	count = 0;
	pos_set = 0;
	start = 0;
	while (set[pos_set] == s1[count])
	{
		if (pos_set == ft_strlen(set) - 1)
		{
			start = ++count;
			pos_set = 0;
			continue ;
		}
		pos_set++;
		count++;
	}
	return (start);
}

int	get_end(const char *s1, const char *set)
{
	size_t	end;
	size_t	pos_set;
	size_t	count;

	count = ft_strlen(s1) - 1;
	pos_set = ft_strlen(set) - 1;
	end = ft_strlen(s1) - 1;
	while (set[pos_set] == s1[count])
	{
		if (pos_set == 0)
		{
			end = --count;
			pos_set = ft_strlen(set) - 1;
			continue ;
		}
		pos_set--;
		count--;
	}
	return (end);
}

void	*malloc_and_fill(const char *s1, size_t start, size_t end)
{
	char	*str;
	size_t	count;

	if (ft_strlen(s1) == 0 || start >= ft_strlen(s1))
	{
		str = malloc(sizeof(char) * 1);
		if (!(str))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (end - start + 1));
	if (!(str))
		return (NULL);
	count = 0;
	while (count <= (end - start))
	{
		str[count] = s1[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_my_trim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	end = get_end(s1, set);
	start = get_start(s1, set);
	str = malloc_and_fill(s1, start, end);
	return (str);
}
