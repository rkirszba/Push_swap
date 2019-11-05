/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:26:58 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:24:43 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_quick_sort_a(t_pslsts *lsts, t_psnb *end)
{
	t_psend		ends;
	t_psdata	*data;
	static int	i = 0;

	ends.end_a = NULL;
	ends.end_b = NULL;
	i++;
	if (!end || ps_is_sorted(lsts->alst_na, end))
		return ;
	if (!(data = (t_psdata*)malloc(sizeof(*data))))
		exit(1);
	if (i <= 4 && ps_eleven_n_more(lsts->alst_na)
	&& ps_last_is_max(lsts->alst_na))
	{
		ps_exe_rec_rra(lsts);
		end = ps_other_end(lsts->alst_na);
	}
	ps_fill_data_a(lsts, end, data);
	if (data->entries > 2)
		ends.end_a = data->next_end;
	ps_split_a(lsts, data, &ends);
	ps_quick_sort_a(lsts, ends.end_a);
	ps_quick_sort_b(lsts, ends.end_b);
	free(data);
}
