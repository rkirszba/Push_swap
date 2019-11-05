/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:38:06 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 12:30:56 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_show_state2(t_psnb *alst, t_pssdl *stct, t_rect *rect, int stack)
{
	int		i;
	int		j;

	j = 0;
	i = ps_give_entries(alst);
	ps_fill_rect(rect, alst);
	while (--i >= 0)
	{
		ps_choose_color(stct, rect[i].nb, stack);
		rect[i].wdth = ps_give_width(rect[i].nb, stct->hvalue);
		rect[i].rect.x = (640 - rect[i].wdth) / 2 + (!stack ? 0 : 640);
		rect[i].rect.y = stct->whght - (stct->hght * (j + 1));
		rect[i].rect.w = (!rect[i].nb ? 1 : rect[i].wdth);
		rect[i].rect.h = stct->hght;
		SDL_RenderFillRect(stct->renderer, &(rect[i].rect));
		j++;
	}
}

void	ps_show_state(t_pslsts *lsts, t_pssdl *stct)
{
	t_rect		*rect1;
	t_rect		*rect2;
	SDL_Rect	rect;

	rect.x = 0;
	rect1 = NULL;
	rect2 = NULL;
	ps_fill_background(stct, rect);
	if (!(rect1 = (t_rect*)malloc(sizeof(*rect1)
	* ps_give_entries(lsts->alst_na))))
		exit(1);
	if (!(rect2 = (t_rect*)malloc(sizeof(*rect2)
	* ps_give_entries(lsts->alst_nb))))
		exit(1);
	ps_show_state2(lsts->alst_na, stct, rect1, 0);
	ps_show_state2(lsts->alst_nb, stct, rect2, 1);
	SDL_RenderPresent(stct->renderer);
	if (rect1)
		free(rect1);
	if (rect2)
		free(rect2);
}

int		ps_visualize_next2(t_pslsts *lsts, t_pssdl *stct)
{
	t_pstab		ptab[11];
	int			i;

	ps_initialize_tab(ptab);
	while (lsts->alst_i)
	{
		ps_show_state(lsts, stct);
		i = 0;
		while (i < 11)
		{
			if (ptab[i].inst == lsts->alst_i->inst)
			{
				ptab[i].f(&(lsts->alst_na), &(lsts->alst_nb));
				break ;
			}
			i++;
		}
		SDL_Delay(stct->delay);
		lsts->alst_i = lsts->alst_i->next;
		SDL_PollEvent(&(stct->event));
		if (stct->event.type == SDL_QUIT)
			return (0);
	}
	ps_show_state(lsts, stct);
	return (1);
}

void	ps_visualize_next(t_pslsts *lsts, t_pssdl *stct)
{
	stct->window = SDL_CreateWindow("Push_swap", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, 1280, stct->whght, SDL_WINDOW_SHOWN);
	stct->renderer = SDL_CreateRenderer(stct->window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Delay(1000);
	if (!(ps_visualize_next2(lsts, stct)))
		stct->follow = 0;
	SDL_Delay(800);
	if (stct->follow)
		ps_check_visualizer(lsts, stct);
	while (stct->follow)
	{
		SDL_PollEvent(&(stct->event));
		if (stct->event.type == SDL_QUIT)
		{
			stct->follow = 0;
			break ;
		}
	}
	SDL_DestroyRenderer(stct->renderer);
	SDL_DestroyWindow(stct->window);
}

void	ps_visualize(t_psnb **alst_na, t_psinstlst **alst_i)
{
	t_psnb		*alst_nb;
	t_pslsts	*lsts;
	t_psinstlst	*tmp;
	t_pssdl		stct;

	if (!(lsts = (t_pslsts*)malloc(sizeof(*lsts))))
		exit(1);
	alst_nb = NULL;
	tmp = *alst_i;
	lsts->alst_i = tmp;
	lsts->alst_na = *alst_na;
	lsts->alst_nb = alst_nb;
	stct.entries = ps_give_entries(lsts->alst_na);
	stct.hvalue = ps_give_hvalue(lsts->alst_na);
	stct.hght = 1024 / stct.entries;
	stct.delay = ps_give_delay(lsts->alst_i);
	stct.follow = 1;
	stct.whght = ps_give_whght(stct.entries);
	ps_visualize_next(lsts, &stct);
	free(lsts);
	ps_free_inst(alst_i);
	ps_free_nb_nb(alst_na, &alst_nb);
}
