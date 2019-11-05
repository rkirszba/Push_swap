/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simplify2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:07:56 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 13:27:11 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_delete_insts(t_psinstlst **alst, t_psinstlst *tmp, t_psinstlst *tmp2)
{
	if (*alst == tmp2)
	{
		tmp = *alst;
		*alst = (*alst)->next->next;
		free(tmp->next);
		free(tmp);
		return ;
	}
	tmp->next = tmp->next->next->next;
	free(tmp2->next);
	free(tmp2);
}

void	ps_merge_insts(t_psinstlst *tmp, t_psinstlst *tmp2)
{
	tmp = tmp2->next;
	if (tmp2->inst == SA || tmp2->inst == SB)
	{
		tmp2->inst = SS;
		tmp2->next = tmp2->next->next;
	}
	else if (tmp2->inst == RA || tmp2->inst == RB)
	{
		tmp2->inst = RR;
		tmp2->next = tmp2->next->next;
	}
	else
	{
		tmp2->inst = RRR;
		tmp2->next = tmp2->next->next;
	}
	free(tmp);
}

void	ps_delete_ninsts(t_psinstlst *tmp, int nb)
{
	int			i;
	t_psinstlst	*tmp2;

	i = 0;
	while (i < nb)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
		i++;
	}
}
