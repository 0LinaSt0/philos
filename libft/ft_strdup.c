/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:20:19 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:20:19 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	z;

	z = 0;
	d = (char *)malloc(ft_strlen((char *)s) + 1);
	if (d == NULL)
		return (NULL);
	while (s[z] != '\0')
	{
		d[z] = s[z];
		z++;
	}
	d[z] = '\0';
	return ((char *)d);
}
