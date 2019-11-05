/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exe_and_record2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:10:22 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:22:45 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exe_rec_ra(t_pslsts *lsts)
{
	ps_ra(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("ra", &(lsts->alst_i));
}

void	ps_exe_rec_rb(t_pslsts *lsts)
{
	ps_rb(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("rb", &(lsts->alst_i));
}

void	ps_exe_rec_rra(t_pslsts *lsts)
{
	ps_rra(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("rra", &(lsts->alst_i));
}

void	ps_exe_rec_rrb(t_pslsts *lsts)
{
	ps_rrb(&(lsts->alst_na), &(lsts->alst_nb));
	ps_make_instlst("rrb", &(lsts->alst_i));
}
