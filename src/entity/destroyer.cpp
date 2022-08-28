/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:13:23 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 22:20:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/destroyer.hpp"
#include "graphic.hpp"

destroyer::destroyer(const size_t col):
	entity(0, col, 3, 8, 400, "🜛", CP_RED, true, true, 60, 100)
{}

destroyer::~destroyer()
{}

void	destroyer::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->_row++;
	if (_action_counter == _action) {
		e.add_entity(new rocket(this->_row + 1, this->_col, 0));
		e.add_entity(new rocket(this->_row + 1, this->_col, 1));
		e.add_entity(new rocket(this->_row + 1, this->_col, -1));
		this->_action_counter = 0;
	} else
		this->_action_counter++;

}
