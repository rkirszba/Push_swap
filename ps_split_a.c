/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:47:18 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:27:36 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_split_a_next2(t_pslsts *lsts, t_psdata *data, t_psend *ends)
{
	if (data->entries - data->j >= 2 && lsts->alst_na->nb >= data->med->nb
	&& lsts->alst_na->next->nb < data->med->nb
	&& ps_above_med(lsts->alst_na->next->next, data))
	{
		ps_exe_rec_sa(lsts);
		if (!data->rev_rot)
			ends->end_a = ps_other_end(lsts->alst_na);
		if (!data->i)
		{
			ends->end_b = lsts->alst_na;
			(data->i)++;
		}
		ps_exe_rec_pb(lsts);
		return (0);
	}
	if (!data->rev_rot && ps_above_med(lsts->alst_na, data))
	{
		ends->end_a = ps_other_end(lsts->alst_na);
		return (0);
	}
	return (1);
}

static void	ps_split_a_next(t_pslsts *lsts, t_psdata *data, t_psend *ends,
int *k)
{
	while (data->j < data->entries)
	{
		if (!ps_split_a_next2(lsts, data, ends))
			break ;
		if (lsts->alst_na->nb >= data->med->nb)
		{
			ps_exe_rec_ra(lsts);
			(*k)++;
		}
		else
		{
			if (!data->i)
			{
				ends->end_b = lsts->alst_na;
				(data->i)++;
			}
			ps_exe_rec_pb(lsts);
		}
		(data->j)++;
	}
}

void		ps_split_a(t_pslsts *lsts, t_psdata *data, t_psend *ends)
{
	int		i;
	int		k;

	k = 0;
	if (!data->end || ps_is_sorted(lsts->alst_na, data->end))
		return ;
	if (data->entries == 2)
	{
		ps_exe_rec_sa(lsts);
		return ;
	}
	if (data->entries == 3 && !data->rev_rot)
	{
		ps_handle_three_a(lsts);
		return ;
	}
	ps_split_a_next(lsts, data, ends, &k);
	if (data->rev_rot)
	{
		i = -1;
		while (++i < k)
			ps_exe_rec_rra(lsts);
	}
}
