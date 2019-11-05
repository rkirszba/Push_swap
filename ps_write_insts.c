/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_write_insts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:22:37 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/04 15:48:22 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_write_inst(t_psinstlst *alst_i)
{
	if (alst_i->inst == SA)
		write(1, "sa\n", 3);
	if (alst_i->inst == SB)
		write(1, "sb\n", 3);
	if (alst_i->inst == SS)
		write(1, "ss\n", 3);
	if (alst_i->inst == PA)
		write(1, "pa\n", 3);
	if (alst_i->inst == PB)
		write(1, "pb\n", 3);
	if (alst_i->inst == RA)
		write(1, "ra\n", 3);
	if (alst_i->inst == RB)
		write(1, "rb\n", 3);
	if (alst_i->inst == RR)
		write(1, "rr\n", 3);
	if (alst_i->inst == RRA)
		write(1, "rra\n", 4);
	if (alst_i->inst == RRB)
		write(1, "rrb\n", 4);
	if (alst_i->inst == RRR)
		write(1, "rrr\n", 4);
}

void		ps_write_insts(t_psinstlst *alst_i)
{
	while (alst_i)
	{
		ps_write_inst(alst_i);
		alst_i = alst_i->next;
	}
}
