/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:33:25 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/05 18:55:50 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_utils
{
	size_t	tot_words;
	size_t	len_word;
	size_t	index;
}t_utils;

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	tot;

	tot = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			tot ++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (tot);
}

static void	*freematrix(char **matrix, size_t i)
{
	while (i--)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	t_utils	u;

	if (!s)
		return (NULL);
	u.tot_words = ft_word_counter(s, c);
	out = ft_calloc(sizeof(char *), u.tot_words + 1);
	if (!out)
		return (NULL);
	u.index = 0;
	while (u.tot_words--)
	{
		while (*s == c)
			s++;
		u.len_word = 0;
		while (s[u.len_word] != c && s[u.len_word] != '\0')
			u.len_word++;
		out[u.index] = ft_calloc(sizeof(char), u.len_word + 1);
		if (!out[u.index])
			freematrix(out, u.index);
		ft_memmove(out[u.index++], s, u.len_word);
		s = s + u.len_word;
	}
	out[u.index] = 0;
	return (out);
}
