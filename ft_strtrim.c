/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:02:46 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/06 16:08:10 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	size_s1;
	char	*big;
	char	*chr1;
	char	*chr2;

	if (!s1 || !s2)
		return (0);
	chr1 = ft_strchr(s2, *s1);
	while (*s1 && chr1)
	{
		s1++;
		chr1 = ft_strchr(s2, *s1);
	}
	size_s1 = ft_strlen(s1);
	chr2 = ft_strchr(s2, s1[size_s1]);
	while (size_s1 && chr2)
	{
		size_s1--;
		chr2 = ft_strchr(s2, s1[size_s1]);
	}
	big = ft_substr(s1, 0, size_s1 + 1);
	return (big);
}
