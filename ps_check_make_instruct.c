/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_make_instruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:57:55 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 13:04:51 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_initialize_inst(char *line, t_psinstlst *new)
{
	if (!ft_strcmp(line, "sa"))
		new->inst = SA;
	if (!ft_strcmp(line, "sb"))
		new->inst = SB;
	if (!ft_strcmp(line, "ss"))
		new->inst = SS;
	if (!ft_strcmp(line, "pa"))
		new->inst = PA;
	if (!ft_strcmp(line, "pb"))
		new->inst = PB;
	if (!ft_strcmp(line, "ra"))
		new->inst = RA;
	if (!ft_strcmp(line, "rb"))
		new->inst = RB;
	if (!ft_strcmp(line, "rr"))
		new->inst = RR;
	if (!ft_strcmp(line, "rra"))
		new->inst = RRA;
	if (!ft_strcmp(line, "rrb"))
		new->inst = RRB;
	if (!ft_strcmp(line, "rrr"))
		new->inst = RRR;
}

void		ps_make_instlst(char *line, t_psinstlst **alst_i)
{
	t_psinstlst	*new;
	t_psinstlst	*tmp;

	tmp = *alst_i;
	if (!(new = (t_psinstlst*)malloc(sizeof(*new))))
		exit(1);
	ps_initialize_inst(line, new);
	new->next = NULL;
	if (!(*alst_i))
	{
		*alst_i = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int			ps_check_instruct(t_psinstlst **alst_i)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
		&& ft_strcmp(line, "ss") && ft_strcmp(line, "pa")
		&& ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
		&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr")
		&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
		&& ft_strcmp(line, "rrr"))
		{
			free(line);
			return (0);
		}
		ps_make_instlst(line, alst_i);
		free(line);
	}
	return (1);
}
