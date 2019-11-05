/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exe_and_record.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:04:08 by rkirszba          #+#    #+#             */
/*   Updated: 2019/02/16 17:02:31 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exe_rec_sa(t_pslsts *lsts)
{
	ps_sa(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("sa", &(lsts->alst_i));
}

void	ps_exe_rec_sb(t_pslsts *lsts)
{
	ps_sb(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("sb", &(lsts->alst_i));
}

void	ps_exe_rec_pa(t_pslsts *lsts)
{
	ps_pa(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("pa", &(lsts->alst_i));
}

void	ps_exe_rec_pb(t_pslsts *lsts)
{
	ps_pb(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("pb", &(lsts->alst_i));
}
