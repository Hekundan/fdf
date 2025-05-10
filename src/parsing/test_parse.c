/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:45:51 by johartma          #+#    #+#             */
/*   Updated: 2025/05/10 23:02:25 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../fdf.h"
#include "stdio.h"
#include "stdlib.h"

int	main(void)
{
	t_list	*result;
	t_list	*next;

	result = get_lines("test.fdf");
	while (result)
	{
		printf("%s", (char *) result->content);
		next = result->next;
		ft_lstdelone(result, free);
		result = next;
	}
	return (0);
}
