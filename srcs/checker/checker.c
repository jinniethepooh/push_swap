/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:13:38 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 22:53:19 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	result_checker(t_info *a, t_info *b)
{
	if (is_sort(a->tab, a->cur_size, 'a') && !b->cur_size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a, b);
	exit (0);
}

static void	loop_ins(t_info *a, t_info *b)
{
	char	*ins;
	char	*tmp;

	ins = NULL;
	tmp = (char *)malloc(sizeof(char) * 2);
	while (read(0, tmp, 1))
	{
		tmp[1] = '\0';
		ins = ft_strjoin(ins, tmp);
		if (*tmp == '\n')
		{
			free(tmp);
			do_ins(ins, a, b);
			free(ins);
			ins = NULL;
			tmp = (char *)malloc(sizeof(char) * 2);
		}
	}
	free(tmp);
	result_checker(a, b);
}

int	main(int argc, char **argv)
{
	t_info	a;
	t_info	b;

	if (argc - 1 > 0)
	{
		a.ori_size = argc - 1;
		create_stack(&a, &b, argv);
		get_sequence(&a);
		loop_ins(&a, &b);
	}
	return (0);
}
