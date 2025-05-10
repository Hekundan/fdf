/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:36:22 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 15:40:28 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	count;

	count = 0;
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	while (*s1)
	{
		result[count] = *s1;
		count++;
		s1++;
	}
	while (*s2)
	{
		result[count] = *s2;
		count++;
		s2++;
	}
	result[count] = 0;
	return (result);
}
