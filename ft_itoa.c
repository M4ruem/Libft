/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:07:33 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/05 11:18:30 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write(char *str, long nbr, size_t size)
{
	*(str + size--) = '\0';
	while (nbr > 0)
	{
			*(str + size--) = nbr % 10 + '0';
			nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
			*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
			*(str + size) = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;
	char	*wrt;

	nbr = n;
	if (n > 0)
			size = 0;
	else
			size = 1;
	if (nbr < 0)
			nbr = -nbr;
	while (n)
	{
			n /= 10;
			size++;
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	wrt = ft_write(str, nbr, size);
	return (wrt);
}
