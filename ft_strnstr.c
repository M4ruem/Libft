/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:04:55 by cormiere          #+#    #+#             */
/*   Updated: 2022/09/30 14:41:45 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (0);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] != '\0') && (little[j] == big[i + j]) && i + j < len)
		{
			if (little[j + 1] == '\0')
			{
				big = big + i;
				return ((char *)big);
			}
			j++;
		}
		i++;
	}
	return (0);
}
