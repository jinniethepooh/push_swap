/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:22:38 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/20 00:30:26 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	error_usage(int argc)
{
	if (argc == 1)
	{
		error_msg();
		exit (0);
	}
}

void	error_invalid_input(t_info *a, t_info *b)
{
	free_stack(a, b);
	error_msg();
	exit (0);
}

void	error_malloc(t_info *a, t_info *b)
{
	free_stack(a, b);
	write(2, "[Error] unsuccessfully malloc\n", 30);
	exit (0);
}

void	error_invalid_instruction(char *ins, t_info *a, t_info *b)
{
	free(ins);
	free_stack(a, b);
	error_msg();
	exit (0);
}
