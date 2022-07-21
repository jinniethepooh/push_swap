/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:47:26 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:51:00 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotater(t_info *s, int flag)
{
	if (flag == 'a')
	{
		if (s->min_pos <= (s->cur_size - 1) / 2)
			rotate_a(s, 1);
		else
			reverse_ra(s, 1);
	}
	else if (flag == 'b')
	{
		if (s->max_pos <= (s->cur_size - 1) / 2)
			rotate_b(s, 1);
		else
			reverse_rb(s, 1);
	}
}

void	sort_dsc(t_info *a, t_info *b)
{
	int	push_two_nbr;

	push_two_nbr = 0;
	find_max(b);
	while (!is_sort(b->tab, b->cur_size, 'd'))
	{
		if (b->tab[0][0] == b->max)
		{
			push_a(a, b, 1);
			if (push_two_nbr == 1)
				swap_a(a, 1);
			push_two_nbr = 0;
			find_max(b);
		}
		else if (b->tab[0][1] == b->max_seq - 1)
		{
			push_a(a, b, 1);
			push_two_nbr = 1;
		}
		else
			rotater(b, 'b');
	}
}

void	sort_asc(t_info *a, t_info *b)
{
	int	times;

	times = 1;
	find_min(a);
	while (!is_sort(a->tab, a->cur_size, 'a'))
	{
		if (a->tab[0][0] == a->min)
		{
			push_b(a, b, 1);
			find_min(a);
			++times;
		}
		else
			rotater(a, 'a');
	}
	while (--times)
		push_a(a, b, 1);
}
