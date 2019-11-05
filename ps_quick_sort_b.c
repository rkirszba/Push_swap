/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:54:28 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:33:05 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_quick_sort_b_next(t_pslsts *lsts, t_psnb *end, t_psdata *data,
t_psend *ends)
{
	ps_fill_data_b(lsts, end, data);
	if (data->entries > 2)
		ends->end_b = data->next_end;
	ps_split_b(lsts, data, ends);
	ps_quick_sort_a(lsts, ends->end_a);
	ps_quick_sort_b(lsts, ends->end_b);
	free(data);
}

void		ps_quick_sort_b(t_pslsts *lsts, t_psnb *end)
{
	t_psend		ends;
	t_psdata	*data;
	int			i;
	int			pa;

	ends.end_a = NULL;
	ends.end_b = NULL;
	if (!lsts->alst_nb || !end)
		return ;
	i = -1;
	pa = ps_find_pa(lsts->alst_nb, end);
	while (++i < pa)
		ps_exe_rec_pa(lsts);
	if (!lsts->alst_nb || ps_no_end(lsts->alst_nb, end))
		return ;
	if (!(data = (t_psdata*)malloc(sizeof(*data))))
		exit(1);
	if (lsts->alst_nb->next && !end->next && ps_last_is_min(lsts->alst_na))
	{
		ps_exe_rec_rrb(lsts);
		end = ps_other_end(lsts->alst_nb);
	}
	ps_quick_sort_b_next(lsts, end, data, &ends);
}
