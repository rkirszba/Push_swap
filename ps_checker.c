/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:01:16 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 14:17:48 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_checker(t_psnb *alst_n, t_psinstlst *alst_i, int v)
{
	if (!(ps_check_instruct(&alst_i)))
	{
		write(1, "Error\n", 6);
		ps_free_nb_inst(&alst_n, &alst_i);
		exit(1);
	}
	if (!v)
		ps_execute(&alst_n, &alst_i);
	else
	{
		SDL_Init(SDL_INIT_VIDEO);
		ps_visualize(&alst_n, &alst_i);
		SDL_Quit();
	}
}

int			main(int ac, char **av)
{
	t_psnb		*alst_n;
	t_psinstlst	*alst_i;
	int			i;
	int			v;

	i = 0;
	v = 0;
	alst_n = NULL;
	alst_i = NULL;
	if (ac <= 1)
		return (0);
	while (++i < ac)
	{
		if (ps_check_args(av[i], &alst_n))
			v++;
	}
	if (!alst_n)
		return (0);
	ps_checker(alst_n, alst_i, v);
	return (0);
}
