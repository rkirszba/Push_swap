/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:55:02 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/05 13:43:08 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pslsts	*ps_initialize_struct(void)
{
	t_pslsts	*new;

	if (!(new = (t_pslsts*)malloc(sizeof(*new))))
		exit(1);
	new->alst_na = NULL;
	new->alst_nb = NULL;
	new->alst_i = NULL;
	return (new);
}

static t_psnb	*ps_give_end(t_psnb *alst_na)
{
	if (!alst_na)
		return (NULL);
	while (alst_na->next)
		alst_na = alst_na->next;
	return (alst_na);
}

int				main(int ac, char **av)
{
	t_pslsts	*lsts;
	t_psnb		*end;
	int			i;

	i = 0;
	if (ac <= 1)
		return (0);
	lsts = ps_initialize_struct();
	while (++i < ac)
		ps_check_args_ps(av[i], lsts);
	end = ps_give_end(lsts->alst_na);
	ps_quick_sort_a(lsts, end);
	if (lsts->alst_i)
	{
		ps_simplify_insts(&(lsts->alst_i));
		ps_simplify_insts1(&(lsts->alst_i));
	}
	ps_write_insts(lsts->alst_i);
	ps_free_nb_nb(&(lsts->alst_na), &(lsts->alst_nb));
	ps_free_inst(&(lsts)->alst_i);
	free(lsts);
}
