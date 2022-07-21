/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:56:30 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/21 02:05:54 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	manage_min_case(t_info *s, t_info *sa, int flag)
{
	while (1)
	{
		find_min(s);
		if (s->min_pos == s->cur_size - 1)
			if (flag == 'a')
				reverse_ra(s, 1);
		if (is_sort(s->tab, s->cur_size, flag))
			return ;
		find_min(s);
		if (s->min_pos == 0 && s->cur_size > 1)
		{
			if (flag == 'a')
				push_b(s, sa, 1);
			else
				rotate_b(s, 1);
		}
		else
			break ;
	}
}

static void	manage_b(t_info *a, t_info *b)
{
	manage_min_case(b, a, 'b');
	if (b->cur_size > 1)
	{
		if (b->tab[1][0] < b->tab[b->cur_size - 1][0])
		{
			if (b->tab[0][0] < b->tab[1][0])
				swap_b(b, 1);
		}
		else
		{
			if (b->tab[0][0] < b->tab[b->cur_size - 1][0])
				rotate_b(b, 1);
		}
	}
}

void	push_to_b(t_info *a, t_info *b)
{
	manage_min_case(a, b, 'a');
	while (b->cur_size < a->ori_size / 2 && !is_sort(a->tab, a->cur_size, 'a'))
	{
		if (a->min_pos == 1)
			swap_a(a, 1);
		if (a->tab[0][1] < (a->ori_size - 1) / 2)
			push_b(a, b, 1);
		else
			rotate_a(a, 1);
		manage_b(a, b);
		manage_min_case(a, b, 'a');
	}
}

void	sort_small(t_info *a, t_info *b)
{
	sort_asc(a, b);
	sort_dsc(a, b);
	while (b->cur_size)
		push_a(a, b, 1);
	while (!is_sort(a->tab, a->cur_size, 'a'))
		sort_small(a, b);
}
