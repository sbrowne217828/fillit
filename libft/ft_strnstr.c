/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 14:48:26 by gtavares          #+#    #+#             */
/*   Updated: 2017/09/22 15:27:03 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s, char const *f, size_t n)
{
	size_t	len;

	if (*f == '\0')
		return ((char *)s);
	len = ft_strlen(f);
	while (*s != '\0' && n >= len)
	{
		if (ft_strncmp(s, f, len) == 0)
			return ((char *)s);
		s++;
		n--;
	}
	return (NULL);
}
