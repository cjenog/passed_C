/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:27:43 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/09 02:10:10 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = size / 2;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[(size - 1)];
		tab[(size - 1)] = temp;
		i++;
		size--;
	}
}
