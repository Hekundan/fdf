/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: johartma <johartma@student.42.de>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/08 11:51:58 by johartma		  #+#	#+#			 */
/*   Updated: 2024/11/08 12:13:38 by johartma		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

void	ft_itop(int nb, char *string, int *count)
{
	unsigned int	buffer;

	if (nb < 0)
	{
		buffer = -nb;
		string[*count] = '-';
		(*count)++; 
	}
	else
		buffer = nb;
	if ((buffer / 10) > 0) 
		ft_itop(buffer / 10, string, count);
	string[*count] = (buffer % 10) + '0';
	(*count)++;
}

int	num_places(int i)
{
	int				r;
	unsigned int	nb;

	r = 1;
	if (i < 0)
	{
		nb = -i;
		r++;
	}
	else
		nb = i;
	while (nb > 9)
	{
		nb = nb / 10;
		r++;
	}
	return (r);
}

char	*ft_itoa(int nb)
{
	char			*string;
	int				count;

	count = 0;
	string = malloc(num_places(nb) + 1);
	if (!string)
		return (0);
	ft_itop(nb, string, &count);
	string[count] = 0;
	return (string);
}
