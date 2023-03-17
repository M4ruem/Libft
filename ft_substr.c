/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:02:35 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/10 17:15:56 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s3;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s))
	{
		s3 = ft_calloc(1, 1);
		if (!s3)
			return (0);
		return (s3);
	}
	if (len <= ft_strlen(s) - start)
		s3 = ft_calloc(sizeof(char), len + 1);
	else
		s3 = ft_calloc(sizeof(char), (ft_strlen(s) - start + 1));
	if (!s3)
		return (0);
	while (s[start + i] && i < len)
	{
		s3[i] = s[start + i];
		i++;
	}
	return (s3);
}
