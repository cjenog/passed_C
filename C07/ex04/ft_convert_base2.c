/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:04:35 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/17 22:55:37 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ft_white_space_check(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_base_exception(char *base)
{
	int i;

	if (base[0] == 0 || base[1] == 0)
		return (1);
	while (*base != 0)
	{
		if (*base == '+' || *base == '-')
			return (1);
		if (*base == ' ' || (*base >= 9 && *base <= 13))
			return (1);
		i = 1;
		while (base[i] != 0)
		{
			if (*base == base[i])
				return (1);
			i++;
		}
		base++;
	}
	return (0);
}

int	nbr_size(long nbr, int base_len)
{
	int ret;

	if (!nbr)
		return (1);
	ret = 0;
	if (nbr < 0)
		++ret;
	while (nbr)
	{
		nbr /= base_len;
		++ret;
	}
	return (ret);
}
