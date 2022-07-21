/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:54:36 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:56:19 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ----- CREATING A TOP/BOTTOM LAYER FOR EACH BLOCK ----- //

static void	manage_block(t_info *a, t_info *b, int block)
{
	if (b->cur_size > 1)
	{
		if (b->tab[0][1] < ((block * a->block_size) - (a->block_size / 2)))
			rotate_b(b, 1);
	}
}

void	push_to_block(t_info *a, t_info *b)
{
	int	count;
	int	block;

	count = 0;
	block = 1;
	while (a->cur_size)
	{
		if (a->tab[0][1] <= block * a->block_size)
		{
			push_b(a, b, 1);
			manage_block(a, b, block);
			++count;
		}
		else
			rotate_a(a, 1);
		if (count == block * a->block_size)
			++block;
	}
}

void	sort_large(t_info *a, t_info *b)
{
	sort_asc(a, b);
	sort_dsc(a, b);
	while (b->cur_size)
		push_a(a, b, 1);
	while (!is_sort(a->tab, a->cur_size, 'a'))
		sort_large(a, b);
}
