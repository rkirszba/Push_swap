/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:13:13 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:30:04 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*ps_lst_to_tab_b(t_psnb *alst, t_psdata *data)
{
	int		i;
	int		*tab;
	t_psnb	*tmp;

	i = 0;
	tmp = alst;
	if (!(tab = (int*)malloc(sizeof(*tab) * data->entries)))
		exit(1);
	while (i < data->entries)
	{
		tab[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

int			ps_find_pa(t_psnb *alst, t_psnb *end)
{
	int		pa;
	t_psnb	*tmp;
	t_psnb	*tmp2;

	pa = 0;
	tmp = alst;
	if (tmp == end)
		return (1);
	if (tmp->next == end && ps_is_rev_sorted(alst, end))
		return (2);
	if (tmp->next == end && !ps_is_rev_sorted(alst, end))
		return (0);
	while (tmp != end)
	{
		tmp2 = tmp->next;
		while (tmp2 != end->next)
		{
			if (tmp2->nb > tmp->nb)
				return (pa);
			tmp2 = tmp2->next;
		}
		pa++;
		tmp = tmp->next;
	}
	return (++pa);
}

static void	ps_handle_three_b_next(t_pslsts *lsts)
{
	if (lsts->alst_nb->nb > lsts->alst_nb->next->nb
	&& lsts->alst_nb->nb < lsts->alst_nb->next->next->nb)
	{
		ps_exe_rec_rrb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
	}
	else if (lsts->alst_nb->nb < lsts->alst_nb->next->nb
	&& lsts->alst_nb->nb > lsts->alst_nb->next->next->nb)
	{
		ps_exe_rec_sb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
	}
}

void		ps_handle_three_b(t_pslsts *lsts)
{
	if (lsts->alst_nb->nb < lsts->alst_nb->next->nb
	&& lsts->alst_nb->nb < lsts->alst_nb->next->next->nb
	&& lsts->alst_nb->next->nb < lsts->alst_nb->next->next->nb)
	{
		ps_exe_rec_rrb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_sb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
	}
	else if (lsts->alst_nb->nb < lsts->alst_nb->next->nb
	&& lsts->alst_nb->nb < lsts->alst_nb->next->next->nb
	&& lsts->alst_nb->next->nb > lsts->alst_nb->next->next->nb)
	{
		ps_exe_rec_sb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_sb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
	}
	else
		ps_handle_three_b_next(lsts);
}

int			ps_under_med(t_psnb *elem, t_psdata *data)
{
	if (!(elem) || ps_no_end(elem, data->end))
		return (1);
	while (elem != data->end)
	{
		if (elem->nb >= data->med->nb)
			return (0);
		elem = elem->next;
	}
	if (elem->nb >= data->med->nb)
		return (0);
	return (1);
}
