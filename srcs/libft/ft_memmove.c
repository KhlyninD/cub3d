/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:01:33 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 16:01:33 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	if (strdest == NULL && strsrc == NULL)
		return (NULL);
	if ((strdest > strsrc) && (strdest < strsrc + n))
	{
		strdest += n;
		strsrc += n;
		while (n--)
			*--strdest = *--strsrc;
	}
	else
		while (n--)
			*strdest++ = *strsrc++;
	return (dest);
}
