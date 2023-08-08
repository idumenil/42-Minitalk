/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:26:20 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/02 14:19:02 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbword(char const *s, char c)
{
	int			nbr;
	size_t		i;

	i = 0;
	nbr = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i + 1] != c && s[i] == c)
			nbr++;
		i++;
	}
	if (s[i - 1] != c)
		nbr++;
	return (nbr);
}

static char	*ft_strdup_mod(const char *s, char c, size_t *i)
{
	int		len;
	char	*dest;
	size_t	j;

	len = 0;
	j = *i;
	while (s[j] != c && s[j] != '\0')
	{
		len++;
		j++;
	}
	j = 0;
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[*i] != c && s[*i] != '\0')
	{
		dest[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	res = malloc((ft_nbword(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			res[j] = ft_strdup_mod(s, c, &i);
			j++;
		}	
	}
	res[j] = 0;
	return (res);
}
