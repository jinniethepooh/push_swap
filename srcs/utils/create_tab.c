/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:01:01 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/21 03:32:25 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	tab_malloc(t_info *a, t_info *b)
{
	int	i;

	a->tab = (int **)malloc(sizeof(int *) * a->ori_size);
	b->tab = (int **)malloc(sizeof(int *) * a->ori_size);
	if (!a->tab || !b->tab)
		error_malloc(a, b);
	i = 0;
	while (i < a->ori_size)
	{
		a->tab[i] = (int *)malloc(sizeof(int) * 2);
		b->tab[i] = (int *)malloc(sizeof(int) * 2);
		if (!a->tab[i] || !b->tab[i])
			error_malloc(a, b);
		++i;
	}
}

void	get_sequence(t_info *a)
{
	int	counter;
	int	i;
	int	j;

	i = 0;
	while (i < a->ori_size)
	{
		counter = 1;
		j = 0;
		while (j < a->ori_size)
		{
			if (a->tab[i][0] > a->tab[j][0])
				++counter;
			++j;
		}
		a->tab[i][1] = counter;
		++i;
	}
}

void	create_stack(t_info *a, t_info *b, char **s)
{
	int	i;
	int	j;
	int	k;

	a->ori_size = ncount(s, a->ori_size);
	a->cur_size = a->ori_size;
	b->cur_size = 0;
	tab_malloc(a, b);
	i = 0;
	j = 1;
	while (i < a->ori_size)
	{
		k = 0;
		while (i < a->ori_size && s[j][k])
		{
			a->tab[i][0] = ps_atoi(&s[j][k], a, b);
			k += sublooper(&s[j][k], 'b');
			k += sublooper(&s[j][k], 'a');
			++i;
		}
		++j;
	}
	is_dup_input(a, b);
}
