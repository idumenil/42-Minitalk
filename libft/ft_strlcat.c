/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:12:30 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/01 13:43:40 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (n == 0 || !dest || !src)
		return (ft_strlen(src) + n);
	while (dest[i] != '\0' && i < n)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < n - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < n)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
