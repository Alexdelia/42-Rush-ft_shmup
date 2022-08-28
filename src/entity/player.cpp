/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:00 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 11:07:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/player.hpp"
#include "entity/ally_rocket.hpp"
#include "graphic.hpp"

player::player(const int row, const int col): entity(row - 2, (int)col / 2, 0, 0, 0, "^", CP_PLAYER, true, false)
{}

player::~player()
{}

void	player::process(env &e)
{
	(void)e;
}

void	player::spawn_rocket(env &e)
{
	e.add_entity(new ally_rocket(this->_row - 1, this->_col));
}
