/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncmp.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: johartma <johartma@42berlin.de>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/09 13:41:35 by johartma		  #+#	#+#			 */
/*   Updated: 2024/09/09 13:41:35 by johartma		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if ((unsigned char)s1[cnt] != (unsigned char)s2[cnt])
			return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
		if (s1[cnt] == '\0' || s2[cnt] == '\0')
			return (0);
		cnt++;
	}
	return (0);
}
