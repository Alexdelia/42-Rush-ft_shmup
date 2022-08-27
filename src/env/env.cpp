/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:50:06 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:23:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"

env::env(): _win_row(0), _win_col(0), _next_id(0), _entities()
{}

env::~env()
{
	endwin();
}

bool env::init(void)
{
	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	//curs_set(0);	// set after menu
	
	/*if (!graphic::init_color())
		return (endwin(), false);*/

	/*if (!this->resize())
		return (endwin(), false);*/

	return (true);
}
