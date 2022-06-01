/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:58:26 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 15:58:26 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;	

	res = (char *)malloc(size * nmemb);
	i = 0;
	if (!res)
		return (NULL);
	while (i < (size * nmemb))
		res[i++] = '\0';
	return (res);
}
