/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:50:06 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:22:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "graphic.hpp"
#include "entity/player.hpp"

env::env(): _win_row(0), _win_col(0), _tick(0), _score(0), _entities(), _player2(NULL), _boss(NULL)
{
	_begin = std::chrono::steady_clock::now();
	srand(time(NULL));
}

env::~env()
{
	this->_delete_entities();
	endwin();
}

bool env::init(void)
{
	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	set_escdelay(0);
	nodelay(stdscr, TRUE);
	//curs_set(0);	// set after menu
	
	if (!graphic::init_color())
		return (endwin(), false);

	if (!this->resize())
		return (endwin(), false);
	
	this->_player = new player(this->_win_row, this->_win_col);
	this->add_entity(this->_player);

	return (true);
}
