/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:11:44 by mjhin             #+#    #+#             */
/*   Updated: 2022/05/30 21:11:48 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strtrunc(char *str, char c)
{
	char	*res;
	ssize_t	i;
	ssize_t	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = ft_calloc(sizeof(*res), ft_strlen(str) - i + 1);
	if (!res)
		return (NULL);
	while (str[++i])
		res[j++] = str[i];
	free(str);
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		new_s[i] = s1[i];
	while (s2[j] != '\0')
		new_s[i++] = s2[j++];
	new_s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_s);
}
