/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 07:05:32 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/08 17:17:13 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *arr, int n)
{
	int i;
	int max;

	i = n - 1;
	max = 1;
	while (i)
	{
		if (arr[i - 1] >= arr[i])
			max = -1;
		i--;
	}
	if (max == -1)
		return ;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
	if ((arr[0] != 10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int i;
	int arr[n];

	if (n <= 0 || n >= 10)
		return ;
	i = -1;
	while (++i < n)
		arr[i] = i;
	while (arr[0] <= 10 - n)
	{
		ft_print(arr, n);
		arr[n - 1]++;
		i = n;
		while (--i && n > 1)
		{
			if (arr[i] > 9)
			{
				arr[i - 1]++;
				arr[i] = arr[i - 1];
			}
		}
	}
}
