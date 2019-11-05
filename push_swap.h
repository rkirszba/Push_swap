/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:56:43 by rkirszba          #+#    #+#             */
/*   Updated: 2019/03/09 13:56:41 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <SDL2/SDL.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_psnb
{
	int					nb;
	struct s_psnb		*next;
}				t_psnb;

typedef enum	e_psinst
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_psinst;

typedef struct	s_psinstlst
{
	t_psinst			inst;
	struct s_psinstlst	*next;
}				t_psinstlst;

typedef struct	s_pstab
{
	t_psinst			inst;
	void				(*f)(t_psnb**, t_psnb**);
}				t_pstab;

typedef struct	s_pslsts
{
	t_psnb				*alst_na;
	t_psnb				*alst_nb;
	t_psinstlst			*alst_i;
}				t_pslsts;

typedef struct	s_psend
{
	t_psnb				*end_a;
	t_psnb				*end_b;
}				t_psend;

typedef struct	s_psdata
{
	t_psnb				*med;
	t_psnb				*next_end;
	t_psnb				*end;
	int					entries;
	int					rev_rot;
	int					i;
	int					j;
}				t_psdata;

typedef struct	s_pssdl
{
	int					entries;
	int					hvalue;
	int					hght;
	int					whght;
	int					follow;
	int					delay;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			event;
}				t_pssdl;

typedef struct	s_rect
{
	SDL_Rect			rect;
	int					nb;
	int					wdth;
}				t_rect;

/*
** parsing arguments
*/

int				ps_check_args(char *arg, t_psnb **alst_n);
void			ps_check_args_ps(char *arg, t_pslsts *lsts);
long			ps_give_nb(char *arg);
void			ps_write_error_ck(t_psnb **alst_n, char **tab);

/*
** parsing instructions
*/

int				ps_check_instruct(t_psinstlst **alst_i);

/*
** construction liste d instructinos
*/

void			ps_make_instlst(char *line, t_psinstlst **alst_i);

/*
** execution des instructions
*/

