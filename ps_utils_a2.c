/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:44:24 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:29:12 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_handle_three_a(t_pslsts *lsts)
{
	if (lsts->alst_na->nb < lsts->alst_na->next->nb
	&& lsts->alst_na->nb < lsts->alst_na->next->next->nb)
	{
		ps_exe_rec_rra(lsts);
		ps_exe_rec_sa(lsts);
	}
	else if (lsts->alst_na->nb < lsts->alst_na->next->nb
	&& lsts->alst_na->nb > lsts->alst_na->next->next->nb)
		ps_exe_rec_rra(lsts);
	else if (lsts->alst_na->nb > lsts->alst_na->next->nb
	&& lsts->alst_na->nb > lsts->alst_na->next->next->nb
	&& lsts->alst_na->next->nb < lsts->alst_na->next->next->nb)
		ps_exe_rec_ra(lsts);
	else if (lsts->alst_na->nb > lsts->alst_na->next->nb
	&& lsts->alst_na->nb > lsts->alst_na->next->next->nb
	&& lsts->alst_na->next->nb > lsts->alst_na->next->next->nb)
	{
		ps_exe_rec_ra(lsts);
		ps_exe_rec_sa(lsts);
	}
}
