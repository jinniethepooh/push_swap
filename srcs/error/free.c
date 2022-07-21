/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:30:35 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:32:16 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(int **tab, int size)
{
	int	i;

	i = 0;
	if (tab[i])
	{
		while (i < size)
		{
			free(tab[i]);
			++i;
		}
		free(tab);
	}
}

void	free_stack(t_info *a, t_info *b)
{
	if (a->tab)
		free_array(a->tab, a->ori_size);
	if (b->tab)
		free_array(b->tab, a->ori_size);
}
