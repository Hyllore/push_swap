/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:42:25 by droly             #+#    #+#             */
/*   Updated: 2015/12/08 16:10:06 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	i2;

	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[0] != '\0')
	{
		i = 0;
		i2 = 0;
		while (s1[i] != '\0' && (s1[i] == s2[i2]))
		{
			if (s2[++i2] == '\0')
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (NULL);
}