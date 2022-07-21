/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tiny.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:15:41 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 22:31:26 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_info *a, t_info *b)
{
	while (b->cur_size != 2)
	{
		find_min(a);
		if (a->min_pos == 0)
			push_b(a, b, 1);
		if (a->min_pos <= (a->ori_size - 1) / 2)
			rotate_a(a, 1);
		else
			reverse_ra(a, 1);
	}
	sort_three(a);
	sort_small(a, b);
}

void	sort_three(t_info *a)
{
	while (!is_sort(a->tab, a->cur_size, 'a'))
	{
		find_min(a);
		if (a->tab[0][0] > a->tab[1][0] && a->tab[0][0] > a->tab[2][0] \
				&& a->min_pos != 2)
			reverse_ra(a, 1);
		else if (a->tab[0][0] > a->tab[1][0])
			swap_a(a, 1);
		else if (a->min_pos == 1)
			rotate_a(a, 1);
		else
			reverse_ra(a, 1);
	}
}
