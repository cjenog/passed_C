/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:59:28 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/16 21:50:56 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	long	len;
	char	*dm1;

	len = 0;
	while (src[len])
		++len;
	dm1 = (char*)malloc(len + 1);
	dm1[len] = 0;
	len--;
	while (len >= 0)
	{
		dm1[len] = src[len];
		len--;
	}
	return (dm1);
}
