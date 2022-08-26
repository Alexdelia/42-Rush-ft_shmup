/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:55:46 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 00:33:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.hpp"

#include <string.h>

score::score(const env &e)
{
	choose_score(e);	// unsure about approach
}

score::~score()
{}

static bool	write_score(const env &e, std::string username, std::ofstream ofs)
{
}

static std::string	get_username(const env &e)
{
	std::string	username;
	int			key;
	size_t		i;

	clear();
	graphic::print_frame(e, CP_MENU);
	echo();
	attrset(A_BOLD);
	pmw(e, "Enter your name: ");

	key = getch();
	i = 0;
	while (key != '\n')
	{
		if (i > 0 && key == KEY_BACKSPACE)
			i--;
		else if (ft_isprint(key))
		{
			username[i] = (char)key;
			i++;
		}
		else if (is_exit(key) || key == KEY_RESIZE)
			break ;
		key = getch();
	}
	attrset(A_NORMAL);
	username[i] = '\0';
}

bool	score::save_score(const env &e)
{
	std::ofstream	ofs;
	std::string		username;
	int				key;

	if (!e.get_score())
		return (false);

	clear();
	graphic::print_frame(e, CP_SCORE);
	curs_set(1);
	attrset(A_BOLD | COLOR_PAIR(CP_SCORE));
	mvprintw(e.get_row() / 2 - 3,
		(e.get_col() - strlen(MSG_CUR_SCORE) + 1 + ft_stlen(e.get_score()))) / 2,
		"%s %ld", MSG_CUR_SCORE, e.get_score());
	pmw(e, "do you want to save your score ?");
	attrset(A_BOLD);
	mvaddstr(e.get_row() / 2 + 1, (e.get_col() - 5) / 2, "[y/n]");
	move(e.get_row() / 2 + 2, e.get_col() / 2 - 1);
	attrset(A_NORMAL);

	key = getch();
	if (key != 'y' && key != 'Y' && key != '\n')
		return (true);

	username = get_username(e);
	ofs.open(SCORE_PATH, std::ios::in | std::ios::out | std::ios::app | std::fstream::out);
	if (!ofs)
		return (false);
	ofs << e.get_score() << ' ' << username << std::endl;
	ofs.close();

	return (true);
}

bool	score::choose_score(const env &e)
{
	this->s.clear();
	this->sort.clear();

	clear();
	curs_set(0);

	graphic::print_frame_score(e, CP_SCORE);
	graphic::print_header_score(e);

	if (!this->read_score())
		pmw(e, "NO SCORE");
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
