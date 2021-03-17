/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:10:16 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/16 21:52:50 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *dm1;
	int *tmp;
	int size;

	if (min >= max)
		return (0);
	size = max - min;
	dm1 = (int*)malloc(sizeof(int) * size);
	if (!dm1)
		return (0);
	tmp = dm1;
	while (min < max)
		*(tmp++) = min++;
	return (dm1);
}
