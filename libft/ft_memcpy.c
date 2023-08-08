/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:06:08 by idumenil          #+#    #+#             */
/*   Updated: 2023/03/02 17:11:37 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;

	if (dest == NULL)
		return (NULL);
	temp_dest = dest;
	temp_src = src;
	if (src == NULL)
		return (dest);
	if (n > 0)
	{
		while (n--)
		{
			*temp_dest++ = *temp_src++;
		}
	}
	return (dest);
}
