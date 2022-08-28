/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:00 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 11:53:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/player.hpp"
#include "entity/ally_rocket.hpp"
#include "graphic.hpp"

player::player(const int row, const int col):
	entity(row - 2, (int)col / 2, 0, 0, 0, "^", CP_PLAYER, true, false),
	_shoot_timer(0)
{}

player::~player()
{}

void	player::process(env &e)
{
	(void)e;
	if (this->_shoot_timer > 0)
		this->_shoot_timer--;
}

void	player::shoot(env &e)
{
	if (this->_shoot_timer == 0)
	{
		this->_spawn_rocket(e);
		this->_shoot_timer = 6;
	}
}

void	player::_spawn_rocket(env &e)
{
	e.add_entity(new ally_rocket(this->_row - 1, this->_col));
}
