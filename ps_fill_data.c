/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:44:24 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:31:35 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_initialize_data(t_psdata *data)
{
	data->med = NULL;
	data->next_end = NULL;
	data->end = NULL;
	data->entries = 0;
	data->rev_rot = 0;
	data->i = 0;
	data->j = 0;
}

static void	ps_fill_data_a_next(t_pslsts *lsts, t_psdata *data, int *tab)
{
	int		i;
	t_psnb	*tmp;

	i = data->entries - 1;
	while (i >= 0)
	{
		if (tab[i] >= data->med->nb)
			break ;
		i--;
	}
	tmp = lsts->alst_na;
	if (i >= 0)
	{
		while (tmp->nb != tab[i])
			tmp = tmp->next;
		data->next_end = tmp;
	}
}

void		ps_fill_data_a(t_pslsts *lsts, t_psnb *end, t_psdata *data)
{
	t_psnb	*tmp;
	int		*tab;

	ps_initialize_data(data);
	tmp = lsts->alst_na;
	while (tmp != end)
	{
		(data->entries)++;
		tmp = tmp->next;
	}
	(data->entries)++;
	tab = ps_lst_to_tab_a(lsts->alst_na, data);
	ps_find_med_end(lsts->alst_na, tab, data);
	ps_fill_data_a_next(lsts, data, tab);
	if (data->end->next)
		data->rev_rot = 1;
	free(tab);
}

static void	ps_fill_data_b_next(t_pslsts *lsts, t_psdata *data, int *tab)
{
	int		i;
	t_psnb	*tmp;

	i = data->entries - 1;
	while (i >= 0)
	{
		if (tab[i] < data->med->nb)
			break ;
		i--;
	}
	tmp = lsts->alst_nb;
	if (i >= 0)
	{
		while (tmp->nb != tab[i])
			tmp = tmp->next;
		data->next_end = tmp;
	}
}

void		ps_fill_data_b(t_pslsts *lsts, t_psnb *end, t_psdata *data)
{
	t_psnb	*tmp;
	int		*tab;

	ps_initialize_data(data);
	tmp = lsts->alst_nb;
	while (tmp != end)
	{
		(data->entries)++;
		tmp = tmp->next;
	}
	(data->entries)++;
	tab = ps_lst_to_tab_b(lsts->alst_nb, data);
	ps_find_med_end(lsts->alst_nb, tab, data);
	ps_fill_data_b_next(lsts, data, tab);
	if (data->end->next)
		data->rev_rot = 1;
	free(tab);
}
