/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 02:56:15 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/15 04:53:41 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
	{
		ft_putchar(arr[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char *argv[])
{
	while (--argc)
	{
		ft_print(argv[argc]);
	}
	return (0);
}
