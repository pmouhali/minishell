/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:56 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/04 15:10:39 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *rv;

	rv = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			rv = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (rv);
}