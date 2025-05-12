/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:45:51 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 11:41:14 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../fdf.h"
#include "stdio.h"
#include "stdlib.h"

int	main(void)
{
	t_fdf			*result;
	unsigned int	count;

	result = parse_values("test.fdf");
	count = 0;
	while (count < (result->dims[0] * result->dims[1]))
	{
		printf("[%f, %f, %f] ", (result->data[count]).projected[0], (result->data[count]).projected[1], (result->data[count]).projected[2]);
		if (count % result->dims[0] == result->dims[0] - 1)
			printf("\n");
		count++;
	}
	free(result->data);
	free(result);
	return (0);
}
