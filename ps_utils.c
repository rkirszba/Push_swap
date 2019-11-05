/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:43:56 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:43:10 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_initialize_tab(t_pstab *ptab)
{
	ptab[0].inst = SA;
	ptab[0].f = &ps_sa;
	ptab[1].inst = SB;
	ptab[1].f = &ps_sb;
	ptab[2].inst = SS;
	ptab[2].f = &ps_ss;
	ptab[3].inst = PA;
	ptab[3].f = &ps_pa;
	ptab[4].inst = PB;
	ptab[4].f = &ps_pb;
	ptab[5].inst = RA;
	ptab[5].f = &ps_ra;
	ptab[6].inst = RB;
	ptab[6].f = &ps_rb;
	ptab[7].inst = RR;
	ptab[7].f = &ps_rr;
	ptab[8].inst = RRA;
	ptab[8].f = &ps_rra;
	ptab[9].inst = RRB;
	ptab[9].f = &ps_rrb;
	ptab[10].inst = RRR;
	ptab[10].f = &ps_rrr;
}

int		ps_is_sorted(t_psnb *alst, t_psnb *end)
{
	if (!alst || !alst->next)
		return (1);
	while (alst != end)
	{
		if (alst->nb > alst->next->nb)
			return (0);
		alst = alst->next;
	}
	return (1);
}

int		ps_is_rev_sorted(t_psnb *alst, t_psnb *end)
{
	if (!alst || !alst->next)
		return (1);
	while (alst != end)
	{
		if (alst->nb < alst->next->nb)
			return (0);
		alst = alst->next;
	}
	return (1);
}

void	ps_sort_tab(int *tab, int size)
{
	int		i;
	int		swap;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = -1;
		}
		i++;
	}
}

void	ps_find_med_end(t_psnb *alst, int *tab, t_psdata *data)
{
	int		*stab;
	int		i;
	int		med;
	t_psnb	*tmp;

	i = -1;
	tmp = alst;
	if (!(stab = (int*)malloc(sizeof(*stab) * data->entries)))
		exit(1);
	while (++i < data->entries)
		stab[i] = tab[i];
	ps_sort_tab(stab, data->entries);
	i = data->entries / 2;
	med = stab[i];
	free(stab);
	while (tmp->nb != med)
		tmp = tmp->next;
	data->med = tmp;
	while (tmp->nb != tab[data->entries - 1])
		tmp = tmp->next;
	data->end = tmp;
}
