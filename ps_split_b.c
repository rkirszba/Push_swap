/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:54:12 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:27:52 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_split_b_next2(t_pslsts *lsts, t_psdata *data, t_psend *ends,
int j)
{
	if (data->entries - j >= 2 && lsts->alst_nb->nb < data->med->nb
	&& lsts->alst_nb->next->nb >= data->med->nb
	&& ps_under_med(lsts->alst_nb->next->next, data))
	{
		ps_exe_rec_sb(lsts);
		if (!data->rev_rot)
			ends->end_b = ps_other_end(lsts->alst_nb);
		ps_exe_rec_pa(lsts);
		return (0);
	}
	if (!data->rev_rot && ps_under_med(lsts->alst_nb, data))
	{
		ends->end_b = ps_other_end(lsts->alst_nb);
		return (0);
	}
	return (1);
}

static void	ps_split_b_next(t_pslsts *lsts, t_psdata *data, t_psend *ends,
int *k)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (++j < data->entries)
	{
		if (!ps_split_b_next2(lsts, data, ends, j))
			break ;
		if (lsts->alst_nb->nb < data->med->nb)
		{
			ps_exe_rec_rb(lsts);
			(*k)++;
		}
		else
		{
			if (!i)
			{
				ends->end_a = lsts->alst_nb;
				i++;
			}
			ps_exe_rec_pa(lsts);
		}
	}
}

void		ps_split_b(t_pslsts *lsts, t_psdata *data, t_psend *ends)
{
	int		i;
	int		k;

	k = 0;
	if (!data->end || ps_is_rev_sorted(lsts->alst_nb, data->end))
		return ;
	if (data->entries == 2)
	{
		ps_exe_rec_sb(lsts);
		ps_exe_rec_pa(lsts);
		ps_exe_rec_pa(lsts);
		return ;
	}
	if (data->entries == 3 && !data->rev_rot)
	{
		ps_handle_three_b(lsts);
		return ;
	}
	ps_split_b_next(lsts, data, ends, &k);
	if (data->rev_rot)
	{
		i = -1;
		while (++i < k)
			ps_exe_rec_rrb(lsts);
	}
}
