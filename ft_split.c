/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:22:05 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/07 15:04:27 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_free(char **str, int v)
{
	int	i;

	i = 0;
	while (i < v)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

static int	ft_word_count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static int	ft_letter_count(char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			k = 0;
			while (s[i] != c && s[i])
			{
				i++;
				k++;
			}
			str[j++] = malloc(sizeof(char) * k + 1);
			if (!str)
				return (j - 1);
		}
		while (s[i] == c && s[i])
			i++;
	}
	str[j] = 0;
	return (0);
}

static void	ft_write_count(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			k = 0;
			while (s[i] != c && s[i])
			{
				str[j][k] = s[i];
				i++;
				k++;
			}
			str[j][k] = '\0';
			j++;
		}
		while (s[i] == c && s[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**str;
	int		ltt;

	j = 0;
	str = 0;
	if (!s)
		return (0);
	j = ft_word_count(s, c);
	str = malloc((j + 1) * sizeof(char *));
	if (!str)
		return (0);
	if (j == 0)
	{
		str[0] = 0;
		return (str);
	}
	ltt = ft_letter_count(str, s, c);
	if (ltt != 0)
	{
		ft_free(str, ltt);
		return (0);
	}
	ft_write_count(str, s, c);
	return (str);
}
