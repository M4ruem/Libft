/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:58:57 by cormiere          #+#    #+#             */
/*   Updated: 2022/09/30 13:58:22 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	const char	*start;
	char		*end;

	start = src;
	end = dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (start > end)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		i = (int) n - 1;
		while (i >= 0)
		{
			end[i] = start[i];
			i--;
		}	
	}
	return (end);
}
