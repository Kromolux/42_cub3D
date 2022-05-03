/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_map2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:57:59 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/02 09:58:29 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	ft_open_area(char a);

//check for open borders in map
//[rm][cm] [rm][c] [rm][cp]
//[r ][cm] [r ][c] [r ][cp]
//[rp][cm] [rp][c] [rp][cp]
int	ft_check_around(char **input, int r, int c)
{
	int	rp;
	int	rm;
	int	cp;
	int	cm;

	rp = r + 1;
	rm = r - 1;
	cp = c + 1;
	cm = c - 1;
	if (ft_open_area(input[rm][cm]) == RETURN_TRUE
		|| ft_open_area(input[rm][c]) == RETURN_TRUE
		|| ft_open_area(input[rm][cp]) == RETURN_TRUE
		|| ft_open_area(input[r][cm]) == RETURN_TRUE
		|| ft_open_area(input[r][cp]) == RETURN_TRUE
		|| ft_open_area(input[rp][cm]) == RETURN_TRUE
		|| ft_open_area(input[rp][c]) == RETURN_TRUE
		|| ft_open_area(input[rp][cp]) == RETURN_TRUE)
		return (RETURN_ERROR);
	return (RETURN_SUCCESS);
}

static int	ft_open_area(char a)
{
	if (a == ' ' || a == '\0')
		return (RETURN_TRUE);
	return (RETURN_FALSE);
}
