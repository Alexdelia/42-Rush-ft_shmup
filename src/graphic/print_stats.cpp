/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:02:12 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 14:39:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"
#include "env.hpp"

static void	stats(const size_t start)
{
	size_t	i;

	attrset(COLOR_PAIR(CP_SCORE));
	move(2, start + 1);
	i = -1;
	while (++i < SCORE_W - 1)
		addstr("_");
	mvaddstr(3, start, "╱");
	mvaddstr(3, start + SCORE_W, "╲");
	i = -1;
	while (++i < 2)
	{
		mvaddstr(4 + i, start, "▏");
		mvaddstr(4 + i, start + SCORE_W, " ▏");
	}
	move(4 + i, start);
	addstr("╲");
	i = -1;
	while (++i < SCORE_W - 1)
		addstr("_");
	addstr("╱");
}

void	graphic::print_stats(env &e)
{
	size_t	start = e.get_win_col() / 2 - SCORE_W / 2;

	stats(start);

	mvaddstr(4, start + 2, "score : ");
	mvaddstr(5, start + 2, "  HP  : ");

	const std::string	score = std::to_string(e.get_score());
	mvaddstr(4, e.get_win_col() / 2 - score.size() / 2 + 3, score.c_str());

	//const std::string	hp = std::to_string(e.get_player().get_hp())
}
