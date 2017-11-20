/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:05:04 by gtavares          #+#    #+#             */
/*   Updated: 2017/09/28 17:39:47 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int i, char c))
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	newstr = NULL;
	if (s)
	{
		newstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (newstr)
		{
			while (*(s + i))
			{
				*(newstr + i) = (*f)(i, *(s + i));
				i++;
			}
			*(newstr + i) = '\0';
		}
	}
	return (newstr);
}
