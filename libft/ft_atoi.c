/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:03:16 by johartma          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:51 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == 32))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	to_rtrn;
	int	sign;

	to_rtrn = 0;
	sign = 1;
	while (is_whitespace(*str) == 1)
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		to_rtrn *= 10;
		to_rtrn += (*str - '0');
		str++;
	}
	to_rtrn *= sign;
	return (to_rtrn);
}
