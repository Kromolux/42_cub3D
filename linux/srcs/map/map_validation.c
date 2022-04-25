/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:13:28 by rkaufman          #+#    #+#             */
/*   Updated: 2022/04/25 09:41:10 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	map_extension(char *argv)
{
	int	argv_len;

	argv_len = ft_strlen(argv);
	if ((argv[argv_len - 1] != 'b') || (argv[argv_len - 2] != 'u') || \
		(argv[argv_len - 3] != 'c'))
	{
		printf("Error: Wrong extension.\n");
		exit(EXIT_FAILURE);
	}
}