void			ps_execute(t_psnb **alst_na, t_psinstlst **alst_i);
void			ps_sa(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_sb(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_ss(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_pa(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_pb(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_ra(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_rb(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_rr(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_rra(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_rrb(t_psnb **alst_na, t_psnb **alst_nb);
void			ps_rrr(t_psnb **alst_na, t_psnb **alst_nb);

/*
**	verification du tri
*/

void			ps_check(t_psnb **alst_na, t_psnb **alst_nb);

/*
** liberation de memoire
*/

void			ps_free_nb(t_psnb **alst);
void			ps_free_inst(t_psinstlst **alst);
void			ps_free_nb_inst(t_psnb **alst_n, t_psinstlst **alst_i);
void			ps_free_nb_nb(t_psnb **alst_na, t_psnb **alst_nb);

/*
** parsing pile
*/

void			ps_fill_data_a(t_pslsts *lsts, t_psnb *end, t_psdata *data);
void			ps_fill_data_b(t_pslsts *lsts, t_psnb *end, t_psdata *data);
void			ps_initialize_data(t_psdata *data);
int				*ps_lst_to_tab_a(t_psnb *alst, t_psdata *data);
int				*ps_lst_to_tab_b(t_psnb *alst, t_psdata *data);
int				*ps_tab_to_ntab_a(int *tab, t_psdata *data);
void			ps_find_rra(t_psnb *alst, int *tab, t_psdata *data);
void			ps_find_nxtend_rra(t_psnb *alst, int last, t_psdata *data);
void			ps_find_nxtend_a(t_psnb *alst, int *tab, t_psdata *data);
void			ps_find_rrb(t_psnb *alst, int *tab, t_psdata *data);
void			ps_find_nxtend_rrb(t_psnb *alst, int last, t_psdata *data);
void			ps_find_nxtend_b(t_psnb *alst, int *tab, t_psdata *data);
void			ps_find_med_end(t_psnb *alst, int *tab, t_psdata *data);
void			ps_sort_tab(int *tab, int size);
int				ps_is_sorted(t_psnb *alst, t_psnb *end);
int				ps_is_rev_sorted(t_psnb *alst, t_psnb *end);
int				ps_find_pa(t_psnb *alst, t_psnb *end);
int				ps_no_end(t_psnb *alst, t_psnb *end);
t_psnb			*ps_other_end(t_psnb *elem);
int				ps_under_med(t_psnb *elem, t_psdata *data);
int				ps_last_is_min(t_psnb *alst_nb);
int				ps_above_med(t_psnb *elem, t_psdata *data);
int				ps_eleven_n_more(t_psnb *alst_na);
int				ps_last_is_max(t_psnb *alst_na);

/*
** tri sur pile a
*/

void			ps_quick_sort_a(t_pslsts *lsts, t_psnb *end);
void			ps_split_a(t_pslsts *lsts, t_psdata *data, t_psend *ends);
void			ps_handle_three_a(t_pslsts *lsts);

/*
** tri sur pile b
*/

void			ps_quick_sort_b(t_pslsts *lsts, t_psnb *end);
void			ps_split_b(t_pslsts *lsts, t_psdata *data, t_psend *ends);
void			ps_handle_three_b(t_pslsts *lsts);

/*
** execution et enregistrement des instructions
*/

void			ps_exe_rec_sa(t_pslsts *lsts);
void			ps_exe_rec_sb(t_pslsts *lsts);
void			ps_exe_rec_pa(t_pslsts *lsts);
void			ps_exe_rec_pb(t_pslsts *lsts);
void			ps_exe_rec_ra(t_pslsts *lsts);
void			ps_exe_rec_rb(t_pslsts *lsts);
void			ps_exe_rec_rra(t_pslsts *lsts);
void			ps_exe_rec_rrb(t_pslsts *lsts);

/*
** simplication des instructions
*/

void			ps_simplify_insts(t_psinstlst **alst);
void			ps_simplify_insts1(t_psinstlst **alst);
void			ps_delete_insts(t_psinstlst **alst, t_psinstlst *tmp,
				t_psinstlst *tmp2);
void			ps_delete_ninsts(t_psinstlst *tmp, int nb);
void			ps_merge_insts(t_psinstlst *tmp, t_psinstlst *tmp2);

/*
** ecrire instructions
*/

void			ps_write_insts(t_psinstlst *alst_i);

/*
** visualiseur
*/

void			ps_visualize(t_psnb **alst_na, t_psinstlst **alst_i);
void			ps_visualize_next(t_pslsts *lsts, t_pssdl *stct);
int				ps_visualize_next2(t_pslsts *lsts, t_pssdl *stct);
void			ps_show_state(t_pslsts *lsts, t_pssdl *stct);
void			ps_show_state2(t_psnb *alst, t_pssdl *stct, t_rect *rect,
				int stack);
int				ps_give_entries(t_psnb *alst);
int				ps_give_hvalue(t_psnb *alst);
void			ps_fill_rect(t_rect *rect, t_psnb *alst);
int				ps_give_width(int nb, int hvalue);
int				ps_give_whght(int entries);
void			ps_initialize_tab(t_pstab *ptab);
void			ps_fill_background(t_pssdl *stct, SDL_Rect rect);
void			ps_choose_color(t_pssdl *stct, int nb, int stack);
int				ps_give_delay(t_psinstlst *alst_i);
void			ps_check_visualizer(t_pslsts *lsts, t_pssdl *stct);
void			ps_visualize_ok(t_pslsts *lsts, t_pssdl *stct);
void			ps_show_state_ok(t_psnb *alst, t_pssdl *stct, t_rect *rect);
void			ps_show_state_ok_neg(t_psnb *alst, t_pssdl *stct, t_rect *rect);
void			ps_visualize_ko(t_pslsts *lsts, t_pssdl *stct);
void			ps_show_state_ko(t_psnb *alst, t_pssdl *stct, t_rect *rect,
				int stack);
void			ps_sparkle(t_pslsts *lsts, t_pssdl *stct, t_rect *rect1);

#endif
