/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:08:47 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/21 01:33:01 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(int **tab, int size, int flag)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (flag == 'a')
		{
			if (tab[i][0] > tab[i + 1][0])
				return (0);
		}
		else if (flag == 'd')
		{
			if (tab[i][0] < tab[i + 1][0])
				return (0);
		}
		++i;
	}
	return (1);
}

void	is_dup_input(t_info *a, t_info *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->ori_size)
	{
		j = 0;
		while (j < i)
		{
			if (a->tab[i][0] == a->tab[j][0])
				error_invalid_input(a, b);
			++j;
		}
		++i;
	}
}

int	is_valid_input(char c)
{
	if (!ft_isdigit(c) && !ft_issign(c) && !ft_isspace(c))
		error_msg();
	return (1);
}

int	is_valid_nbr(char c, long nbr, int digit)
{
	if ((c == '\0' || ft_isspace(c)) && digit < 11)
	{
		if (INT_MIN <= nbr && nbr <= INT_MAX)
			return (1);
	}
	return (0);
}
