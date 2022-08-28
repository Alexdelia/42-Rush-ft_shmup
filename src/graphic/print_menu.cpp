/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:32:17 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 16:44:40 by adelille         ###   ########.fr       */
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

void	graphic::print_menu(const env &e)
{
	print_frame(e.get_win_row(), e.get_win_col(), CP_MENU);

	pmw(e.get_win_row(), e.get_win_col(), "FT_SHMUP");
}
