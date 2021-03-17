/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:08:29 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/16 19:15:51 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *arr);
int		ft_white_space_check(char c);
int		ft_base_exception(char *base);
int		nbr_size(long nbr, int base_len);

long	ft_check_nbr(char *nbr, char *base_from, int base_len)
{
	int i;
	int sum;
	int sign;

	sign = 1;
	sum = 0;
	while (ft_white_space_check(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
		if (*(nbr++) == '-')
			sign *= -1;
	while (*nbr)
	{
		i = -1;
		while (base_from[++i])
		{
			if (*nbr == base_from[i])
				break ;
		}
		if (i == base_len)
			break ;
		sum = sum * base_len + (i * sign);
		nbr++;
	}
	return ((long)sum);
}

char	*ft_change(long lnbr, int base_len, char *base)
{
	char	*ret;
	int		size;
	long	tmp;

	if (lnbr == 0)
	{
		ret = (char*)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = lnbr;
	size = nbr_size(tmp, base_len);
	ret = (char*)malloc(size + 1);
	ret[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (lnbr < 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_len;
	int		base_to_len;
	long	lnbr;

	base_from_len = ft_len(base_from);
	base_to_len = ft_len(base_to);
	if (ft_base_exception(base_from) || ft_base_exception(base_to))
		return (0);
	lnbr = ft_check_nbr(nbr, base_from, base_from_len);
	return (ft_change(lnbr, base_to_len, base_to));
}
