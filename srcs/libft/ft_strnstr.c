/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:05:27 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 16:05:27 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_getpos(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (*s1 == *s2 && *s1 && n--)
	{
		s1++;
		s2++;
		pos++;
	}
	return (pos);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	curpos;
	size_t	s2len;

	s2len = ft_strlen(s2);
	if (0 < s2len)
	{
		while (*s1 && n)
		{
			curpos = ft_getpos(s1, s2, n--);
			if (curpos == s2len)
				return ((char *)s1);
			if (0 < curpos)
				s1 += curpos;
			else
				s1++;
		}
		return (NULL);
	}
	else
		return ((char *)s1);
}
