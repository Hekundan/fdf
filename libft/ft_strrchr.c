/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:41:44 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 16:12:50 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	char			*result;
	unsigned char	uc;

	uc = (unsigned char) c;
	result = 0;
	while (*s)
	{
		if (*s == uc)
			result = s;
		s++;
	}
	if (uc == 0)
		return (s);
	else
		return (result);
}
