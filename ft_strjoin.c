/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:17:46 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/04 16:23:05 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;
	size_t	full_size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	full_size = s1_size + s2_size + 1;
	str = malloc(sizeof(char) * (full_size));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1_size + 1);
	ft_strlcat(str, s2, full_size);
	return (str);
}
