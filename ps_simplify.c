/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simplify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:17:20 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 13:23:49 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_simplify_insts1(t_psinstlst **alst)
{
	t_psinstlst	*tmp;
	t_psinstlst	*tmp2;

	tmp = *alst;
	while (tmp->next && tmp->next->next && tmp->next->next->next
	&& tmp->next->next->next->next)
	{
		if (tmp->inst == RA && tmp->next->inst == SA
		&& tmp->next->next->inst == PB
		&& tmp->next->next->next->inst == RRA
		&& tmp->next->next->next->next->inst == PA)
		{
			tmp->inst = PB;
			tmp->next->inst = SA;
			tmp->next->next->inst = PA;
			tmp->next->next->next->inst = SA;
			tmp2 = tmp->next->next->next->next;
			tmp->next->next->next->next = tmp->next->next->next->next->next;
			ps_delete_ninsts(tmp2, 1);
			ps_simplify_insts1(alst);
			break ;
		}
		tmp = tmp->next;
	}
}

static int	ps_simplify_insts_next(t_psinstlst **alst, t_psinstlst *tmp,
t_psinstlst *tmp2)
{
	if ((tmp2->inst == SA && tmp2->next->inst == SA)
	|| (tmp2->inst == SB && tmp2->next->inst == SB)
	|| (tmp2->inst == PA && tmp2->next->inst == PB)
	|| (tmp2->inst == PB && tmp2->next->inst == PA)
	|| (tmp2->inst == RA && tmp2->next->inst == RRA)
	|| (tmp2->inst == RRA && tmp2->next->inst == RA)
	|| (tmp2->inst == RB && tmp2->next->inst == RRB)
	|| (tmp2->inst == RRB && tmp2->next->inst == RB))
	{
		ps_delete_insts(alst, tmp, tmp2);
		ps_simplify_insts(alst);
		return (0);
	}
	else if ((tmp2->inst == RRA && tmp2->next->inst == RRB)
	|| (tmp2->inst == RRB && tmp2->next->inst == RRA)
	|| (tmp2->inst == RA && tmp2->next->inst == RB)
	|| (tmp2->inst == RB && tmp2->next->inst == RA)
	|| (tmp2->inst == SA && tmp2->next->inst == SB)
	|| (tmp2->inst == SB && tmp2->next->inst == SA))
	{
		ps_merge_insts(tmp, tmp2);
		ps_simplify_insts(alst);
		return (0);
	}
	return (1);
}

void		ps_simplify_insts(t_psinstlst **alst)
{
	t_psinstlst	*tmp;
	t_psinstlst *tmp2;

	if (!*alst || !(*alst)->next)
		return ;
	tmp = *alst;
	tmp2 = tmp;
	while (tmp2->next)
	{
		if (!(ps_simplify_insts_next(alst, tmp, tmp2)))
			break ;
		else
		{
			tmp2 = tmp2->next;
			if (tmp->next != tmp2)
				tmp = tmp->next;
		}
	}
}
