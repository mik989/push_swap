/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:43:34 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/14 18:43:41 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	check;

	count = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			check = 1;
			count++;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (count);
}

static char	*word_str(const char *s, int start, int finish)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	k;
	char	**arr;
	int		index;

	arr = calloc(sizeof(char *), (count_words(s, c) + 2));
	if (!s || !arr)
		return (NULL);
	arr[0] = "a";
	i = 0;
	k = 1;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || s[i] == '\0') && index >= 0)
		{
			arr[k++] = word_str(s, index, i);
			index = -1;
		}
		i++;
	}
	arr[k] = NULL;
	return (arr);
}
