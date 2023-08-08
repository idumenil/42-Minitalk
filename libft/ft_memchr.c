/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:02:53 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/03 14:12:07 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	i;

	if (!s || n == 0)
		return (NULL);
	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return ((void *)(dest + i));
		i++;
	}
	return (NULL);
}
