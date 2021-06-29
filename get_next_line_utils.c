/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:56:14 by albzamor          #+#    #+#             */
/*   Updated: 2021/06/29 14:22:26 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = malloc(count * size);
	if (buffer == NULL)
		return (buffer);
	ft_bzero(buffer, size * count);
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*scopy;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	scopy = (void *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	while (i < ft_strlen(s1))
		scopy[i++] = s1[j++];
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
		scopy[i++] = s2[k++];
	scopy[i] = '\0';
	return (scopy);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub_str;

	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = len - start;
	if (ft_strlen(s) < start)
	{
		sub_str = malloc(sizeof(char) * 1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len > ft_strlen(s) - start - 1)
		len = ft_strlen(s) - start ;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = -1;
	while ((++i < len) && s[i + start != '\0'])
		sub_str[i] = s[start + i];
	sub_str[i] = '\0';
	return (sub_str);
}



static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count_word;

	count_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
				|| s[i] == '\t' || s[i] == '\v' || s[i] == ' '))
			i++;
		if (s[i] != c && s[i] != '\0')
			count_word++;
		while (s[i] == c && s[i] != '\0')
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				count_word++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count_word);
}

static size_t	ft_desplace(char const *s, char c)
{
	size_t	i;
	size_t	count_word;

	count_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
				|| s[i] == '\t' || s[i] == '\v' || s[i] == ' '))
			i++;
		if (s[i] != c && s[i] != '\0')
			return (i);
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

static size_t	ft_lens(char *lens, char c)
{
	size_t	i;

	i = 0;
	{
		while (lens[i] != '\0')
		{
			if (lens[i] == c)
				return (i);
			i++;
		}
		return (i);
	}
}

char	**ft_split(char const *s, char c)

{
	char	*scopy;
	char	**pp;
	size_t	i;
	size_t	words;
	size_t	desplace;

	i = 0;
	if (s == NULL)
		return (NULL);
	desplace = 0;
	words = ft_wordcount(s, c);
	scopy = (char *)s;
	pp = (char **)malloc(sizeof(char *) * (words + 1));
	if (pp == NULL)
		return (NULL);
	while (i < words)
	{
		scopy = scopy + ft_desplace(scopy, c);
		pp[i] = ft_substr((const char *)scopy, 0, ft_lens(scopy, c));
		scopy = scopy + ft_lens(scopy, c) + 1;
		i++;
	}
	pp[i] = NULL;
	return (pp);
}
