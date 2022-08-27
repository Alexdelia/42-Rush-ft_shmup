/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:39:33 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:36:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"

static void	print_frame_score_end(const env &e, size_t i)
{
	mvaddstr(i, 4, "▏  ╱");
	mvaddstr(i + 1, 4, "╲ˍ╱S");
	move(i - 1, 8);
	i = 0;
	while (++i < (size_t)e.get_win_col() - 10)
		addstr("_");
	move(e.get_win_row() - 2, 8);
	i = 0;
	while (++i < (size_t)e.get_win_col() - 10)
		addstr("_");
	mvaddstr(e.get_win_row() - 4, e.get_win_col() - 2, "_");
	mvaddstr(e.get_win_row() - 3, e.get_win_col() - 2, "╱.");
	mvaddstr(e.get_win_row() - 2, e.get_win_col() - 3, "╱.");
}

void	graphic::print_frame_score(const env &e, const int color)
{
	size_t	i;

	attrset(A_BOLD | COLOR_PAIR(color));
	move(0, 2);
	i = 0;
	while (++i < (size_t)e.get_win_col() - 5)
		addstr("_");
	mvaddstr(1, 1, "╱ ╲");
	mvaddstr(2, 1, "▏  ▏");
	mvaddstr(3, 1, "╲ˍˍ▏");
	mvaddstr(1, e.get_win_col() - 4, "╲.");
	i = 1;
	while (++i < (size_t)e.get_win_row() - 3)
	{
		mvaddstr(i, 4, "▏");
		mvaddstr(i, e.get_win_col() - 3, "▏.");
	}
	print_frame_score_end(e, i);
	attrset(A_NORMAL);
}

static void print_username(const score &s, const size_t i)
{
	if (i == 0)
		mvaddstr(3, 5, "🏆");
	if (!s.s[s.sort[i]].username.size())
	{
		attrset(A_ITALIC);
		mvaddstr(3 + i, 7, "[anonymous]");
		attrset(A_BOLD);
	}
	else
		mvaddstr(3 + i, 7, s.s[s.sort[i]].username.c_str());
}

void	graphic::print_header_score(const env &e)
{
	attrset(A_BOLD | A_UNDERLINE);
	mvprintw(2, 7, "USERNAME");
	mvprintw(2, e.get_win_col() - 8, "SCORE");
	//mvprintw(2, (e.get_win_col() - strlen("SCORE")) / 2 + 3, "SCORE");
	//mvprintw(2, e.get_win_col() - 8, "TOP");
	attrset(A_NORMAL);
}

void	graphic::print_score(const env &e, const score &s)
{
	attrset(A_BOLD);
	for (size_t i = 0;
		i < (size_t)e.get_win_row() - 7
		&& i < score::max_read_score
		&& s.s[s.sort[i]].score > 0;
		i++)
	{
		print_username(s, i);
		mvprintw(3 + i, (5 - ft_stlen(s.s[s.sort[i]].score)) / 2 + e.get_win_col() - 9,
			"%ld", s.s[s.sort[i]].score);
		/*attron(A_REVERSE | COLOR_PAIR(get_color(s.s[s.sort[i]].top)));
		mvaddstr(3 + i, (e.get_win_col() - 10), "      ");
		mvprintw(3 + i, (5 - ft_stlen(s[sort[i]].top)) / 2 + (e.get_win_col() - 9),
			"%ld", s[sort[i]].top);
		attroff(A_REVERSE | COLOR_PAIR(get_color(s[sort[i]].top)));*/
	}
	attrset(A_NORMAL);
}
