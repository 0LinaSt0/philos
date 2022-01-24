/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:20:30 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:20:31 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen((char *)ndl) == 0)
		return ((char *)hst);
	while (hst[i] != '\0' && i < len && len - i >= ft_strlen((char *)ndl))
	{
		if (hst[i] == *ndl && ft_strncmp(hst + i, ndl,
				ft_strlen((char *)ndl)) == 0)
			return ((char *)(hst + i));
		i++;
	}
	return (NULL);
}
