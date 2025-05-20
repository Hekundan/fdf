/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:26:05 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 16:26:16 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h> 
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	check;
	void	*ptr;

	check = nmemb * size;
	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (0);
	else if (check == 0)
		return (malloc(0));
	else
	{
		ptr = malloc(check);
		if (!ptr)
			return (0);
		ft_bzero(ptr, check);
		return (ptr);
	}
}
