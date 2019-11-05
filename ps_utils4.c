/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:59:33 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 13:34:16 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_write_error_ck(t_psnb **alst_n, char **tab)
{
	write(1, "Error\n", 6);
	ps_free_nb(alst_n);
	free(tab);
	exit(1);
}

static int	ps_check_minmax(char *arg, long nb)
{
	if (nb > 2147483648)
	{
		free(arg);
		return (0);
	}
	return (1);
}

long		ps_give_nb(char *arg)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 0;
	nb = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = 1;
		i++;
	}
	while (arg[i])
	{
		nb = nb * 10 + arg[i] - 48;
		if (!ps_check_minmax(arg, nb))
			return (2147483648);
		i++;
	}
	if (sign)
		nb = nb * (-1);
	free(arg);
	return (nb);
}
