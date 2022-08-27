/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:55:46 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 16:51:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "score.hpp"

#include <climits>

score::score(env &e)
{
	choose_score(e);	// unsure about approach
}

score::~score()
{}

bool	score::choose_score(env &e)
{
	this->s.clear();
	this->sort.clear();

	clear();
	curs_set(0);

	graphic::print_frame_score(e, CP_SCORE);
	graphic::print_header_score(e);

	if (!this->read_score())
		graphic::pmw(e.get_win_row(), e.get_win_col(), "NO SCORE");
	else
	{
		this->sort_score();
		graphic::print_score(e, *this);
	}

	if (getch() == KEY_RESIZE)
	{
		if (!e.resize())
			return (false);
		if (!this->choose_score(e))	// recursive recreation of score, need to handle that line
			return (false);
	}

	curs_set(1);

	return (true);
}

static size_t	index_big(score &s, const size_t big)
{
	size_t	i;
	size_t	local_big;
	size_t	index_big;

	local_big = 0;
	index_big = 0;
	i = 0;
	while (i < MAX_READ_SCORE && s.s[i].score > 0)
	{
		if (s.s[i].score > local_big && s.s[i].score < big)
		{
			local_big = s.s[i].score;
			index_big = i;
		}
		i++;
	}
	if (local_big == 0)
		return (i);
	return (index_big);
}

void	score::sort_score()
{
	size_t	i;
	size_t	big;

	i = 0;
	big = ULONG_MAX;
	while (i < MAX_READ_SCORE && big > 0)
	{
		this->sort[i] = index_big(*this, big);
		big = this->s[this->sort[i]].score;
		i++;
	}
	this->sort[i] = i;
}
