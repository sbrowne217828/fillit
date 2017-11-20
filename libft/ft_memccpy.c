/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:23:49 by gtavares          #+#    #+#             */
/*   Updated: 2017/09/21 10:49:11 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	while (n)
	{
		*((char*)s1) = *((char*)s2);
		s1 = (void*)((char*)s1 + 1);
		s2 = (void*)((char*)s2 + 1);
		if ((char)(c) == *((char*)s1 - 1))
		{
			return (s1);
		}
		n--;
	}
	return (NULL);
}
