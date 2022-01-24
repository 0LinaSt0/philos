/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:20:03 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:20:04 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*str;

	i = 0;
	str = (unsigned const char *) s;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
