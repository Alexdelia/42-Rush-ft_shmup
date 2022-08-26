/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:50:06 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 22:18:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"

env::env(): key(0), _row(0), _col(0)
{}

env::~env()
{}

bool env::init(void)
{
	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	//keypad(stdscr, TRUE);
	//curs_set(0);	// set after menu
	
	if (!graphic::init_color())
		return (endwin(), false);

	if (!this->resize())
		return (endwin(), false);

	return (true);
}
