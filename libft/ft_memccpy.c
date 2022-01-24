/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:20:01 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:20:02 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned const char *) src;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char) c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
