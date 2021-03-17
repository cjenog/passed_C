/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:57:33 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/16 22:04:25 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

int		get_word_cnt(char *str, char *charset)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			++cnt;
			while (*str && !is_in_charset(*str, charset))
				++str;
		}
		else
			++str;
	}
	return (cnt);
}

void	ft_strcpy(char *dest, char *start, char *last)
{
	while (start < last)
		*(dest++) = *(start++);
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**dm1;
	long	index;
	char	*start;

	dm1 = (char**)malloc(sizeof(char*) * get_word_cnt(str, charset) + 1);
	index = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			start = str;
			while (*str && !is_in_charset(*str, charset))
				++str;
			dm1[index] = (char*)malloc(str - start + 1);
			ft_strcpy(dm1[index++], start, str);
		}
		++str;
	}
	dm1[index] = 0;
	return (dm1);
}
