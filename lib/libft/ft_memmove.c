/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:47:00 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 17:56:23 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	copy_forward(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	copy_backward(char *d, const char *s, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	if (d < s || d >= (s + n))
		copy_forward(d, s, n);
	else
		copy_backward(d, s, n);
	return (dest);
}
