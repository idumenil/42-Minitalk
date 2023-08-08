/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:34:20 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/01 10:57:48 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long a)
{
	size_t	len;

	len = 0;
	if (a < 0)
	{
		a = -a;
		len++;
	}
	while (a > 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

static char	*ft_tab0(char *tab)
{
	tab = malloc(sizeof(char) * 2);
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	long	a;
	char	*tab;
	size_t	len;

	a = n;
	len = ft_len(a);
	tab = NULL;
	if (a == 0)
		return (ft_tab0(tab));
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len--] = '\0';
	if (a < 0)
	{
		tab[0] = '-';
		a = -a;
	}
	while (a > 0)
	{
		tab[len] = a % 10 + '0';
		a = a / 10;
		len--;
	}
	return (tab);
}
