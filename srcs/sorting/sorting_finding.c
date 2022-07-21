/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:51:07 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:54:26 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(int nbr, t_info *s)
{
	int	i;

	i = 0;
	while (i < s->cur_size)
	{
		if (nbr == s->tab[i][0])
			return (i);
		++i;
	}
	return (-1);
}

void	find_min(t_info *s)
{
	int	i;

	i = 1;
	s->min = s->tab[0][0];
	s->min_pos = 0;
	while (i < s->cur_size)
	{
		if (s->tab[i][0] < s->min)
		{
			s->min = s->tab[i][0];
			s->min_pos = i;
		}
		++i;
	}
}

// ----- APPLY SEQUENCE FOR LARGER SIZE ----- //

void	find_max(t_info *s)
{
	int	i;

	i = 1;
	s->max = s->tab[0][0];
	s->max_pos = 0;
	s->max_seq = s->tab[0][1];
	while (i < s->cur_size)
	{
		if (s->tab[i][0] > s->max)
		{
			s->max = s->tab[i][0];
			s->max_pos = i;
			s->max_seq = s->tab[i][1];
		}
		++i;
	}
}
