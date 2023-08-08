/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:37 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/03 15:48:58 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispresent(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	k;
	size_t	len;

	k = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_ispresent(s1[start], set))
		start++;
	while (s1[end] && ft_ispresent(s1[end], set))
	{
		end--;
		k++;
	}
	len = ft_strlen(s1) - k - start;
	return (ft_substr(s1, start, len));
}
