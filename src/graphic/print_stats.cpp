/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stats.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:02:12 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 16:21:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"
#include "env.hpp"
#include "entity/player.hpp"

static void clean(const size_t start)
{
	for (size_t i = 0; i < 6; i++)
		mvaddstr(3 + i, start, STATS_W_S);
}

static void	stats(const size_t start)
{
	size_t	i;

	attrset(COLOR_PAIR(CP_SCORE));
	move(2, start + 1);
	i = -1;
	while (++i < STATS_W - 1)
		addstr("_");
	mvaddstr(3, start, "╱");
	mvaddstr(3, start + STATS_W, "╲");
	i = -1;
	while (++i < 2)
	{
		mvaddstr(4 + i, start, "▏");
		mvaddstr(4 + i, start + STATS_W, " ▏");
	}
	move(4 + i, start);
	addstr("╲");
	i = -1;
	while (++i < STATS_W - 1)
		addstr("_");
	addstr("╱");
}

void	graphic::print_stats(env &e)
{
	size_t	start = e.get_win_col() / 2 - STATS_W / 2;
	size_t	i;
	int		hp = e.get_player()->get_hp();

	clean(start);
	stats(start);

	mvaddstr(4, start + 2, "score: ");
	mvaddstr(5, start + 2, "   HP: ");

	const std::string	score = std::to_string(e.get_score());
	mvaddstr(4, start + 5 + STATS_W / 2 - score.size() / 2, score.c_str());
	mvaddch(5, start + 10, '[');
	i = -1;
	while (++i < 10)
	{
		if ((int)i < (hp / 10))
			attrset(COLOR_PAIR(CP_HP));
		else
			attrset(A_NORMAL);
		addch(' ');
	}
	attrset(COLOR_PAIR(CP_SCORE));
	addstr("] ");
	const std::string	hp_s = std::to_string(hp);
	addstr(hp_s.c_str());
	addstr("/100");
}
