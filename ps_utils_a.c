/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:17:56 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:44:48 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ps_tab_to_ntab_a(int *tab, t_psdata *data)
{
	int		i;
	int		j;
	int		*new_tab;

	i = data->entries - 1;
	while (i > 1)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tab[i] < tab[j])
				break ;
			j--;
		}
		if (j != -1)
			break ;
		i--;
	}
	data->entries = i + 1;
	if (!(new_tab = (int*)malloc(sizeof(*new_tab) * (data->entries))))
		exit(1);
	i = -1;
	while (++i < data->entries)
		new_tab[i] = tab[i];
	return (new_tab);
}

int		*ps_lst_to_tab_a(t_psnb *alst, t_psdata *data)
{
	int		i;
	int		*tab;
	int		*new_tab;
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
	new_tab = ps_tab_to_ntab_a(tab, data);
	free(tab);
	return (new_tab);
}

int		ps_above_med(t_psnb *elem, t_psdata *data)
{
	if (!(elem) || ps_no_end(elem, data->end))
		return (1);
	while (elem != data->end)
	{
		if (elem->nb < data->med->nb)
			return (0);
		elem = elem->next;
	}
	if (elem->nb < data->med->nb)
		return (0);
	return (1);
}

int		ps_eleven_n_more(t_psnb *alst_na)
{
	int		i;

	if (!alst_na)
		return (0);
	i = 0;
	while (alst_na)
	{
		i++;
		alst_na = alst_na->next;
	}
	if (i >= 11)
		return (1);
	return (0);
}

int		ps_last_is_max(t_psnb *alst_na)
{
	int		max;

	if (!alst_na)
		return (0);
	max = alst_na->nb;
	while (alst_na->next)
	{
		if (alst_na->nb > max)
			max = alst_na->nb;
		alst_na = alst_na->next;
	}
	if (max < alst_na->nb)
		return (1);
	return (0);
}
