/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:50:06 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:47:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "graphic.hpp"

env::env(): _win_row(0), _win_col(0), _tick(0), _score(0), _entities()
{
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
	nodelay(stdscr, TRUE);
	//curs_set(0);	// set after menu
	
	if (!graphic::init_color())
		return (endwin(), false);

	if (!this->resize())
		return (endwin(), false);

	return (true);
}

size_t	env::get_tick() const {
	return this->_tick;
}
