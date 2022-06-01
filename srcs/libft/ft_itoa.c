/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:59:29 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 15:59:29 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_recursion(char **res, int n)
{
	char	divdigit;

	if (n < 0)
	{
		*(*res)++ = '-';
		if (n == -2147483648)
		{
			*(*res)++ = '2';
			ft_recursion(res, 147483648);
		}
		else
			n *= (-1);
	}
	if (n >= 10)
	{
		divdigit = (n % 10) + 48;
		n = n / 10;
		ft_recursion(res, n);
		*(*res)++ = divdigit;
	}
	else if (n >= 0 && n <= 9)
	{
		divdigit = n + 48;
		*(*res)++ = divdigit;
	}
}

static	int	ft_count_digits(int n)
{
	int	res;

	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	if (res == 0)
		return (1);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		digits;

	digits = ft_count_digits(n);
	if (n < 0)
	{
		res = (char *)ft_calloc(digits + 2, sizeof(*res));
		if (!res)
			return (NULL);
		ft_recursion(&res, n);
	}
	else
	{
		res = (char *)ft_calloc(digits + 1, sizeof(*res));
		if (!res)
			return (NULL);
		ft_recursion(&res, n);
	}
	*res = '\0';
	if (n < 0)
		return (res - digits - 1);
	return (res - digits);
}
