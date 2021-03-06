/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:32:24 by gtavares          #+#    #+#             */
/*   Updated: 2017/09/22 14:33:47 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	n;
	int		i;

	n = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[n + i] = s2[i];
		i++;
	}
	s1[n + i] = '\0';
	return (s1);
}
