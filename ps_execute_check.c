/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_execute_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:01:42 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 19:33:24 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_write_result(t_psnb **alst_na, t_psnb **alst_nb, int ok)
{
	if (!ok)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ps_free_nb_nb(alst_na, alst_nb);
	exit(1);
}

void		ps_check(t_psnb **alst_na, t_psnb **alst_nb)
{
	t_psnb	*tmp;

	if (!*alst_na)
		ps_write_result(alst_na, alst_nb, 0);
	tmp = *alst_na;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			ps_write_result(alst_na, alst_nb, 0);
		tmp = tmp->next;
	}
	if (*alst_nb)
		ps_write_result(alst_na, alst_nb, 0);
	else
		ps_write_result(alst_na, alst_nb, 1);
}

void		ps_execute(t_psnb **alst_na, t_psinstlst **alst_i)
{
	t_psnb		*alst_nb;
	t_psinstlst	*tmp;
	int			i;
	t_pstab		ptab[11];

	i = 0;
	tmp = *alst_i;
	alst_nb = NULL;
	ps_initialize_tab(ptab);
	while (tmp)
	{
		while (i < 11)
		{
			if (ptab[i].inst == tmp->inst)
			{
				ptab[i].f(alst_na, &alst_nb);
				i = 0;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	ps_free_inst(alst_i);
	ps_check(alst_na, &alst_nb);
}
