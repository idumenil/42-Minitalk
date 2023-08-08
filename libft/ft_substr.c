/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:43:44 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/03 13:38:21 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (start >= (unsigned int)ft_strlen(s))
	{
		res = malloc(sizeof(*s) * 1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	i = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	res = malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (NULL);
	while (s[start] && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
