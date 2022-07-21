/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:04:47 by cchetana          #+#    #+#             */
/*   Updated: 2022/07/21 03:31:56 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sublooper(char *s, int flag)
{
	int	loop;

	loop = 0;
	if (flag == 'b')
	{
		while (s[loop] && ft_isspace(s[loop]) && \
				is_valid_input(s[loop]))
			++loop;
	}
	else if (flag == 'a')
	{
		while (s[loop] && !ft_isspace(s[loop]) && \
				is_valid_input(s[loop]))
			++loop;
	}
	return (loop);
}

int	looper(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		i += sublooper(&s[i], 'b');
		if (s[i] && !ft_isspace(s[i]))
			++count;
		i += sublooper(&s[i], 'a');
	}
	if (!count)
		error_msg();
	return (count);
}

int	ncount(char **s, int sz)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < sz + 1)
	{
		count += looper(s[i]);
		++i;
	}
	return (count);
}

int	ps_atoi(const char *str, t_info *a, t_info *b)
{
	int					i;
	int					digit;
	int					sign;
	unsigned long long	nbr;

	i = 0;
	digit = 0;
	while (str[i] && ft_isspace(str[i]))
		++i;
	sign = 1;
	nbr = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		sign = ',' - str[i++];
	if (!ft_isdigit(str[i]))
		error_invalid_input(a, b);
	while (str[i + digit] && ft_isdigit(str[i + digit]))
	{
		nbr = (nbr * 10) + (str[i + digit] - '0');
		++digit;
	}
	if (!is_valid_nbr(str[i + digit], nbr * sign, digit))
		error_invalid_input(a, b);
	return (nbr * sign);
}
