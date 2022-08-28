/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:32:17 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:11:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"

#include <cstring>

void	graphic::print_frame(const int row, const int col, const int color)
{
	size_t	i;

	attrset(COLOR_PAIR(color));
	addstr("╔");
	i = 0;
	while (++i < (size_t)col - 1)
		addstr("═");
	addstr("╗");
	i = 0;
	while (++i < (size_t)row - 1)
	{
		mvaddstr(i, 0, "║");
		mvaddstr(i, col - 1, "║");
	}
	move(i, 0);
	addstr("╚");
	i = 0;
	while (++i < (size_t)col - 1)
		addstr("═");
	addstr("╝");
	attrset(A_NORMAL);
}

static void	print_menu_key(const env &e)
{
	move((e.get_win_row() - 1) / 2 + 4, (e.get_win_col() - strlen("[p/q]")) / 2);
	attrset(A_NORMAL);
	addch('[');
	attrset(COLOR_PAIR(CP_PLAY) | A_BOLD);
	addch('p');
	attrset(A_NORMAL);
	addch('/');
	attrset(COLOR_PAIR(CP_HP) | A_BOLD);
	addch('m');
	attrset(A_NORMAL);
	addch('/');
	attrset(COLOR_PAIR(CP_EXIT) | A_BOLD);
	addch('q');
	attrset(A_NORMAL);
	addch(']');
}

void	graphic::print_menu(const env &e)
{
	print_frame(e.get_win_row(), e.get_win_col(), CP_MENU);
	attrset(A_BOLD | COLOR_PAIR(CP_PLAY));
	mvprintw((e.get_win_row() - 1) / 2,
		(e.get_win_col() - strlen(MSG_PLAY)) / 2, MSG_PLAY);
	attrset(A_BOLD | COLOR_PAIR(CP_HP));
	mvprintw((e.get_win_row() - 1) / 2,
		(e.get_win_col() - strlen(MSG_MULTI)) / 2, MSG_MULTI);
	attrset(A_BOLD | COLOR_PAIR(CP_EXIT));
	mvprintw((e.get_win_row() - 1) / 2 + 2,
		(e.get_win_col() - strlen(MSG_EXIT)) / 2, MSG_EXIT);
	print_menu_key(e);

	attrset(COLOR_PAIR(CP_PLAYER) | A_BOLD);
	pmw(e.get_win_row() - 8, e.get_win_col(), "FT_SHMUP");
}
