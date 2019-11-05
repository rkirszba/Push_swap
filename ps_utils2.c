/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:54:51 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/06 18:32:25 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_no_end(t_psnb *alst, t_psnb *end)
{
	t_psnb	*tmp;

	tmp = alst;
	while (tmp)
	{
		if (tmp == end)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_psnb	*ps_other_end(t_psnb *elem)
{
	if (!elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}

int		ps_give_entries(t_psnb *alst)
{
	int		i;

	i = 0;
	while (alst)
	{
		i++;
		alst = alst->next;
	}
	return (i);
}

int		ps_give_hvalue(t_psnb *alst)
{
	int		hvalue;

	if (!alst)
		return (0);
	hvalue = (alst->nb < 0 ? -(alst->nb) : alst->nb);
	while (alst)
	{
		if ((alst->nb < 0 ? -(alst->nb) : alst->nb) > hvalue)
			hvalue = (alst->nb < 0 ? -(alst->nb) : alst->nb);
		alst = alst->next;
	}
	if (!hvalue)
		hvalue = 1;
	return (hvalue);
}

void	ps_fill_rect(t_rect *rect, t_psnb *alst)
{
	int		i;

	i = 0;
	while (alst)
	{
		rect[i].nb = alst->nb;
		i++;
		alst = alst->next;
	}
}
