/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:10:14 by droly             #+#    #+#             */
/*   Updated: 2016/03/18 18:53:02 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int dst;

	dst = 0;
	i = 0;
	if (s2[0] == '0' && s2[1] != '\0')
		s1 = ft_strjoin("0", s1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	dst = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (dst);
}
